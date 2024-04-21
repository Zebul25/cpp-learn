#include<stdio.h>
#include<math.h>

void test23(){
	for(int i=0;i<4;i++){
		for(int j=i;j>0;j--){
			printf(" ");
		}
		for(int j=0;j<4-i;j++){
			printf("* ");
		}
		printf("\n");
	}
}
void test24(){
	int fahr=105;
	int c=5*(fahr-32)/9;
	printf("fahr = 150, celsius = %d",c);
}

void test26(){
	double g=10;
	double t=3;
	double dist=g*t*t/2;
	printf("height = %.2f",(dist>100)?100:dist);
}

void test28(){
	int f;
	scanf("%d",&f);
	int c=5*(f-32)/9;
	printf("Celsius = %d",c);
}
void test29(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d + %d = %d\n",a,b,a+b);
	printf("%d - %d = %d\n",a,b,a-b);
	printf("%d * %d = %d\n",a,b,a*b);
	printf("%d / %d = %d",a,b,a/b);
}
void test210(){
	float x;
	scanf("%f",&x);
	float r;
	if(x==0)
		r=0;
	else
		r=1/x;
	printf("f(%.1f) = %.1f",x,r);
}
void test211(){
	float x;
	scanf("%f",&x);
	float r;
	if(x>=0){
		r=sqrt(x);
	}else{
		r=pow(x+1,2)+x*2+1/x;
	}
	printf("f(%.2f) = %.2f",x,r);
}
void test212(){
	int lower,upper;
	scanf("%d %d",&lower,&upper);
	if(upper<lower||upper>100){
		printf("Invalid.");
		return;
	}
	printf("fahr celsius");
	for(int i=lower;i<=upper;i+=2){
		double c=5.0*(i*1.0-32)/9.0;
		printf("\n%d%6.1f",i,c);
		
	}
}
void test213(){
	int n;
	scanf("%d",&n);
	double sum=0;
	for(int i=1;i<=n;i++){
		sum=sum+1.0/i;
	}
	printf("sum = %.6lf",sum);
}
void test214(){
	int n;
	scanf("%d",&n);
	double sum=0;
	for(int i=1;i<=n;i++){
		sum=sum+1.0/(2*i-1);
	}
	printf("sum = %.6lf",sum);
}
void test215(){
	int n;
	scanf("%d",&n);
	double sum=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			sum=sum+1.0/(3*i-2);
		}else{
			sum=sum-1.0/(3*i-2);
		}
	}
	printf("sum = %.3lf",sum);
}
void test217(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		int r=pow(3,i);
		printf("pow(3,%d) = %d",i,r);
		if(i!=n)
			printf("\n");
	}
}

double fact(int n){
	if(n==0||n==1)
		return 1.0;
	else
		return n*fact(n-1)*1.0;
}
void test218(){
	int m,n;
	scanf("%d %d",&m,&n);
	double r=fact(n)/fact(m)/fact(n-m);
	printf("result = %.0lf",r);
}
void x21(){
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int sum=a+b+c+d;
	double avg=(a+b+c+d)/4.0;
	printf("Sum = %d; Average = %.1lf",sum,avg);
}
void x22(){
	int e;
	scanf("%d",&e);
	if(e<0){
		printf("Invalid Value!");
		return;
	}
	double cost;
	if(e<=50){
		cost=e*0.53;
	}else{
		cost=50*0.53+(e-50)*0.58; 
	}
	printf("cost = %.2lf",cost);
}
void x23(){
	int m,n;
	scanf("%d %d",&m,&n);
	double sum=0;
	for(double i=m;i<=n;i++){
		sum=sum+pow(i,2)+1.0/i;
	}
	printf("sum = %.6lf",sum);
}
void x24(){
	int n;
	scanf("%d",&n);
	double sum=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			sum+=i*1.0/(2*i-1);
		}else{
			sum-=i*1.0/(2*i-1);
		}
	}
	printf("%.3lf",sum);
}
void x25(){
	int n;
	scanf("%d",&n);
	double sum;
	for(int i=1;i<=n;i++){
		sum+=sqrt(i);
	}
	printf("sum = %.2lf",sum);
}
void x26(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=fact(i);
	}
	printf("%d",sum);
}
void test32(){
	int n;
	scanf("%d",&n);
	int r;
	if(n>0){
		r=1;
	}else if(n==0){
		r=0;
	}else{
		r=-1;
	}
	printf("sign(%d) = %d",n,r);
}
void test33(){
	int n;
	scanf("%d",&n);
	int count=0;
	double sum=0;
	double x;
	for(int i=0;i<n;i++){
		scanf("%lf",&x);
		sum+=x;
		if(x>=60){
			count++;
		}
	}
	printf("average = %.1lf\ncount = %d",sum/n,count);	 
}
void test34(){
	char ch;
	int letter=0,blank=0,digit=0,other=0;
	for(int i=0;i<10;i++){
		ch=getchar();
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
			letter++;
		}else if(ch==' '||ch=='\n'){
			blank++;
		}else if(ch>='0'&&ch<='9'){
			digit++;
		}else{
			other++;
		}
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
}
void test35(){
	int n;
	scanf("%d",&n);
	if(n>2100||n<=2000){
		printf("Invalid year!");
	}else{
		int f=1;
		for(int i=2001;i<n;i++){
			if(i%400==0||(i%4==0&&i%100!=0)){
				f=0;
				printf("%d\n",i);
			}
		}
		if(f){
			printf("None");
		}
	}

}
void test37(){
	int n;
	scanf("%d",&n);
	if(n>=90){
		printf("A");
	}else if(n>=80){
		printf("B");
	}else if(n>=70){
		printf("C");
	}else if(n>=60){
		printf("D");
	}else{
		printf("E");
	}
}
void test38(){
	printf("[1] apple\n");
	printf("[2] pear\n");
	printf("[3] orange\n");
	printf("[4] grape\n");
	printf("[0] exit\n");
	int x;
	for(int i=0;i<5;i++){
		scanf("%d",&x);
		if(x==1){
			printf("price = 3.00\n");
		}else if(x==2){
			printf("price = 2.50\n");
		}else if(x==3){
			printf("price = 4.10\n");
		}else if(x==4){
			printf("price = 10.20\n");	
		}else if(x==0){
			break;
		}else{
			printf("price = 0.00\n");
		}
	}
}
void x31(){
	int a,b,c,t;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){
		t=a;
		a=b;
		c=t;
	}
	if(a>c){
		t=a;
		a=c;
		c=t;
	}
	if(b>c){
		t=b;
		b=c;
		c=t;
	}
	
	printf("%d->%d->%d",a,b,c);
}
void x32(){
	int real,limit;
	scanf("%d %d",&real,&limit);
	double exceed=(real-limit)*100.0/limit;
	if(exceed>=50){
		printf("Exceed %.0lf%%. License Revoked",exceed);
	}else if(exceed>=10){
		printf("Exceed %.0lf%%. Ticket 200",exceed);
	}else{
		printf("OK");
	}
}
void x33(){
	double dist;
	int  wt;
	scanf("%lf %d",&dist,&wt);
	double cost=0;
	if(dist<=3){
		cost+=10;
	}else if(dist<=10){
		cost+=10;
		cost+=(dist-3)*2;
	}else{
		cost+=10;
		cost+=(10-3)*2;
		cost+=(dist-10)*3;
	}
	if(wt>=5){
		cost+=wt/5*2;
	}
	printf("%.0lf",cost);
}
void x34(){
	int n;
	scanf("%d",&n);
	int x;
	int a=0,b=0,c=0,d=0,e=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x>=90){
			a++;
		}else if(x>=80){
			b++;
		}else if(x>=70){
			c++;
		}else if(x>=60){
			d++;
		}else{
			e++;
		}
	}
	printf("%d %d %d %d %d",a,b,c,d,e);
}
double edge(double x1,double y1,double x2,double y2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
void x35(){
	double x1,y1,x2,x3,y2,y3;
	scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
	double a=edge(x1,y1,x2,y2);
	double b=edge(x1,y1,x3,y3);
	double c=edge(x2,y2,x3,y3);
	double p,s;
	if(a+b>c&&a+c>b&&b+c>a){
		p=(a+b+c)/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));//º£Â×¹«Ê½
		printf("L = %.2lf,A = %.2lf",2*p,s); 
		return;
	}
	printf("Impossible");
}
void test43(){
	double eps;
	scanf("%lf",&eps);
	double sum=0,item;
	int i=0;
	int f=1;
	do{
		item=1.0/(3*i+1);
		sum+=f*item;
		f=-f;
		i++;
	}while(item>eps);
	printf("sum = %.6lf",sum);
}
void test46(){
	int num,n;
	scanf("%d %d",&num,&n);
	int x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x>num){
			printf("Too big\n");
		}else if(x<num){
			printf("Too small\n");
		}else{
			if(n<1){
				printf("Bingo!");
			}else if(n<3){
				printf("Lucky You!");
			}else
				printf("Good Guess!");
			return;
		}
	}
	printf("Game Over");
}

void test47(){
	int n;
	scanf("%d",&n);
	double sum=1;
	int i=1;
	while(n){
		sum+=1.0/fact(i);
		i++;
		n--;
	}
	printf("%.8lf",sum);
}
void test410(){
	int n;
	scanf("%d",&n);
	int res;
	int x;
	scanf("%d",&res);
	for(int i=1;i<n;i++){
		scanf("%d",&x);
		if(x<res){
			res=x;
		}
	}
	printf("min = %d",res);
}
void test411(){
	int m,n;
	scanf("%d %d",&m,&n);
	int count=0;
	int sum=0;
	for(int i=m;i<=n;i++){
		int flag=1;
		for(int j=2;j<i/2;j++){
			if(i%j==0){
				flag=0;
				break;
			}
		}
		if(flag){
			count++;
			sum+=i;
//			printf("%d\n",i);
		}
	}
	printf("%d %d",count,sum);
}
void x41(){
	int sum=0;
	int x;
	scanf("%d",&x);
	while(x>0){
		if(x%2==1){
			sum+=x;
		}
		scanf("%d",&x);
	}
	printf("%d",sum);
}
void x42(){
	double x;
	scanf("%lf",&x);
	int k=1;
	double sum=1;
	double item;
	do{
		item=1.0/fact(k);
		sum=sum+pow(x,k)*item;
		k++;
	}while(item>=0.00001);
	printf("%.4lf",sum);
}
void x43(){
	int n;
	scanf("%d",&n);
	 
}

int main(){
	int a=1,b=1,c=1,d=1,m=1,n=1;
	(m=a>b)&&(n=c>d);
	printf("%d %d",m,n);
	
	
	return 0;
}
