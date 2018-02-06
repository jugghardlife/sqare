#include "resource.h"
#include "elsHead.h"

//WINAPI:����Լ��
//���:һ���������ڵ�Ψһ��ʶ  HINSTANCE hInstance
//ǰһ�����  ûʲô����
//�����в���
LRESULT CALLBACK PELouSi(HWND hWnd,UINT nMsg,WPARAM wParam,LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPTSTR lpCmdLine,int nCmdShow)
{	
	//��ʼ��������
	WNDCLASSEX wc;
	HWND hWnd;
	MSG mSg;

	wc.cbClsExtra=0;
	wc.cbSize=sizeof(WNDCLASSEX);
	wc.cbWndExtra=0;
	wc.hbrBackground=(HBRUSH)COLOR_WINDOW;//������ɫ
	wc.hCursor=LoadCursor(NULL,IDC_HELP);
	wc.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));
	wc.hIconSm=LoadIcon(NULL,IDI_HAND);
	wc.hInstance=hInstance;
	wc.lpfnWndProc=PELouSi;//�ص�������ַ
	wc.lpszClassName="els"; //���ֲ�Ҫ�ظ���������ϵͳ����
	wc.lpszMenuName=NULL;
	wc.style=CS_HREDRAW|CS_VREDRAW;
	//12��

	//ע�ᴰ�ڶ���
	//ATOM    unsigned short
	if(0==RegisterClassEx(&wc))
	{	
		//�����ԭ��
		int a=GetLastError();//����
		return 0;
	}

	//��������
	hWnd=CreateWindowEx(WS_EX_TOPMOST,	"els","�ػʵ�����",WS_OVERLAPPEDWINDOW,100,30,500,600+45,NULL,NULL,hInstance,NULL);
	if(NULL==hWnd)     //���ھ����ǰ���ڵ�Ψһ�ı�ʶ
	{
		return 0;
	}

	//��ʾ����
	ShowWindow(hWnd,SW_SHOWNORMAL);
	//������ʾ����0  ������ʾ���ط�0
	
	//��Ϣѭ��
	while(GetMessage(&mSg,NULL,0,0))    //�ڶ�������NULL�ͷ�NULL������
	{
		TranslateMessage(&mSg);  //������Ϣ 
		
		DispatchMessage(&mSg);  //�ַ���Ϣ  ��׼��Ϣ  ������Ϣ  ֪ͨ��Ϣ  �Զ�����Ϣ
	}
	return 0;
}

//long                                                                             //UINT ��Ϣ��ID
LRESULT CALLBACK PELouSi(HWND hWnd,UINT nMsg,WPARAM wParam,LPARAM lParam)
{	
	PAINTSTRUCT pt;
	HDC hDC;
	switch(nMsg)
	{
	case WM_CREATE:  //���ڴ�������ֻ����һ��
		OnCreate();
		break;
	
	case WM_TIMER:
		GetLastError();
		break;
	case WM_PAINT:
		hDC=BeginPaint(hWnd,&pt);  //getDC�����ڿɲ����ı�ʶ
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

	return DefWindowProc(hWnd,nMsg,wParam,lParam);    //����
}
