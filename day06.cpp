#include<iostream>

using namespace std;

template<typename T>
void mySwap(T &a,T &b){
	T temp=a;
	a=b;
	b=temp;
}

template<class T>
void func(){
	cout<<"this is func!"<<endl;
}

template<typename T>
void selectSort(T arr[],int len){
	int ma=0;
	for(int i=0;i<len-1;i++){
		ma=i;
		for(int j=i+1;j<len;j++){
			if(arr[j]>arr[ma]){
				ma=j;
			}
		}
		if(ma!=i){
			mySwap(arr[ma],arr[i]);
		}
	}
}

template<typename T>
void print(T arr[],int len){
	for(int i=0;i<len;i++){
		cout<<arr[i];
	}
	cout<<endl;
}

void test02(){
	char arr[]="acbdef";
	int len=sizeof(arr)/sizeof(char);
	selectSort<char>(arr,len);
	int nums[]={2,1,4,5,3};
	print<char>(arr,len);
	selectSort<int>(nums,5);
	print<int>(nums,5);
}

void test01(){
	double a=10,b=20;
	//自动推到 
	mySwap(a,b);
	cout<<"a = "<<a<<" b = "<<b<<endl;
	
	func<int>();
} 

int main(){
	test02();
	
	
	return 0;
}
