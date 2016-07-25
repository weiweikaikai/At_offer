/*************************************************************************
	> File Name: 11-15.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sun 22 May 2016 08:57:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
 
//11.打印 1到-----N个数字组成的最大数
bool  Increment(char *number,int n)
{
	bool ret = false;
    int ntakeover = 0;
    for(int i=n-1;i>=0;--i)
	   {
	   int sum = number[i]-'0'+ntakeover; 
	     if(i == n-1) //个位数字加一
		   {
		   sum++;
		   }
	   if(sum==10) //个位加1之后等于10的时候。这样加一上来只能等于10
		   {
		       if(i==0) //如果此时最高位加一位10 的时候那就是最大数的时候，此时终止
			   {
                ret = true;
		       }
	           else
			   {
			   sum -= 10; 
               ntakeover=1; //进一位
			   number[i]='0'+sum; //个位赋值
			   }
	       }
		else //个位加一之后没有10大的
		   {
		     number[i]='0'+sum;
			 break;
		   }
	   }
         return ret;
}

void PrintNumber(char *number,int n)
{
	bool begin=true; //begin用于控制输出类似于10 20 后边的零
   for(int i=0;i<n;++i)
	{
     if(begin && number[i] != '0')
		{
	   begin=false;
	     }
		 if(!begin)
		{
		  cout<<number[i];
		 }
    }

}

void Print1ToMaxOfNdigit(int n)
{
  if(n <=0 )
	{
   return ;
    }
   char *number= new char[n+1];
   memset(number,'0',n);
   number[n]='\0';
   
   while(!Increment(number,n)) //每次循环进去执行
	{
     PrintNumber(number,n);
	 cout<<" ";
    }
	cout<<endl;
    
    delete []number;

}

int main()
{

Print1ToMaxOfNdigit(2); 

return 0;
}

