/*************************************************************************
	> File Name: 6-10.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Wed 04 May 2016 10:43:54 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

/*
//6. Double_stack_cteate_queue

template<typename T>
class My_queue
{
 public:
        My_queue()
        {
        }
       ~My_queue()
       {}
       void Push(const T&val)
       {
         st1.push(val);
       }
       T Pop()
       {
        if(st2.size() == 0)
        {
         while(st1.size() > 0)
         {
          st2.Push(st1.top());
          st1.pop();
         }
        }
        if(st2.size() == 0)
        {
         cout<<"empty\n";
        }
        T ret =st2.top();
        st2.pop();
        return ret;
       }
    private:
       stack<T>&st1;
       stack<T>&st2;

};


int main()
{

My_queue<int> a;
a.Push(1);
a.Push(2);

cout<<a.Pop()<<endl;
    return 0;
}
*/
/*
//7.旋转数组中找最小的值
int find_min_from_array(int array[],int length)
{
  if(array == 0 || length <=0)
  {
    return -1;
  }
  int left = 0;
  int right = length-1;
  int mid = left;

  while(array[left] >= array[right])
    { 
        if(right - left == 1)
        {
         mid = right;
         break;
        }
        mid = left +((right-left)>>1);
        if(array[mid] == array[left] && array[mid] == array[right])
        {
            mid =0;
         for(int i=1;i<length;++i)
         {
             if(array[i] < array[mid])
             {
                mid = i;
             }
         }
         break;
        }
        if(array[mid] >= array[right])
        {
          left = mid;
        }
        else if(array[mid] <= array[right])
        {
           right = mid;
        }
    
    }
  return mid;
}

int main()
{

//int array[]={4,5,1,2,3};
int array[]={1,0,1,1,1};
cout<<find_min_from_array(array,5)<<endl;

  return 0;
}
*/

/*
//8.斐波那契数列

//递归实现
int  Recur_Fibonacci(int n)
{
  if(n<0)
  {
  return -1;
  }
  if(n==0 || n== 1)
   {
   return n;
   }
    return (Recur_Fibonacci(n-1)+Recur_Fibonacci(n-2));
}

//非递归实现
int Loop_Fibonacci(int n)
{
    if(n<0)
	{
    return -1 ;
    }
   if(n==0 || n== 1)
    {
     return n;
    }
     int f1=0;
	 int f2=1;
	 int f3=0;
	 while(n>=2)
	 {
	       f3=f1+f2;
	       f1=f2;
		   f2=f3;
		   --n;
	 }
	 return f3;

}
int main()
{
cout<<Loop_Fibonacci(6)<<endl;

return 0;
}
*/
/*
//9.二进制中1的个数
//解法1
int Number_Of_One(int n)
{
  int count=0;
  while(n)
	{
      if(n & 1)
		{
	     count++;
	    }
		n>>=1;//但是这种出现负数的时候移位就会引起数据的变化，因为负数是左移高位补符号
  }
  return count;
}
*/
/*
//解法2

int Number_Of_One(int n)
{
     int count = 0;
	 while(n)  //当n的所有位全部变成0的时候结束
	{
	 count++;
	 n &= (n-1); //n-1的使得最后一个位1变成了0
	 }
     return count;
}


int Number_Of_Zero(int n)
{
    int count=0;
	while(n+1)//当n的所有位全变成1的时候再加一就是0了
	{
	 count++;

	 n |= (n+1);//n+1将n的最后一个位0变成了1
	}
    return count;
}

int main()
{
   cout<<Number_Of_One(15)<<endl;
    cout<<Number_Of_Zero(15)<<endl;
  return 0;
}
*/
//求数值的整数次方
double Power(double num,int n )
{
	if((num>-0.0000001 && num < 0.0000001))
	   {
	     return 0.0; 
	   }
      if(n == 0)
	   {
	   return 1.0;
	   }
	   if(n < 0)
	   {
	    n=-n;
	   }
	   double result=1.0;
	   while(n)
	    {
	      result *= num;
		  --n;
	   }
	   if(n < 0)
	   {
	    result=1.0/result;
	   }
	  return result;
}

int main()
{

cout<<Power(0,1)<<endl;
return 0;

}