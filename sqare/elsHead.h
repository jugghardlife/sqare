#ifndef DEF_ELS_HEAD
#define DEF_ELS_HEAD

#include <windows.h>
#include <time.h>

#endif
#define DEF_TIMER1 1234

//��ʾ����
void OnPaint(HDC hDC); 
void OnCreate();
//�����������
int CreateRandomSqare();
//�������������
void CopySqareToBack();

//��ʾ����
void PaintSqare(HDC hMemDC);

//�س���
void OnReturn(HWND hWnd);
//����
void OnLeft(HWND hWnd);
//����
void	 OnRight(HWND hWnd);
//�������
void OnchangeSqare(HWND hWnd);

//��������
void SqareDown();
//��������
void SqareLeft();
//��������
void SqareRight();


//��ʱ����Ӧ����
void OnTimer(HWND hWn);

//����ͣ�������   0����������   1��������
int CanSqareDown();
int CanSqareDown2();
int CanSqareLeft();
int CanSqareLeft2();
int CanSqareRight();
int CanSqareRight2();
int CanSqareChangeShape();

//1 ���2
void Chang1To2();
void ChangeSqare();

//��ʾ2
void ShowSqare2(HDC hMemDC);
