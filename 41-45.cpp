/*************************************************************************
	> File Name: 41-45.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Wed 24 Aug 2016 12:17:49 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
//41.打印出一个正数序列中和为某一个数的序列
//1.和为某一个数的序列长度是2
void  print(vector<int> &vec,int value)
{
	if(vec.size() == 0)
	{
	  return;
	}
	int length=(int)vec.size();
    int *left=&vec[0];
    int *right=&vec[length-1];

	while(left < right)
	{
		int sum=(*left + *right);
	  if(sum < value)
		{
		  left++;
		}
	   else if(sum > value)
		{
	     right--;
	    }
		else
		{
		  cout<<*left<<" "<<*right<<endl;
			  return ;
		}
	}
   return ;
}
//求所有的和为value值的序列
void print_(vector<int> &vec,int value)
{
  if(vec.size() <= 1)
	{
       return ;
    }
      int length=vec.size()-1;
      int small=0;
	  int big=1;
	  int sum = vec[small]+vec[big];
	  while(small < big)
	  {
	     if(sum < value)
		{
	      ++big;
		  sum +=vec[big];
	    }
		else if(sum > value)
		{
		  sum -= vec[small];
		   ++small;
		}
		else
		{
		 for(int i=small;i<=big;++i)
			{
		      cout<<vec[i]<<" ";
		    }
		 cout<<endl;
		}
	  }
   return ;
}
void test_41()
{
    vector<int>vec;
	vec.push_back(1);
	vec.push_back(2);
    vec.push_back(4);
    vec.push_back(7);
	vec.push_back(11);
	vec.push_back(15);
    print(vec,15);
}
void test_41_()
{
    vector<int>vec;
	vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
    vec.push_back(7);
	vec.push_back(8);
    print_(vec,15);
}
//42翻转字符串

void ReveseStr(char *str)
{
   if(str == NULL || *str == '\0')
	{
      return ;
    }
    char *start=str;
	char *end=str;
	char*cur = str;
	int flag=0;
	 char tmp='\0';
	do
	{
		if(*cur == ' ' || *cur == '\0')
		{
			flag=1;
		   end =cur-1;
		   while(start < end)
			{
		      tmp= *end;
			  *end--=*start;
			  *start++=tmp;
			}
			 
		}
		if(flag)
		{
		  flag=0;
		  start = cur+1;
		}
	}
	while (*cur++ != '\0');
	
	cur-=2;
	while(str < cur)
	{
	 tmp = *cur;
	*cur--=*str;
    *str++=tmp;
	}
}
//扩展: 循环左移的问题
void leftLoopMove(char *str,int n)
{
  if(str == NULL || *str=='\0' || n<=0)
	{
       return;
    }
	int length =strlen(str);
	char *start = str;
	char *end = str;
	char tmp = '\0';
	char *cur=str;
	int flag=0;
    int count=0;
	do
	{
		++count;
		if (count == n || count==length)
		{
			  end=cur;
			  flag=1;
           while(start < end)
			{
			  tmp = *end;
			  *end--=*start;
			  *start++ =tmp;
		    }
		}
		if(flag)
		{
		 flag=0;
		 start=cur+1;
		}
		
	}
	while (*cur++ != '\0');
		cur-=2;
	while(str < cur)
	{
	 tmp = *cur;
	*cur--=*str;
    *str++=tmp;
	}
}

void test_42()
{
   char str[]="I am a student.";
   ReveseStr(str);
   cout<<str<<endl;
}

void test_42_()
{
  char str[]="abcdefg";
  leftLoopMove(str,4);
  cout<<str<<endl;
}
// 43.n个骰子的点数   
//n个骰子的和最小值为n 最大值为6n  打印出所有和为s出现的次数



//44


//45



int main()
{
	//test_41();
	//test_41_();
	//test_42();
	test_42_();
    return 0;
}

