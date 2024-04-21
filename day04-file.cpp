#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void test01(){
	ofstream ofs;
	ofs.open("test.txt",ios::out);
	ofs<<"����������"<<endl;
	ofs<<"���䣺21"<<endl;
	ofs<<"�Ա���"<<endl;
	
	ofs.close();
}

void test02(){
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	if(!ifs.is_open()){
		cout<<"�ļ���ʧ��"<<endl;
		return ;
	}
	//1.
//	char buf[1024]={0};
//	while(ifs>>buf){
//		cout<<buf<<endl;
//	}
	//2.
//	char buff[1024]={0};
//	while(ifs.getline(buff,sizeof(buff))){
//		cout<<buff<<endl;
//	}
	//3.
//	string str;
//	while(getline(ifs,str)){
//		cout<<str<<endl;
//	}
	//4.
	char c;
	while((c=ifs.get())!=EOF){
		cout<<c;
	}
	ifs.close();
}

class Person{
public:
	Person(){
		
	}
	Person(char name[],int age){
		m_Name=name;
		m_Age=age;
	}

	char* m_Name;
	int m_Age;
};

void test03(){
	Person p("����",24);
	ofstream ofs("person.txt",ios::out|ios::binary);
	ofs.write((const char*)&p,sizeof(Person));
	
	ofs.close();
}

void test04(){
	ifstream ifs("person.txt",ios::in|ios::binary);
	if(!ifs.is_open()){
		cout<<"�ļ���ʧ��"<<endl;
		return;
	}
	Person p;
	ifs.read((char*)&p,sizeof(Person));
	
	cout<<"������"<<p.m_Name<<" ���䣺 "<<p.m_Age<<endl;
	ifs.close();
}

int main(){
	test04();
	
	return 0;
}
