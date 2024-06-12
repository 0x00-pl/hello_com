#include"com_base.h"

struct Ifsub{
	int (object::*sub)(int,int);
	void (object::*del_me)();
};

struct Ifsub2:public Ifsub{
	float (object::*subf)(float,float);
};

DLLAPI Ifsub2* createVfsub();
DLLAPI object* createfsub();
