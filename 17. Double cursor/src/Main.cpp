#include <Windows.h>

int main()
{
    // Create the second cursor using the CreateCursor function
    HCURSOR cursor2 = CreateCursor(NULL, 0, 0, 32, 32, (LPCVOID)cursorData, (LPCVOID)maskData);

    // Set the second cursor using the SetCursor function
    SetCursor(cursor2);

    // Show the second cursor using the ShowCursor function
    ShowCursor(TRUE);

    // Do other work here

    // Clean up
    DestroyCursor(cursor2);

    return 0;
}
