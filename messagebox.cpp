#include <windows.h>

int main(void) {
    MessageboxW(
        NULL,
        L"MY FIRST MESSAGEBOX!",
        L"YUUPPP",
        MB_ICONEXCLAMATION | MB_OKCANCEL
    );

    return EXIT_SUCCESS;
}