#include<iostream>
using namespace std;

class Person{
public:
	Person(){
		cout<<"调用Person默认构造函数！"<<endl;
	}
	
	Person(int a) : age(a){
		cout<<"调用Person含参构造函数！"<<endl;
	}
	
	Person(const Person& p){
		this->age=p.age;
		cout<<"调用Person拷贝构造函数"<<endl;
	}
	
	~Person(){
		cout<<"调用Person析构函数"<<endl;
	}

public: 
	int age;
};

void test01(){
	Person p1;
	cout<<p1.age<<endl;
	Person p2(10);
	cout<<p2.age<<endl;
	Person p3(p2);
	cout<<p3.age<<endl;
	cout<<"结束test01"<<endl;
} 


int main(){
	
	test01();
	return 0;
}
