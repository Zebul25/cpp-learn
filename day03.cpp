#include<iostream>
using namespace std;

class Base{
public:
	Base(){
		m_A=100;
		cout<<"调用Base构造函数"<<endl; 
	} 
	~Base(){
		cout<<"调用Base析构函数"<<endl;
	}
	
	void func(){
		cout<<"Base func 函数调用"<<endl;
	} 
	
public:
	int m_A;
	static int m_D;
protected:
	int m_B;
private:
	int m_C;
};

int Base::m_D=10;

class Son1 : public Base{
public:
	Son1(){
		m_A=200;
		cout<<"调用Son1构造函数"<<endl;
	}
	~Son1(){
		cout<<"调用Son1析构函数"<<endl;
	}

public:
	void func(){
//		m_A=100;
//		m_B=100;
		//m_C=100;  私有权限 子类无法访问 
		cout<<"Son1 func 函数调用"<<endl;
	}
	
	int m_A;		
};

void test01(){
	Son1 s1;//构造先父类后子类，析构先子类后父类 
//	s1.m_A=10;
	//s1.m_B=10;  保护类型 类外访问不到 
	//s1.m_C=10	  私有类型 类外访问不到 
	
	cout<<"m_A = "<<s1.m_A<<endl;
	cout<<"m_A = "<<s1.Base::m_A<<endl;
	s1.func();
	s1.Base::func();
	//同名静态成员函数和对象 操作相同 
}

class Son2 : protected Base{
public:
	void func(){
		m_A=100;
		m_B=10;
		//m_C=10;
	}
};

void test02(){
	Son2 s1; 
//	s1.m_A=10; 保护继承 原先的public -> protected 
//	s1.m_B=10;
//	s1.m_C=10;
}

class Son3 : private Base{
public:
	void func(){
		m_A=10;
		m_B=10;
		//m_C=10;
	}
};

class Grandson3 : public Son3{
public:
	void func(){
//		m_A=1;   父类private访问不到 
	}
};

void test03(){
	Son3 s3;
//	s3.m_A=10; 私有继承 public -> private 
//	s3.m_B=10;	        protected -> private  
//	s3.m_C=10;
}
class Base2{
	
}; 
//多继承语法  不建议使用 
class Son4 : public Base,public Base2{
	
};

//菱形继承 
class Animal{
public:
	int m_Age;
}; 

class Sheep : virtual public Animal{

}; 
class Tuo : virtual public Animal{

};
class SheepTuo : public Sheep,public Tuo{
	
};

void test04(){
	SheepTuo st;
	st.m_Age=10;
	Animal a;
	Sheep s;
	Tuo t;
	cout<<"Animal size of = "<<sizeof(a)<<endl; 
	cout<<"Sheep size of = "<<sizeof(s)<<endl; 
	cout<<"Tuo size of = "<<sizeof(t)<<endl; 
	cout<<"SheepTuo size of = "<<sizeof(st)<<endl; 
}

int main(){
	test04();
	
	
}
