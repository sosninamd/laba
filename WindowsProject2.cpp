#include <windows.h>
#include <vector>
#include <Windows.h>
using namespace std;



// Определения оконных процедур.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Глобальное хранилище фигур.
vector<RECT> rectList;
vector<POINT> circleList;

// Точка входа в программу.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Регистрация класса окна.
    WNDCLASSW wc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = L"MyClass";
    if (!RegisterClassW(&wc)) {
        return 0;
    }

    // Создание окна.
    HWND hWnd = CreateWindow(TEXT("MyClass"), TEXT("My Window"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    return 0;

    // Отображение окна.
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Цикл обработки сообщений.
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}

// Оконная процедура.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;

    switch (message) {
    case WM_CREATE: {
        // Создание фигур и добавление их в хранилище.
        RECT rect = { 50, 50, 150, 100 };
        rectList.push_back(rect);

        POINT center = { 250, 75 };
        circleList.push_back(center);
        break;
    }
    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);

        // Рисование всех фигур из хранилища.
        for (const auto& rect : rectList) {
            Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
        }
        for (const auto& center : circleList) {
            Ellipse(hdc, center.x - 25, center.y - 25, center.x + 25, center.y + 25);
        }

        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
