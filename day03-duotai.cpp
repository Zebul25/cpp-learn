#include<iostream>
#include<string>
using namespace std;

class Animal{
public:
	Animal(){
		cout<<"Animal 构造函数调用"<<endl;
	}
	
	virtual ~Animal() = 0;
	
	virtual void speak(){
		cout<<"动物在说话"<<endl;
	}
	
	
	string *name; 
};
Animal::~Animal(){
	cout<<"纯析构函数调用"<<endl;
}

class Cat : public Animal{
public:
	Cat(string str){
		name =new string(str);
		cout<<"Cat 构造函数调用"<<endl;
	} 
	~Cat(){
		cout<<"Cat 析构函数调用"<<endl;
		if(name!=NULL){
			delete name;
			name=NULL;
		}
	}
	void speak(){
		cout<<*name<<"小猫在说话"<<endl;
	}
};

class Dog : public Animal{
public:
	void speak(){
		cout<<"小狗在说话"<<endl;
	}
};

void doSpeak(Animal &a){
	a.speak();
}

//void test01(){
//	Cat c;
//	Dog d;
//	doSpeak(c);
//	doSpeak(d);
//}

void test03(){
	Animal *c=new Cat("Tom");
	c->speak();
	delete c;
}
class AbstractCalculator{
public:
	//纯虚函数 
	virtual int getResult()=0;
	// 只要类中有一个纯虚函数，该类就称为抽象类
	//抽象类的特点：
	// 1.无法实例化对象
	// 2.子类必须对抽象类的纯虚函数进行重写，否则该子类也为抽象类 
	int m_A;
	int m_B;
};

class AddCalculator : public AbstractCalculator{
public:
	int getResult(){
		return m_A+m_B;
	}
};

class SubCalculator : public AbstractCalculator{
public:
	int getResult(){
		return m_A-m_B;
	}
};

class MulCalculator : public AbstractCalculator{
public:
	int getResult(){
		return m_A*m_B;
	}
};

void test02(){
	AbstractCalculator *p =new AddCalculator;
	p->m_A=10;
	p->m_B=10;
	cout<<p->m_A<<" + "<<p->m_B<<" = "<<p->getResult()<<endl;
	delete p;
	p =new SubCalculator;
	p->m_A=10;
	p->m_B=10;
	cout<<p->m_A<<" - "<<p->m_B<<" = "<<p->getResult()<<endl;
	delete p;
	p =new MulCalculator;
	p->m_A=10;
	p->m_B=10;
	cout<<p->m_A<<" * "<<p->m_B<<" = "<<p->getResult()<<endl;
	delete p;
}

int main(){
	//test03();
	string  str;
	cin>>str;
	cout<<str;
	system("pause");
	return 0;
} 
