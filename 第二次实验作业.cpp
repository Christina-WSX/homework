#include<iostream>
using namespace std;
#include"math.h"
void Calculation (int x)
{
		float a,b,c,x1,x2;             
	    float temp;//计算b*b-4*a*c   
		float num;//开根号                             
		cin>>a>>b>>c;  
		temp=b*b-4*a*c;   
	    num=sqrt(temp);                            
		if(temp>0) //两个不同实根
		{
		x1=(-b+num)/(2*a);
		x2=(-b-num)/(2*a);
		cout<<"x1="<<x1<<"x2="<<x2<<endl;
		}
	   if(temp==0)//一个相同实根
	   {
        x1=x2=(-b)/(2*a);
        cout<<"x1=x2="<<x1<<endl;
	   }    
}
void area(float s)
{
		float a,b,c,p,l;
		cin>>a>>b>>c;
		l=a+b+c;
		p=l/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<"s="<<s<<endl;
}
void date(int i)
{
		int year,month,day;
		cin>>year>>month>>day;
        int days = 0;
        int day_tab[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (i=1; i<month; i++)
		{
        days += day_tab[i];
		}
        days += day;
        if ((year%4==0 && year%100!=0 || year%400==0) && month>=3)
        days+=1;
    	cout<<"days="<<days<<endl;
        int circle;
		circle=(days/7)+1;
		cout<<"circle="<<circle<<endl;
}        
int main()
{
	float x,s;
	int i;
      Calculation (x);
      area(s);
      date(i);
}
