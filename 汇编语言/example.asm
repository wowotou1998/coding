;�Ĵ�����ŵĵ����ǵ�ַ����ֱ�ӵ��������Ǹ�����
;�Ĵ�����ŵĵ����ǵ�ַ����ֱ�ӵ��������Ǹ�����
;�Ĵ�����ŵĵ����ǵ�ַ����ֱ�ӵ��������Ǹ�����	


	DISP	MACRO    X			  ;����һ�δ��в����ĺ�
				MOV	DL,X          ;Ҫ��ʾ���ַ���DL�Ĵ���
				MOV	AH,02H        ;DOS���ܵ��ú���02H
			    INT		21H   	  ;21H�жϳ�����DOS���ܵ���
			ENDM

		DATA	SEGMENT 		;DATA���ݶ�
			DATA1	DB '12732'	;��DATA1��Ԫ����š�12732���ַ�
			DATA2	DB '06815'	;��DATA2��Ԫ����š�06815���ַ�
			N	EQU  $-DATA2	;EQU�ǶԱ�Ÿ�ֵ��αָ��

		STACK	SEGMENT  STACK		;STACK���ݶ�
			STA		DB 20 DUP (?)	;�ڵ�ԪSTA��Ԥ��20���ֽ�
			TOP	EQU  $-STA
		STACK	ENDS

		CODE	SEGMENT 		;CODE���ݶ�

		ASSUME  CS:CODE,DS:DATA,SS:STACK,ES:DATA ;���߻������Ƕ�Ϊ���ݶ� ���Ƕ�Ϊ����Σ��Ƕ�Ϊ��ջ��
		START:	MOV	AX,DATA 	;
				MOV	DS,AX		;
				MOV	AX,STACK	;
				MOV	SS,AX		;
				MOV	AX,TOP		;
				MOV	SP,AX		
				LEA	SI,DATA1		;��ȡDATA1��ƫ�Ƶ�ַ�͵�SI�Ĵ�����
				MOV	BX,0
				MOV	CX,N
				CALL	DISPL				;��ʾ������������DISPL����
				DISP	'+'
			    LEA		SI,DATA2	;ȡDATA2��ƫ�Ƶ�ַ�͵�SI�Ĵ�����
				MOV	BX,0
				MOV	CX,N
				CALL	DISPL				;��ʾ����
				DISP	'='
				LEA		DI,DATA1 ;ȡDATA1��ƫ�Ƶ�ַ�͵�SI�Ĵ�����
				MOV	CX,N
		        CALL	ADDA				;���üӷ��ӳ���	
				LEA		SI,DATA1	;ȡDATA1��ƫ�Ƶ�ַ�͵�SI�Ĵ�����
				MOV	BX,0
				MOV	CX,N
				CALL	DISPL				;��ʾ������
				DISP	0DH
				DISP	0AH
				MOV	AX,4C00H
				INT		21H 	;�ж� �жϺ�Ϊ33

		DISPL	PROC						;��ʾ�ӳ���
			DS1:	MOV	AH,02H				;
					MOV	DL,[SI+BX]			;��BX��SI�е�����֮����ָ��Ԫ��ʼ��1�ֽ�����DL����8λ�Ĵ�����
					INT		21H				;�жϺ�Ϊ33
					INC		BX				;BX����+1
					LOOP	DS1				;CX��1���粻Ϊ0.��ѭ��������ִ��DS1��λ�����
					RET						;���ڷ���ָ��
		DISPL	ENDP						;��ʾ�ӳ������

		ADDA	PROC						;�ӷ��ӳ���ʼ
				PUSH	CX					;��CX�����������ջ��ջ��ָ���2
				MOV	 BX,0					;BX������0
				
		AD1:  	SUB 	BYTE  PTR [SI+BX],30H		;SI�ĵ�ַ����BX�ĵ�ַ֮����ָ��Ԫ������ȥ30H�������SI����BX��ָ�ĵ�Ԫ����ȥ
		        SUB 	BYTE  PTR [DI+BX],30H		;ͬ��
				INC		BX
				LOOP	AD1							;CX��1���粻Ϊ0.��ѭ��������ִ��AD1��λ�����
				POP		CX                          ;
				PUSH	CX
				MOV	BX,N-1				;���
				CLC						;CLCָ���ʹ��λ��־CF��0
				
		AD2:	MOV	AL,[SI+BX]
				ADC	AL,[DI+BX]
				AAA
				MOV	[DI+BX],AL
				DEC		BX				;��BX�����ݼ�1
				LOOP	AD2				;��CX��ֵ��Ϊ0ʱ�������ϵؽ�cx��ֵ��1��ִ��AD2�����
				POP		CX
				PUSH	CX
				MOV		BX,0					;����
		AD3:  ADD 	BYTE  PTR [DI+BX],30H
				INC		BX
				LOOP	AD3
				POP		CX
				RET								;������ڷ���ָ��
		ADDA	ENDP						;�ӷ��ӳ������
		CODE	ENDS
				END	START
