#include<iostream>
using namespace std;

class Base{
public:
	Base(){
		m_A=100;
		cout<<"����Base���캯��"<<endl; 
	} 
	~Base(){
		cout<<"����Base��������"<<endl;
	}
	
	void func(){
		cout<<"Base func ��������"<<endl;
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
		cout<<"����Son1���캯��"<<endl;
	}
	~Son1(){
		cout<<"����Son1��������"<<endl;
	}

public:
	void func(){
//		m_A=100;
//		m_B=100;
		//m_C=100;  ˽��Ȩ�� �����޷����� 
		cout<<"Son1 func ��������"<<endl;
	}
	
	int m_A;		
};

void test01(){
	Son1 s1;//�����ȸ�������࣬������������� 
//	s1.m_A=10;
	//s1.m_B=10;  �������� ������ʲ��� 
	//s1.m_C=10	  ˽������ ������ʲ��� 
	
	cout<<"m_A = "<<s1.m_A<<endl;
	cout<<"m_A = "<<s1.Base::m_A<<endl;
	s1.func();
	s1.Base::func();
	//ͬ����̬��Ա�����Ͷ��� ������ͬ 
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
//	s1.m_A=10; �����̳� ԭ�ȵ�public -> protected 
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
//		m_A=1;   ����private���ʲ��� 
	}
};

void test03(){
	Son3 s3;
//	s3.m_A=10; ˽�м̳� public -> private 
//	s3.m_B=10;	        protected -> private  
//	s3.m_C=10;
}
class Base2{
	
}; 
//��̳��﷨  ������ʹ�� 
class Son4 : public Base,public Base2{
	
};

//���μ̳� 
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
