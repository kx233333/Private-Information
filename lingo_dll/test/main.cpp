#include <iostream>
#include <windows.h>

int main() {
	HINSTANCE hDllInst;
	hDllInst = LoadLibrary(L"C:\Users\kx\Desktop\code\lingo\lingo_dll\lingo_dll\x64\Debug\MYUSER.dll"); //����DLL
	typedef int(*PLUSFUNC)(int* NumArgs, double* x, double* dResult); //���Ϊ������ǰ��Ϊ����ֵ
	PLUSFUNC plus_str = (PLUSFUNC)GetProcAddress(hDllInst, "MYUSER"); //GetProcAddressΪ��ȡ�ú����ĵ�ַ
	std::cout << plus_str(1, 2, 3, 4);
}
