;寄存器里放的到底是地址还是直接的数据这是个问题
;寄存器里放的到底是地址还是直接的数据这是个问题
;寄存器里放的到底是地址还是直接的数据这是个问题	


	DISP	MACRO    X			  ;这是一段带有参数的宏
				MOV	DL,X          ;要显示的字符送DL寄存器
				MOV	AH,02H        ;DOS功能调用号是02H
			    INT		21H   	  ;21H中断程序是DOS功能调用
			ENDM

		DATA	SEGMENT 		;DATA数据段
			DATA1	DB '12732'	;在DATA1单元处存放“12732“字符
			DATA2	DB '06815'	;在DATA2单元处存放“06815“字符
			N	EQU  $-DATA2	;EQU是对标号赋值的伪指令

		STACK	SEGMENT  STACK		;STACK数据段
			STA		DB 20 DUP (?)	;在单元STA处预留20个字节
			TOP	EQU  $-STA
		STACK	ENDS

		CODE	SEGMENT 		;CODE数据段

		ASSUME  CS:CODE,DS:DATA,SS:STACK,ES:DATA ;告诉汇编程序那段为数据段 ，那段为代码段，那段为堆栈段
		START:	MOV	AX,DATA 	;
				MOV	DS,AX		;
				MOV	AX,STACK	;
				MOV	SS,AX		;
				MOV	AX,TOP		;
				MOV	SP,AX		
				LEA	SI,DATA1		;☆取DATA1的偏移地址送到SI寄存器中
				MOV	BX,0
				MOV	CX,N
				CALL	DISPL				;显示被加数，调用DISPL函数
				DISP	'+'
			    LEA		SI,DATA2	;取DATA2的偏移地址送到SI寄存器中
				MOV	BX,0
				MOV	CX,N
				CALL	DISPL				;显示加数
				DISP	'='
				LEA		DI,DATA1 ;取DATA1的偏移地址送到SI寄存器中
				MOV	CX,N
		        CALL	ADDA				;调用加法子程序	
				LEA		SI,DATA1	;取DATA1的偏移地址送到SI寄存器中
				MOV	BX,0
				MOV	CX,N
				CALL	DISPL				;显示运算结果
				DISP	0DH
				DISP	0AH
				MOV	AX,4C00H
				INT		21H 	;中断 中断号为33

		DISPL	PROC						;显示子程序
			DS1:	MOV	AH,02H				;
					MOV	DL,[SI+BX]			;将BX和SI中的内容之和所指单元开始的1字节送入DL（低8位寄存器）
					INT		21H				;中断号为33
					INC		BX				;BX内容+1
					LOOP	DS1				;CX减1，如不为0.则循环，继续执行DS1这段汇编程序
					RET						;段内返回指令
		DISPL	ENDP						;显示子程序结束

		ADDA	PROC						;加法子程序开始
				PUSH	CX					;将CX的内容推入堆栈，栈顶指针减2
				MOV	 BX,0					;BX内容置0
				
		AD1:  	SUB 	BYTE  PTR [SI+BX],30H		;SI的地址加上BX的地址之和所指单元的数减去30H结果放在SI加上BX所指的单元当中去
		        SUB 	BYTE  PTR [DI+BX],30H		;同上
				INC		BX
				LOOP	AD1							;CX减1，如不为0.则循环，继续执行AD1这段汇编程序
				POP		CX                          ;
				PUSH	CX
				MOV	BX,N-1				;☆☆
				CLC						;CLC指令可使进位标志CF清0
				
		AD2:	MOV	AL,[SI+BX]
				ADC	AL,[DI+BX]
				AAA
				MOV	[DI+BX],AL
				DEC		BX				;将BX的内容减1
				LOOP	AD2				;当CX的值不为0时持续不断地将cx的值减1并执行AD2程序段
				POP		CX
				PUSH	CX
				MOV		BX,0					;☆☆☆
		AD3:  ADD 	BYTE  PTR [DI+BX],30H
				INC		BX
				LOOP	AD3
				POP		CX
				RET								;☆☆☆段内返回指令
		ADDA	ENDP						;加法子程序结束
		CODE	ENDS
				END	START
