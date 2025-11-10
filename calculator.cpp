#include <windows.h>

#define ID_MENU_PANEL 101

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hSidebar;

    switch (uMsg) {
        case WM_CREATE: {
            // Create a static sidebar panel
            hSidebar = CreateWindowEx(
                0, "STATIC", "History",
                WS_CHILD | WS_VISIBLE | SS_CENTER,
                0, 0, 200, 500,  // x, y, width, height
                hwnd, (HMENU)ID_MENU_PANEL, NULL, NULL
            );

            // Add a sample button inside the sidebar
            CreateWindow(
                "BUTTON", "Calculator",
                WS_CHILD | WS_VISIBLE,
                20, 50, 160, 30,
                hSidebar, NULL, NULL, NULL
            );

            return 0;
        }

        case WM_SIZE: {
            // Resize sidebar height with main window
            RECT rc;
            GetClientRect(hwnd, &rc);
            MoveWindow(hSidebar, 0, 0, 200, rc.bottom, TRUE);
            return 0;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const char CLASS_NAME[] = "MainWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Black Boom App",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
