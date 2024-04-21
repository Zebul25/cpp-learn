#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int> dq){
	for(deque<int>::const_iterator it=dq.begin();it!=dq.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01(){
	deque<int> dq(10,100);
	printDeque(dq);
	//deque没有容量的概念capacity 
	cout<<"deque size : "<<dq.size()<<endl;
	dq.push_back(1);
	dq.push_front(2);
	printDeque(dq); 
	cout<<"deque size : "<<dq.size()<<endl;
}

int main(){
	test01();
	
	return 0;
}
