#include <iostream>
#include<string>
using namespace std;
int StoA(string s, int a[])
{
	int n=s.size();
	for(int i=0; i<n; i++)
		a[n-1-i]=s[i]-48;
	return n;
}

string AtoS(int a[], int n)
{
	string s="";
	for(int i=0; i<n; i++)
	{
		char t=a[i]+48;
		s=t+s;
	}	
	return s;
}

int Minus(int a[], int n1, int b[], int n2, int c[])
{
	int i, x, n3;
	if(n1>=n2)           //大-小
	{
		n3=n1;
	for(i=0; i<n2; i++)//数位对齐
	{
		if(a[i]>=b[i])
		{
		x=a[i]-b[i];
		}
		else 
		{
			x=10+a[i]-b[i];
			a[i+1]=a[i+1]-1;//借位后-1
		}
		c[i]=x;
	}
	for(i=n2;i<n3;i++)//大数多出位数处理
		if(a[i]==0&&i==n3)    //若最高位为0，减一位
			--n3;
		else
			c[i]=a[i];
	}
	else if(n1<n2)  // 大-小
	{
		n3=n2;
	for(i=0; i<n1; i++)
	{
		if(b[i]>=a[i])
		x=b[i]-a[i];
		else 
		{
			x=10+b[i]-a[i];
		b[i+1]=b[i+1]-1;
		}
		c[i]=x;
	}
	for(i=n1;i<n3;i++)
		if(b[i]==0&&i==n3)
			--n3;
		else
			c[i]=b[i];
	}
	return n3;		
}
int main()
{
	string s1="1146"; int a[1000], n1;
	string s2="38";	 int b[1000], n2;
	string s3="";    int c[1000], n3;
	n1=StoA(s1, a);				
	n2=StoA(s2, b);				
	n3=Minus(a, n1, b, n2, c);	
	s3=AtoS(c, n3);			 
	cout<<s3<<endl;
	return 0;
}