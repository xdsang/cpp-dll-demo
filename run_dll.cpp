#include <windows.h>
#include <iostream>

typedef int (*add)(int, int);

int main() {
    HINSTANCE handle = LoadLibrary(TEXT(MY_DLL));
	if (handle == 0) {
		printf("load dll error\r\n");
	}
	else {
		printf("load dll success\r\n");
	}
    auto f = (add) GetProcAddress(handle, "add");
    std::cout << f(1, 32) << std::endl;
    FreeLibrary(handle);
    return 0;
}
