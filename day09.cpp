#include<iostream>
#include<string>
#include<vector>

using namespace std;

void test01(){
	string s1;
	s1.assign("hello");
	string s2;
	s2.assign(s1);
	cout<<s2<<endl;
	cout<<s1<<endl;
	s1.assign("world");
	cout<<s1<<endl;
	
	cout<<s1+s2<<endl;
	string s3("tim");
	s3+='o';
	cout<<s3<<endl;
	s3+="open";
	cout<<s3<<endl;
	s3.append("socket");
	cout<<s3<<endl;
	s3.append(s2);
	cout<<s3<<endl;
	s3.append("thissad",3);
	cout<<s3<<endl;
	
}

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test02(){
	vector<int> v1(10,100);
	printVector(v1);
	vector<int> v2=v1;
	printVector(v2);
	cout<<"v1.capacity() = "<<v1.capacity()<<endl;
	cout<<"v1.size() = "<<v1.size()<<endl;
	cout<<"v2.capacity() = "<<v2.capacity()<<endl;
	cout<<"v2.size() = "<<v2.size()<<endl;
	v1.push_back(20);
	printVector(v1);
	cout<<"v1.capacity() = "<<v1.capacity()<<endl;
	cout<<"v1.size() = "<<v1.size()<<endl;
	v1.resize(23,2);
	printVector(v1);
	cout<<"v1.capacity() = "<<v1.capacity()<<endl;
	cout<<"v1.size() = "<<v1.size()<<endl;
}

void test03(){
	vector<int> v1(100000);
	//swap的妙用 -- 收缩空间
	cout<<"v1 capacity : "<<v1.capacity()<<endl;
	cout<<"v1 size : "<<v1.size()<<endl;
	v1.resize(3);
	cout<<"v1 capacity : "<<v1.capacity()<<endl;
	cout<<"v1 size : "<<v1.size()<<endl;
	vector<int> (v1).swap(v1); 
	cout<<"v1 capacity : "<<v1.capacity()<<endl;
	cout<<"v1 size : "<<v1.size()<<endl;
	//预留空间
	v1.reserve(100);
	cout<<"v1 capacity : "<<v1.capacity()<<endl;
	cout<<"v1 size : "<<v1.size()<<endl;
}

int main(){
	
	test03();
	
	return 0;
}
