#include<iostream>
using namespace std;

class Person{
public:
	Person(){
		cout<<"����PersonĬ�Ϲ��캯����"<<endl;
	}
	
	Person(int a) : age(a){
		cout<<"����Person���ι��캯����"<<endl;
	}
	
	Person(const Person& p){
		this->age=p.age;
		cout<<"����Person�������캯��"<<endl;
	}
	
	~Person(){
		cout<<"����Person��������"<<endl;
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
	cout<<"����test01"<<endl;
} 


int main(){
	
	test01();
	return 0;
}
