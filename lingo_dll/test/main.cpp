#include <iostream>
#include <windows.h>

int main() {
	HINSTANCE hDllInst;
	hDllInst = LoadLibrary(L"C:\Users\kx\Desktop\code\lingo\lingo_dll\lingo_dll\x64\Debug\MYUSER.dll"); //调用DLL
	typedef int(*PLUSFUNC)(int* NumArgs, double* x, double* dResult); //后边为参数，前面为返回值
	PLUSFUNC plus_str = (PLUSFUNC)GetProcAddress(hDllInst, "MYUSER"); //GetProcAddress为获取该函数的地址
	std::cout << plus_str(1, 2, 3, 4);
}
