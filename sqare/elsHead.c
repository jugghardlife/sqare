#include "elsHead.h"
char g_arrBackGroud[20][10]={0};
char g_arrSqare[2][4]={0};
int g_nSqareC =-1;
int g_nSqareID=-1;
int g_nLine =-1;
int g_nList=-1;

void OnPaint(HDC hDC)
{
	//����������DC
	HDC hMemDC=CreateCompatibleDC(hDC);
	// ����һ��ֽ
	HBITMAP hBitmapBack=CreateCompatibleBitmap(hDC,500,600);
	//ֽ��DC��������
	SelectObject(hMemDC,hBitmapBack);
	
	PaintSqare(hMemDC);
	ShowSqare2(hMemDC);

	

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
	HBRUSH hOldBrush;
	HBRUSH hNewBrush;
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
	
	switch(g_nSqareC)
	{
	case 0:
			hNewBrush=CreateSolidBrush(RGB(32,145,173));
		break;
	case 1:
		hNewBrush=CreateSolidBrush(RGB(32,173,36));
		break;
	case 2:
		hNewBrush=CreateSolidBrush(RGB(247,15,15));
		break;
	case 3:
		hNewBrush=CreateSolidBrush(RGB(247,229,15));
		break;
	case 4:
		hNewBrush=CreateSolidBrush(RGB(28,128,167));
		break;
	case 5:
		hNewBrush=CreateSolidBrush(RGB(88,28,167));
		break;
	case 6:
		hNewBrush=CreateSolidBrush(RGB(111,206,4));
		break;
	}

	
	hOldBrush=SelectObject(hMemDC,hNewBrush);
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
	hNewBrush=SelectObject(hMemDC,hOldBrush);
	DeleteObject(hNewBrush);
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
		g_nLine=0;
		g_nList=3;
		break;
	case 1:
		g_arrSqare[0][0]=0,g_arrSqare[0][1]=1,g_arrSqare[0][2]=1,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=1,g_arrSqare[1][1]=1,g_arrSqare[1][2]=0,g_arrSqare[1][3]=0;
		g_nLine=0;
		g_nList=3;
		break;
	case 2:
		g_arrSqare[0][0]=0,g_arrSqare[0][1]=0,g_arrSqare[0][2]=1,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=1,g_arrSqare[1][1]=1,g_arrSqare[1][2]=1,g_arrSqare[1][3]=0;
		g_nLine=0;
		g_nList=3;
		break;
	case 3:
		g_arrSqare[0][0]=1,g_arrSqare[0][1]=0,g_arrSqare[0][2]=0,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=1,g_arrSqare[1][1]=1,g_arrSqare[1][2]=1,g_arrSqare[1][3]=0;
		g_nLine=0;
		g_nList=3;
		break;
	case 4:
		g_arrSqare[0][0]=0,g_arrSqare[0][1]=1,g_arrSqare[0][2]=0,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=1,g_arrSqare[1][1]=1,g_arrSqare[1][2]=1,g_arrSqare[1][3]=0;
		g_nLine=0;
		g_nList=3;
		break;
	case 5:
		g_arrSqare[0][0]=1,g_arrSqare[0][1]=1,g_arrSqare[0][2]=0,g_arrSqare[0][3]=0;
		g_arrSqare[1][0]=1,g_arrSqare[1][1]=1,g_arrSqare[1][2]=0,g_arrSqare[1][3]=0;
		g_nLine=0;
		g_nList=4;
		break;
	case 6:
		g_arrSqare[0][0]=1,g_arrSqare[0][1]=1,g_arrSqare[0][2]=1,g_arrSqare[0][3]=1;
		g_arrSqare[1][0]=0,g_arrSqare[1][1]=0,g_arrSqare[1][2]=0,g_arrSqare[1][3]=0;
		g_nLine=0;
		g_nList=3;
		break;
	}
	g_nSqareC=nIndex;
	g_nSqareID=nIndex;
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

void OnLeft(HWND hWnd)
{
	//����������
	if(1==CanSqareLeft()&&1==CanSqareLeft2())
	{
		HDC hDc=GetDC(hWnd);
		SqareLeft();
		g_nList--;
		OnPaint(hDc);
		ReleaseDC(hWnd,hDc);//�˹��ͷ�
	 }
}

void	 OnRight(HWND hWnd)
{
	if(1==CanSqareRight() && 1==CanSqareRight2())
	{
		//����������
		HDC hDc=GetDC(hWnd);
		SqareRight();
		g_nList++;
		OnPaint(hDc);
		ReleaseDC(hWnd,hDc);
	}
}

void OnchangeSqare(HWND hWnd)
{
	HDC hDc=GetDC(hWnd);
	switch(g_nSqareID)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		//��ͨ����
		if(1==CanSqareChangeShape())
		{
			ChangeSqare();
		}else
		{
			return ;
		}
		break;
	case 5:
		//������
		return;
	case 6:
		//������
		break;
	}
	OnPaint(hDc);
	ReleaseDC(hWnd,hDc);
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

void SqareLeft()
{
	int i=0,
		 j=0;
	for(i=0;i<20;i++)
	{
		for(j=0;j<10;j++)
		{
			if(1==g_arrBackGroud[i][j])
			{
				g_arrBackGroud[i][j-1]=g_arrBackGroud[i][j];
				g_arrBackGroud[i][j]=0;
			}	
		}
	}
}

void SqareRight()
{
	int i=0,
		 j=0;
	for(i=19;i>=0;i--)
	{
		for(j=10;j>=0;j--)
		{
			if(1==g_arrBackGroud[i][j])
			{
				g_arrBackGroud[i][j+1]=g_arrBackGroud[i][j];
				g_arrBackGroud[i][j]=0;
			}	
		}
	}
}

void OnTimer(HWND hWnd)
{
	HDC hDc=GetDC(hWnd);//�ں˶���
	if(1==CanSqareDown() && 1==CanSqareDown2())
	{
		//��������
		SqareDown();
		g_nLine++;
	}
	else
	{
		//1 ���2
		Chang1To2();
		// ���������
		CreateRandomSqare();
		//���Ƶ�������
		CopySqareToBack();
	}
	//��ʾ����
	OnPaint(hDc);
	//PaintSqare(hDc);

	ReleaseDC(hWnd,hDc);//�˹��ͷ�
}

int CanSqareDown()
{
	int i=0;
	for(i=0;i<10;i++)
	{
		if(1==g_arrBackGroud[19][i])
		{
			return 0;//return ��������  exit ��������
		}
	}
	return 1;
}

int CanSqareDown2()
{
	int i=0,
		 j=0;

	for(i=19;i>=0;i--)
	{
		for(j=0;j<10;j++)
		{
			if(1==g_arrBackGroud[i][j])
			{
				if(2==g_arrBackGroud[i+1][j])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int CanSqareLeft()
{
	int i=0;
	for(i=0;i<20;i++)
	{
		if(1==g_arrBackGroud[i][0])
		{
			return 0;
		}
	}
	return 1;
}

int CanSqareLeft2()
{
	int i=0,
		 j=0;
	for(i=0;i<20;i++)
	{
		for(j=0;j<10;j++)
		{
			if(1==g_arrBackGroud[i][j])
			{
				if(2==g_arrBackGroud[i][j-1])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int CanSqareRight()
{
	int i=0;
	for(i=0;i<20;i++)
	{
		if(1==g_arrBackGroud[i][9])
		{
			return 0;
		}
	}
	return 1;
}

int CanSqareRight2()
{
	int i=0,
		 j=0;
	for(i=0;i<20;i++)
	{
		for(j=0;j<10;j++)
		{
			if(1==g_arrBackGroud[i][j])
			{
				if(2==g_arrBackGroud[i][j+1])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//1 ���2
void Chang1To2()
{
	int i=0,
		 j=0;

	for(i=0;i<20;i++)
	{
		for(j=0;j<10;j++)
		{
			if(1==g_arrBackGroud[i][j])
			{
				g_arrBackGroud[i][j]=2;
			}
		}
	}
}

void ChangeSqare()
{
	int n=2;
	int i=0,
		 j=0;
	char arrSqare[3][3]={0};
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			arrSqare[i][j]=g_arrBackGroud[g_nLine+i][g_nList+j];
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			g_arrBackGroud[g_nLine+i][g_nList+j]=arrSqare[n-j][i];	
		}
	}
}

int CanSqareChangeShape()
{
	int i=0,
		 j=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(2==g_arrBackGroud[g_nLine+i][g_nList+j])
			{
				return 0;
			}
		}
	}
	return 1;
}

//��ʾ2
void ShowSqare2(HDC hMemDC)
{
	int i=0,
		 j=0;
	HBRUSH hOldBrush;
	HBRUSH hNewBrush=CreateSolidBrush(RGB(111,206,113));
	hOldBrush=SelectObject(hMemDC,hNewBrush);

	for(i=0;i<20;i++)
	{
		for(j=0;j<10;j++)
		{
			if(2==g_arrBackGroud[i][j])
			{
				//������
				Rectangle(hMemDC,j*30,i*30,j*30+30,i*30+30);
			}
		}
	}
	hNewBrush=SelectObject(hMemDC,hOldBrush);
	DeleteObject(hNewBrush);
}