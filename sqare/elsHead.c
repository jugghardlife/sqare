#include "elsHead.h"
char g_arrBackGroud[20][10]={0};
char g_arrSqare[2][4]={0};
void OnPaint(HDC hDC)
{
	//创建兼容性DC
	HDC hMemDC=CreateCompatibleDC(hDC);
	// 创建一张纸
	HBITMAP hBitmapBack=CreateCompatibleBitmap(hDC,500,600);
	//纸和DC关联起来
	SelectObject(hMemDC,hBitmapBack);
	
	PaintSqare(hMemDC);

	

	//内存DC传递到窗口DC上
	BitBlt(hDC,0,0,300,600,hMemDC,0,0,SRCCOPY);
	

	//释放位图
	DeleteObject(hBitmapBack);
	// 释放DC
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
	//画大方块
	Rectangle(hMemDC,0,0,300,600);
	
	//画小方块
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
				//画方块
				Rectangle(hMemDC,j*30,i*30,j*30+30,i*30+30);
			}
		}
	}
}

//创建随机块
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
	//打开定时器
	SetTimer(hWnd,DEF_TIMER1,1000,NULL);
}

//方块下落
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
