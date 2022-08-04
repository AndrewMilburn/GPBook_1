#include<Skeleton.h>

LRESULT CALLBACK WndProc( HWND hWindow, UINT msg, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
					PSTR szCmdLine, int iCmdShow )
{
	static TCHAR szAppName[] = TEXT( "Skeleton" );
	WNDCLASSEX	wndclass;
	HWND		hWindow;
	MSG			msg;

	//Create the Window Class for the main Window
	wndclass.cbSize =			sizeof( wndclass );
	wndclass.style =			CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc =		WndProc;
	wndclass.cbClsExtra =		0;
	wndclass.cbWndExtra =		0;
	wndclass.hInstance =		hInstance;
	wndclass.hIcon =			LoadIcon( hInstance, MAKEINTRESOURCE( IDI_SKELETON ) );
	wndclass.hIconSm =			LoadIcon( hInstance, MAKEINTRESOURCE( IDI_SKELETON_SM ) );
	wndclass.hCursor =			LoadCursor( NULL, IDC_ARROW );
	wndclass.hbrBackground =	(HBRUSH)(COLOR_WINDOW + 1);
	wndclass.lpszMenuName =		NULL;
	wndclass.lpszClassName =	szAppName;

	if(!RegisterClassEx( &wndclass ))
	{
		return 0;
	}
	
	hWindow = CreateWindow( szAppName, szAppName, WS_OVERLAPPEDWINDOW,
							CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							NULL, NULL, hInstance, NULL );
	ShowWindow( hWindow, iCmdShow );
	UpdateWindow( hWindow );

	while(GetMessage( &msg, NULL, 0, 0 ))
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc( HWND hWindow, UINT msg, WPARAM wParam, LPARAM lParam )
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;

	switch(msg)
	{
		case WM_PAINT:
		{
			hDC = BeginPaint( hWindow, &ps );
			GetClientRect( hWindow, &rect );
			DrawText( hDC, TEXT( "This is a skeleton application" ), -1, &rect,
					 DT_SINGLELINE | DT_CENTER | DT_VCENTER );
			EndPaint( hWindow, &ps );
			return 0;
		}
		case WM_DESTROY:
		{
			PostQuitMessage( 0 );
			return 0;
		}
	}
	return DefWindowProc( hWindow, msg, wParam, lParam );
}