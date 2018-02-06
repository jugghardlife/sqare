#include "resource.h"
#include "elsHead.h"

//WINAPI:调用约定
//句柄:一个数，窗口的唯一标识  HINSTANCE hInstance
//前一个句柄  没什么用了
//命令行参数
LRESULT CALLBACK PELouSi(HWND hWnd,UINT nMsg,WPARAM wParam,LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPTSTR lpCmdLine,int nCmdShow)
{	
	//初始化窗口类
	WNDCLASSEX wc;
	HWND hWnd;
	MSG mSg;

	wc.cbClsExtra=0;
	wc.cbSize=sizeof(WNDCLASSEX);
	wc.cbWndExtra=0;
	wc.hbrBackground=(HBRUSH)COLOR_WINDOW;//背景颜色
	wc.hCursor=LoadCursor(NULL,IDC_HELP);
	wc.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));
	wc.hIconSm=LoadIcon(NULL,IDI_HAND);
	wc.hInstance=hInstance;
	wc.lpfnWndProc=PELouSi;//回调函数地址
	wc.lpszClassName="els"; //名字不要重复，给操作系统看的
	wc.lpszMenuName=NULL;
	wc.style=CS_HREDRAW|CS_VREDRAW;
	//12个

	//注册窗口对象
	//ATOM    unsigned short
	if(0==RegisterClassEx(&wc))
	{	
		//出错的原因
		int a=GetLastError();//函数
		return 0;
	}

	//创建窗口
	hWnd=CreateWindowEx(WS_EX_TOPMOST,	"els","秦皇岛方块",WS_OVERLAPPEDWINDOW,100,30,500,600+45,NULL,NULL,hInstance,NULL);
	if(NULL==hWnd)     //窗口句柄当前窗口的唯一的标识
	{
		return 0;
	}

	//显示窗口
	ShowWindow(hWnd,SW_SHOWNORMAL);
	//隐藏显示返回0  正常显示返回非0
	
	//消息循环
	while(GetMessage(&mSg,NULL,0,0))    //第二个参数NULL和非NULL的区别
	{
		TranslateMessage(&mSg);  //翻译消息 
		
		DispatchMessage(&mSg);  //分发消息  标准消息  命令消息  通知消息  自定义消息
	}
	return 0;
}

//long                                                                             //UINT 消息的ID
LRESULT CALLBACK PELouSi(HWND hWnd,UINT nMsg,WPARAM wParam,LPARAM lParam)
{	
	PAINTSTRUCT pt;
	HDC hDC;
	switch(nMsg)
	{
	case WM_CREATE:  //窗口创建初期只产生一次
		OnCreate();
		break;
	
	case WM_TIMER:
		GetLastError();
		break;
	case WM_PAINT:
		hDC=BeginPaint(hWnd,&pt);  //getDC，窗口可操作的标识
		OnPaint(hDC);
		EndPaint(hWnd,&pt);
		break;
	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_RETURN:
			OnReturn(hWnd);
			break;
		case VK_LEFT:
			
			break;
		case VK_RIGHT:
			
			break;
		case VK_UP:
			
			break;
		case VK_DOWN:
			
			break;
		}
		break;
	case WM_DESTROY:
		KillTimer(hWnd,DEF_TIMER1);
		PostQuitMessage(0);//WM_CLOSE   WM_DESTROY  WM_QUIT
		break;
	}

	return DefWindowProc(hWnd,nMsg,wParam,lParam);    //功能
}
