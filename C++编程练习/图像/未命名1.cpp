// ���뻷����Visual C++ 6.0��EasyX 2014������
// http://www.easyx.cn
//
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <easyx.h> 
int main()
{
	// ���������������
	srand((unsigned) time(NULL));

	// ��ʼ��ͼ��ģʽ
	initgraph(640, 480);

	int  x, y;
	char c;

	settextstyle(16, 8, _T("Courier"));	// ��������

	// ������ɫ
	settextcolor(GREEN);
	setlinecolor(BLACK);

	for (int i = 0; i <= 479; i++)
	{
		// �����λ����ʾ���������ĸ
		for (int j = 0; j < 3; j++)
		{
			x = (rand() % 80) * 8;
			y = (rand() % 20) * 24;
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);
		}

		// ���߲���һ��������
		line(0, i, 639, i);

		Sleep(10);					// ��ʱ
		if (i >= 479)	i = -1;		// ѭ������
		if (kbhit())	break;		// ��������˳�
	}

	// �ر�ͼ��ģʽ
	closegraph();
}

