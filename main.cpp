#include <iostream>
#include <windows.h>
int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
