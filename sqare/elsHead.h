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

//��������
void SqareDown();

