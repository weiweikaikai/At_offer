/*************************************************************************
	> File Name: 46-50.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Wed 24 Aug 2016 12:18:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
 //46 不使用逻辑和加减法计算1+2+......+n
 //1.开放性思维  利用多个对象构造函数  和静态变量
 class tmp
 {
	 public:
		 tmp(){++n; sum+=n;}
	 static unsigned int GetSum()
	 {
	   return sum;
	 }
	 private:
		 static unsigned int n;
	     static unsigned int sum;
 };
 unsigned int tmp::n=0;
 unsigned int tmp::sum=0;
  unsigned int sumof1ton(unsigned int n)
  {
     tmp *p = new tmp[n];
	 delete []p;
	 p=NULL;

	 cout<<tmp::GetSum()<<endl;
  }
//2.利用多态虚函数的实现方式模拟递归实现
class base
{
   public:
	   virtual unsigned int sum(unsigned int n)
	   {
	   return 0;
       }
};

base * array[2];
class Dri:public base
{
	public:
		virtual unsigned int sum(unsigned int n)
	{
	    return array[!!n]->sum(n-1)+n;
	}
};
unsigned int sumofnum(unsigned int n)
{
    base a;
	Dri b;
	array[0]=&a;
	array[1]=&b;
	unsigned int value = array[1]->sum(n);
	cout<<value<<endl;
	return value;
}
//47 不用四则运算计算加法
int add (int num1,int num2)
{
  int sum=0;
  int carray=0;
  do
  {
	  sum =num1 ^ num2;
	  carray = (num1&num2) <<1;
	  num1= sum;
	  num2=carray;
  }
  while (num2 != 0);
  cout<<num1<<endl;
  return num1;
}
//49: 字符串转化为数字
int  Myatoi(const char *str)
{
  if(str == NULL)
	{
        return -1; //并设置errno
    }
	int flag=1;
	if(*str == '-')
	{
	  flag =-1;
	  ++str;
	}
	if(*str == '+')
	{
	  ++str;
	}
   int ret=0;
   while(*str != '\0')
	{
	    if(*str >='0' && *str<='9')
		{
         ret =ret*10+ (*str-'0');
		}
		++str;
    }
	return ret*flag;

}
//48:不能别继承的类 用C++设计一个不能被继承的类

//1.把构造函数 和析构函数 设置为私有 
//但是为了可以获得当前类的实例还是要定义一个公有的静态函数来创建和释放类的实例

class hello
{
	public:
	static hello* getinstance()
	{
	   return new hello();
	}
	static void deleteinstance(hello * p)
	{
	   delete p;
	   p=NULL;
	}
};

void test_49()
{
   cout<<Myatoi("+1234567")<<endl;
   cout<<Myatoi("-1234567")<<endl;
   cout<<Myatoi("1234567")<<endl;
   cout<<Myatoi("")<<endl;
}

//50树中两个节点的最低公共祖先



int main()
{
	//test_49();
	sumof1ton(100);
	sumofnum(100);
	add(100,200);
    return 0;
}

