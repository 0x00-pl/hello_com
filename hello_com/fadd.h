
#include"fadd_export.h"
#include<iostream>
using namespace std;

//.cpp
class fsub: public object{
public:
	void del_me(){delete this;}
	int sub(int a,int b){return a-b;}
	float sub(float a, float b){return a-b+1;}
};


Ifsub2* initVfsub(){
	static Ifsub2* ret=0;
	if(ret) return ret;
	ret= new Ifsub2;
	static_cast_set(ret->sub, static_cast<int(fsub::*)(int,int)>(&fsub::sub));
	static_cast_set(ret->subf, static_cast<float(fsub::*)(float,float)>(&fsub::sub));
	static_cast_set(ret->del_me, &fsub::del_me);
	return ret;
}

Ifsub2* createVfsub(){return initVfsub();}
object* createfsub(){return new fsub;}

//other cpp
void test(){
	Ifsub2* pv= createVfsub();
	object* po= createfsub();

	cout<<(po->*pv->sub)(3,2)<<endl;
}