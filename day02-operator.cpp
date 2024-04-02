#include<iostream>
using namespace std;

class Complex{
	friend Complex operator + (const Complex& c1,const Complex& c2);
	friend ostream& operator << (ostream& os,const Complex &c);
public:
	Complex(){
		
	}
	
	Complex(int re,int im) : m_re(re),m_im(im) {
		
	}
	
//	Complex operator+(const Complex& c2){
//		Complex c;
//		c.m_re=this->m_re+c2.m_re;
//		c.m_im=this->m_im+c2.m_im;
//		return c;
//	}
	Complex& operator ++ (){
		++m_re;
		return *this;
	}
	Complex operator ++ (int){
		Complex t(*this);
		this->m_re++;
		return t;
	} 
private:
	int m_re;
	int m_im;
};

Complex operator + (const Complex& c1,const Complex& c2){
	return Complex (c1.m_re+c2.m_re,c2.m_im+c1.m_im);
}

ostream& operator << (ostream& os,const Complex &c){
	os<<"("<<c.m_re<<","<<c.m_im<<")";
	return os;
}



void test01(){
	Complex c1(10,10);
	Complex c2(20,20);
	Complex c3=c1+c2;
	cout<<++(++c3)<<endl;
	//cout<<"c3:re = "<<c3.m_re<<" im = "<<c3.m_im<<endl;
	cout<<c3<<endl;
	
	cout<<(c3++)++<<endl;
	cout<<c3<<endl; 
}


int main(){
	test01();
	
	return 0;
}
