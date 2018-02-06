#ifndef DEF_ELS_HEAD
#define DEF_ELS_HEAD

#include <windows.h>
#include <time.h>

#endif
#define DEF_TIMER1 1234

//显示方块
void OnPaint(HDC hDC); 
void OnCreate();
//产生随机方块
int CreateRandomSqare();
//随机块贴进背景
void CopySqareToBack();

//显示方块
void PaintSqare(HDC hMemDC);

//回车键
void OnReturn(HWND hWnd);

//方块下落
void SqareDown();

