#include<iostream>

using namespace std;

template<typename T> //typenameҲ������class 
void myswap(T& a,T& b){
	T temp=a;
	a=b;
	b=temp;
}


void test01(){
	int a=10,b=20;
	cout<<"a = "<<a<<" b = "<<b<<endl;
	//1.�Զ������Ƶ� 
	myswap(a,b);
	cout<<"a = "<<a<<" b = "<<b<<endl;
	double c=1.2,d=2.2;
	cout<<"c = "<<c<<" d = "<<d<<endl;
	//2.��ʾָ������ 
	myswap<double>(c,d);
	cout<<"c = "<<c<<" d = "<<d<<endl;
}

int main(){
	test01();
	
	return 0;
}
