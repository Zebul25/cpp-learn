#include<stdio.h>
#include<math.h>

#define MAXN 10

//l5-1.本题要求实现一个计算m~n（m<n）之间所有整数的和的简单函数。
int sum(int m,int n){
	int res=0;
	for(int i=m;i<=n;i++){
		res+=i;
	}
	return res;
}
//l5-2.本题要求对两个整数a和b，输出其中较大的数。
int max(int a,int b){
	return a>b?a:b;
}
//l5-3.本题要求实现函数输出n行字符金字塔。
void CharPyramid(int n,char ch){
	
	for(int i=1;i<=n;i++){
		for(int j=n-i;j>0;j--){
			printf(" ");
		}
		for(int j=0;j<i;j++){
			printf("%c ",ch);
		}
		printf("\n");
			
	}
}
//x5-1.本题要求实现符号函数sign(x)。
int sign(int x){
	if(x>0)
		return 1;
	else if(x==0)
		return 0;
	else
		return -1;
}
//x5-2.本题要求实现一个函数，计算N个整数中所有奇数的和，同时实现一个判断奇偶性的函数。
int even(int n){
	return n%2==0;
} 
int OddSum(int List[],int N){
	int res=0;
	for(int i=0;i<N;i++){
		if(!even(List[i])){
			res+=List[i];
		}
	}
	return res;
}
//x5-3.本题要求实现一个函数，对给定平面任意两点坐标(x1,y1)和(x2,y2),求这两点之间的距离
double dist(double x1,double y1,double x2,double y2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
} 
//x5-4.本题要求实现一个判断素数的简单函数、以及利用该函数计算给定区间内素数和的函数。
//素数就是只能被1和自身整除的正整数。注意：1不是素数，2是素数。
int prime(int p){
	if(p<=1)
		return 0;
	for(int i=2;i<=p/2;i++){
		if(p%i==0)
			return 0;
	} 
	return 1;
}
int PrimeSum(int m,int n){
	int sum=0;
	for(int i=m;i<=n;i++){
		if(prime(i)){
			sum+=i;
		}
	}
	return sum;
}
//x5-5.本题要求实现一个统计整数中指定数字的个数的简单函数。 -24024
int CountDigit(int number,int digit){
	int cnt=0;
	char num[64];
	sprintf(num,"%d",number);
	for(int i=0;i<strlen(num);i++){
		if(num[i]-'0'==digit){
			cnt++;
		}
	}
	return cnt;
}
//x5-6使用函数输出水仙花数
int narcissistic(int number){
	char str[64];
	sprintf(str,"%d",number);
	int len=strlen(str);
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=(pow(str[i]-'0',len));
	}
	return sum==number;
}
void PrintN(int m,int n){
	
	for(int i=m;i<=n;i++){
		if(narcissistic(i))
			printf("%d\n",i);
	}
}
//x5-7使用函数求余弦函数的近似值
double funcos(double e,double x){
	double n=0;
	double sum=0;
	
}
double jiecheng(double n){
	if(n==0||n==1)
		return 1;
	else
		return n*jiecheng(n-1);
}

int main(){
	int m, n;
  
    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);
	return 0;	
} 
