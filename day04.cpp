#include<iostream>
#include<string>
using namespace std;

class CPU{
public:
	virtual void work()=0;
};
class ViewCard{
public:
	virtual void work()=0;
};
class Memory{
public:
	virtual void work()=0;
};

class Computer{
public:
	Computer(CPU* cpu,ViewCard* vc,Memory* mem){
		m_CPU=cpu;
		m_VC=vc;
		m_Mem=mem;
	}
	~Computer(){
		if(m_CPU!=NULL){
			delete m_CPU;
			m_CPU=NULL;
		}
		if(m_VC!=NULL){
			delete m_VC;
			m_VC=NULL;
		}
		if(m_Mem!=NULL){
			delete m_Mem;
			m_Mem=NULL; 
		}
	}
	void work(){
		m_CPU->work();
		m_VC->work();
		m_Mem->work();
	}
private:
	CPU *m_CPU;
	ViewCard *m_VC;
	Memory *m_Mem;
};



class InterCPU : public CPU{
public:
	void work(){
		cout<<"Inter CPU开始计算了..."<<endl;
	}
};
class InterViewCard : public ViewCard{
public:
	void work(){
		cout<<"Inter ViewCard 开始显示了..."<<endl;
	}
};
class InterMemory : public Memory{
public:
	void work(){
		cout<<"Inter Memory 开始存储了..."<<endl;
	}
};


void test01(){
	InterCPU *ic =new InterCPU;
	InterViewCard *iv=new InterViewCard;
	InterMemory *im=new InterMemory; 
	Computer *c=new Computer(ic,iv,im);
	c->work();
	delete c;
}

int main(){
	test01();
	
	return 0;
}
