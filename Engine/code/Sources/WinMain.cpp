/// @author Ángel
/// Código modificado por:
/// Felipe Vallejo Molina
/// 
/// felipevm07@gmail.com
/// 2024.01

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>

extern int main(int, char**);

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
    return main(__argc, __argv);
}

#endif
