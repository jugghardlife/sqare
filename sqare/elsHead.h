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
//左移
void OnLeft(HWND hWnd);
//右移
void	 OnRight(HWND hWnd);
//方块变形
void OnchangeSqare(HWND hWnd);

//方块下落
void SqareDown();
//方块左移
void SqareLeft();
//方块右移
void SqareRight();


//定时器响应函数
void OnTimer(HWND hWn);

//方块停在最底下   0不可以下落   1可以下落
int CanSqareDown();
int CanSqareDown2();
int CanSqareLeft();
int CanSqareLeft2();
int CanSqareRight();
int CanSqareRight2();
int CanSqareChangeShape();

//1 变成2
void Chang1To2();
void ChangeSqare();

//显示2
void ShowSqare2(HDC hMemDC);
