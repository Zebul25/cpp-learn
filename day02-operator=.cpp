#include<iostream>
#include<string>
using namespace std;

class Person{
public:
	Person(int age){
		m_Age=new int(age);
	}
	
	Person& operator = (const Person &p){
		this->m_Age=new int(*p.m_Age);
		return  *this;
	}
	
	bool operator == (const Person& p){
		return *this->m_Age==*p.m_Age;
	}
	
	~Person(){
		if(m_Age!=NULL){
			delete m_Age;
			m_Age=NULL;
		}
		cout<<"调用析构函数!"<<endl;
	}

	int* m_Age;
};

ostream& operator << (ostream& os,Person &p){
		os<<*(p.m_Age);
		return os;


}

class MyPrint{
public:
	void operator () (string str){
		cout<<str<<endl; 
	}
};

class MyAdd{
public:
	int operator() (int a,int b){
		return a+b;
	}
};


void test01(){
	Person p1(10);
	Person p2=p1;
	Person p3(30);
	cout<<p1<<endl;
	cout<<p2<<endl;
	p1=p2=p3;
	cout<<p1<<endl; 
	p2=10; 
	if(p1==p2){
		cout<<"p1和p2是相等的"<<endl;
	}else{
		cout<<"p1和p2是不相等的"<<endl;
	}
}

void test02(){
	MyPrint mp;
	mp("hello 仿函数！");
	MyAdd ma;
	cout<<ma(10,10)<<endl;
	cout<<MyAdd()(20,20)<<endl;
}

class Sample{
public:
	Sample(){
		cout<<"调用构造函数"<<endl;
	}
	~Sample(){
		cout<<"调用析构函数"<<endl;
	}
};

int main(){
	
//	test01();
	//test02();
	//int x=17;
	//cout<<oct<<x;
	Sample a[2],*p[3];
	return 0;
}
