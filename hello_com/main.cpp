#ifdef _WINDLL
# define PLCOM_EXPORT
#endif

#ifndef PLCOM_EXPORT

#include"fadd_export.h"
#include<windows.h>
#include<iostream>
using namespace std;

typedef Ifsub2* (*fVfsub)();
typedef object* (*ffsub)();

void main(){
	HINSTANCE dlmem= LoadLibraryA("hello_com.dll");
	fVfsub pcreateVfsub=  (fVfsub)GetProcAddress(dlmem, "createVfsub");
	ffsub pcreatefsub=  (ffsub)GetProcAddress(dlmem, "createfsub");

	
	Ifsub2* pv= pcreateVfsub();
	object* po= pcreatefsub();

	cout<<(po->*pv->sub)(93,2)<<endl;

	system("pause");
}


#else

#include "fadd.h"


void main(){
	test();
	system("pause");
}
#endif