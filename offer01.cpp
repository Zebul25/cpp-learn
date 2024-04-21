#include<iostream>
#include<string>


using namespace std;

int divideCore(int dividend, int divisor);

//面试题1：整数除法
int divide(int dividend, int divisor){
	if(dividend==0x8000000&&divisor==-1){
		return INT_MAX;
	}
	int negative=2;
	if(dividend>0){
		negative--;
		dividend=-dividend;
	}
	if(divisor>0){
		negative--;
		divisor=-divisor;
	}
	int result=divideCore(dividend,divisor);
	return negative==1?-result:result;
}
int divideCore(int dividend, int divisor){
	int result=0;
	while(dividend <= divisor){
		int value=divisor;
		int qutient=1;
		while(value >= 0xc000000 && dividend <= value + value){
			qutient += qutient;
			value += value;
		}
		result += qutient;
		dividend -= value;
	}
	return result;
}

//面试题2：二进制加法
string addBinary(string a, string b){
	string result;
	int i=a.size()-1;
	int j=b.size()-1;
	int carry = 0;
	while(i>=0||j>=0){
		int digitA = i >= 0 ? a[i--]-'0' : 0;
		int digitB = j >= 0 ? b[j--]-'0' : 0;
		int sum = digitA + digitB + carry;
		carry = sum >= 2 ? 1 : 0;
		sum = sum >= 2 ? sum - 2 : sum;
		result.push_back(sum);
	}
	
	if(carry == 1){
		result.push_back(1);
	}
	
	return result.reverse_iterator()
}

int main(){
	int a,b;
	cin>>a>>b;
	
	cout<<divide(a,b);
	
	return 0;
} 
