#include "elsHead.h"
char g_arrBackGroud[20][10]={0};
char g_arrSqare[2][4]={0};
void OnPaint(HDC hDC)
{
	//����������DC
	HDC hMemDC=CreateCompatibleDC(hDC);
	// ����һ��ֽ
	HBITMAP hBitmapBack=CreateCompatibleBitmap(hDC,500,600);
	//ֽ��DC��������
	SelectObject(hMemDC,hBitmapBack);
	
	PaintSqare(hMemDC);

	

	//�ڴ�DC���ݵ�����DC��
	BitBlt(hDC,0,0,300,600,hMemDC,0,0,SRCCOPY);
	

	//�ͷ�λͼ
	DeleteObject(hBitmapBack);
	// �ͷ�DC
	DeleteDC(hMemDC);
}

void OnCreate()
{
	srand((unsigned int)time(NULL));
	CreateRandomSqare();
	CopySqareToBack();
}

void PaintSqare(HDC hMemDC)
{
	int i=0,
		 j=0;
	//���󷽿�
	Rectangle(hMemDC,0,0,300,600);
	
	//��С����
	//g_arrBackGroud[1][4]=g_arrSqare[0][0];
	//g_arrBackGroud[1][5]=g_arrSqare[0][1];
	//g_arrBackGroud[1][6]=g_arrSqare[0][2];
	//g_arrBackGroud[1][7]=g_arrSqare[0][3];
	//
	//g_arrBackGroud[2][4]=g_arrSqare[1][0];
	//g_arrBackGroud[2][5]=g_arrSqare[1][1];
	//g_arrBackGroud[2][6]=g_arrSqare[1][2];
	//g_arrBackGroud[2][7]=g_arrSqare[1][3];
	for(i=0;i<20;i++)
	{
		for(j=0;j<10;j++)
		{
			if(1==g_arrBackGroud[i][j])
			{
				//������
				Rectangle(hMemDC,j*30,i*30,j*30+30,i*30+30);
			}
		}
	}
}

//���������
int CreateRandomSqare()
{
	int nIndex=rand()%7;
	switch(nIndex)
	{
	case 0:
		g_arrSqare[0][0]=1,g_arrSqare[0][1]=1,g_arrSqare[0][2]=0,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=0,g_arrSqare[1][1]=1,g_arrSqare[1][2]=1,g_arrSqare[1][3]=0;
		break;
	case 1:
		g_arrSqare[0][0]=0,g_arrSqare[0][1]=0,g_arrSqare[0][2]=1,g_arrSqare[0][3]=1;
		g_arrSqare[1][0]=0,g_arrSqare[1][1]=1,g_arrSqare[1][2]=1,g_arrSqare[1][3]=0;
		break;
	case 2:
		g_arrSqare[0][0]=0,g_arrSqare[0][1]=0,g_arrSqare[0][2]=1,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=1,g_arrSqare[1][1]=1,g_arrSqare[1][2]=1,g_arrSqare[1][3]=0;
		break;
	case 3:
		g_arrSqare[0][0]=1,g_arrSqare[0][1]=0,g_arrSqare[0][2]=0,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=1,g_arrSqare[1][1]=1,g_arrSqare[1][2]=1,g_arrSqare[1][3]=0;
		break;
	case 4:
		g_arrSqare[0][0]=0,g_arrSqare[0][1]=1,g_arrSqare[0][2]=0,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=1,g_arrSqare[1][1]=1,g_arrSqare[1][2]=1,g_arrSqare[1][3]=0;
		break;
	case 5:
		g_arrSqare[0][0]=1,g_arrSqare[0][1]=1,g_arrSqare[0][2]=0,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=1,g_arrSqare[1][1]=1,g_arrSqare[1][2]=0,g_arrSqare[1][3]=0;
		break;
	case 6:
		g_arrSqare[0][0]=1,g_arrSqare[0][1]=1,g_arrSqare[0][2]=1,g_arrSqare[0][3]=1;
		g_arrSqare[1][0]=0,g_arrSqare[1][1]=0,g_arrSqare[1][2]=0,g_arrSqare[1][3]=0;
		break;
	}
	return nIndex;
}

void CopySqareToBack()
{
	int i=0,
		 j=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			g_arrBackGroud[i][3+j]=g_arrSqare[i][j];
		}
	}
}

void OnReturn(HWND hWnd)
{
	//�򿪶�ʱ��
	SetTimer(hWnd,DEF_TIMER1,1000,NULL);
}

//��������
void SqareDown()
{
	int i=0,
		 j=0;

	for(i=19;i>=0;i--)
	{
		for(j=0;j<10;j++)
		{
			if(1==g_arrBackGroud[i][j])
			{
				g_arrBackGroud[i+1][j]=g_arrBackGroud[i][j];
				g_arrBackGroud[i][j]=0;
			}
		}
	}
}
