#include<iostream>
#include<string>
using namespace std;

class Animal{
public:
	Animal(){
		cout<<"Animal ���캯������"<<endl;
	}
	
	virtual ~Animal() = 0;
	
	virtual void speak(){
		cout<<"������˵��"<<endl;
	}
	
	
	string *name; 
};
Animal::~Animal(){
	cout<<"��������������"<<endl;
}

class Cat : public Animal{
public:
	Cat(string str){
		name =new string(str);
		cout<<"Cat ���캯������"<<endl;
	} 
	~Cat(){
		cout<<"Cat ������������"<<endl;
		if(name!=NULL){
			delete name;
			name=NULL;
		}
	}
	void speak(){
		cout<<*name<<"Сè��˵��"<<endl;
	}
};

class Dog : public Animal{
public:
	void speak(){
		cout<<"С����˵��"<<endl;
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
	//���麯�� 
	virtual int getResult()=0;
	// ֻҪ������һ�����麯��������ͳ�Ϊ������
	//��������ص㣺
	// 1.�޷�ʵ��������
	// 2.�������Գ�����Ĵ��麯��������д�����������ҲΪ������ 
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
