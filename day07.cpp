#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;

class Person{
public:
	Person(string name,int age): m_Name(name),m_Age(age)
	{
		
	}
	
	string m_Name;
	int m_Age;
};

template<class T>
void myCompare(T &a, T &b){
	if(a==b){
		cout<<"a == b"<<endl;
	} else{
		cout<<"a != b"<<endl; 
	}
}

template<> void myCompare(Person &p1,Person &p2){
	if(p1.m_Name==p2.m_Name&&p1.m_Age==p2.m_Age){
		cout<<"p1 == p2"<<endl;
	}else{
		cout<<"p1 != p2"<<endl;
	}
}

//类模板
//类模板可有默认参数 
template<typename NameType,typename AgeType = int>
class People{
public:	
	People(NameType name,AgeType age) : m_Name(name),m_Age(age){
		
	}
	
	void showPeople(){
		cout<<this->m_Name<<"\t"<<this->m_Age<<endl;
	}
	
	NameType m_Name;
	AgeType m_Age;
}; 

void test01(){
	int a=10,b=20;
	Person p1("Tom",21),p2("Jerry",21);
	myCompare(p1,p2);
}

void test02(){
	People<string,int> p("Zebul",24);
	p.showPeople();
	People<string> p1("Daxibu",24);
	p1.showPeople();
}

// 类模板与继承
template<class T>
class Base{
public:
	T obj;
}; 

template<class T1,class T2>
class Son : public Base<T2>{//必须知道父类中T的类型，才能继承给子类 
public:
	Son(){
		cout<<"T1的数据类型为："<<typeid(T1).name()<<endl;
		cout<<"T2的数据类型为："<<typeid(T2).name()<<endl;
	}
	
	void show();
	
	T1 m;
	
};

template<class T1,class T2>
void Son<T1,T2>::show(){
	cout<<"show"<<endl;
}

void test03(){
	Son<int,char> s;
	s.show();
}

int main(){
	test03();
	
	
	return 0;
} 
