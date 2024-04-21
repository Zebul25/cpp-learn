#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Person;

template<class T>
class MyArray{
public:
	MyArray(int capacity) : m_Capacity(capacity){
		this->m_Size=0;
		this->pAddress=new T[capacity];
		cout<<"调用构造函数"<<endl; 
	}
	
	MyArray(const MyArray &arry){
		this->m_Capacity=arry.m_Capacity;
		this->m_Size=arry.m_Size;
		this->pAddress=new T[arry.m_Capacity];
		for(int i=0;i<arry.m_Size;i++){
			this->pAddress[i]=arry.pAddress[i];
		}
		cout<<"调用拷贝构造函数"<<endl;
	}
	
	//重载= 
	MyArray& operator = (const MyArray & arr){
		if(this->pAddress!=NULL){
			delete[] this->pAddress;
			this->pAddress=NULL;
		}
		//深拷贝 
		this->m_Capacity=arr.m_Capacity;
		this->m_Size=arr.m_Size;
		this->pAddress=new T[arr.m_Capacity];
		for(int i=0;i<arr.m_Size;i++){
			this->pAddress[i]=arr.pAddress[i];
		}
		cout<<"调用拷贝赋值"<<endl;
	}
	
	//尾插 
	void Push_Back(const T& val){
		if(this->m_Size==this->m_Capacity){
			return;
		}
		this->pAddress[this->m_Size++]=val;
	} 
	
	//尾删
	void Pop_Back(){
		if(this->m_Size==0){
			return;
		}
		this->m_Size--;
	} 
	
	//[]重载
	T& operator[](int index){
		return this->pAddress[index];
	} 
	
	int size(){
		return this->m_Size;
	}
	
	int capacity(){
		return this->m_Capacity;
	}
	
	~MyArray(){
		if(this->pAddress!=NULL){
			delete[] this->pAddress;
			this->pAddress=NULL;
		}
		cout<<"调用析构函数"<<endl;
	}
	
private:
	int m_Capacity;
	int m_Size;
	T *pAddress;
};

void printIntArray(MyArray<int> &arr){
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<endl;
	}
}

class Person{
public:
	Person(){
		
	}
	
	Person(string name,int age):m_Name(name),m_Age(age){
		
	}

	string m_Name;
	int m_Age;
};

void PrintPersonArray(MyArray<Person> &arr){
	for(int i=0;i<arr.size();i++){
		cout<<"姓名："<<arr[i].m_Name<<" 年龄："<<arr[i].m_Age<<endl;
	}
} 

void test01(){
	MyArray<int> a1(10);
	for(int i=0;i<5;i++){
		a1.Push_Back(i);
	}
	printIntArray(a1);
	cout<<a1.capacity()<<endl;
	cout<<a1.size()<<endl;
	Person p1("张三",24);
	Person p2("李四",22);
	Person p3("王五",21);
	MyArray<Person> p(5);
	p.Push_Back(p1);
	p.Push_Back(p2);
	p.Push_Back(p3);
	PrintPersonArray(p);
	
}

void func(int val){
	cout<<val<<endl;
}

void test02(){
	vector<int> v1={1,2,3,4,5};
	for_each(v1.begin(),v1.end(),func);
} 




int main(){
	test02();
	
	return 0;
} 
