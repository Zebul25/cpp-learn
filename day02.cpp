#include<iostream>
#include<string>
using namespace std;

class Person{
public:
	static int m_A;
	int m_C;
	mutable int m_D;
	
	//常函数 
	void showPerson() const {
//		this->m_C=10;
		this->m_D=10;
	}
private:
	static int m_B;
};

int Person::m_A=100;
int Person::m_B=200;

class Building{
public:
	friend class GoodGay;
	Building();
	friend void goodGay(Building &b);
public:
	string m_SittingRoom;
	
private:
	string m_BedRoom;
}; 

class GoodGay{
public:
	GoodGay();
	void visit();
	
private:
	Building *b;
};

GoodGay::GoodGay(){
	this->b=new Building; 
}

void GoodGay::visit(){
	cout<<"正在访问好基友的："<<this->b->m_SittingRoom<<endl; 
	cout<<"正在访问好基友的："<<this->b->m_BedRoom<<endl; 
}

Building::Building(){
	this->m_SittingRoom="客厅";
	this->m_BedRoom="卧室"; 
}

void goodGay(Building &b){
	cout<<"正在访问： "<<b.m_SittingRoom<<endl;
	cout<<"正字访问： "<<b.m_BedRoom<<endl; 
}

void test1(){
	Person p1;
	Person p2;
	//p1.m_A=10;
	cout<<p1.m_A<<endl;
	//cout<<p2.m_B<<endl;
}

void test2(){
	Building b;
	goodGay(b);
	GoodGay gg;
	gg.visit();
}

int main(){
	
	//test1();
	test2();
	
	
	return 0;
}
