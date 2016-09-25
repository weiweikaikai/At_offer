/*************************************************************************
	> File Name: 31-35.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Mon 25 Jul 2016 11:08:53 AM CST
 ************************************************************************/

#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<iostream>
using namespace std;
 //31连续子数组的最大和
/*输入一个整形数组,数组中有正数也有负数,数组中一个或者连续的多个整数组成一个子数组。
求所有子数组的和的最大值，
时间复杂度为O(n)
*/
  int FindGreatestSumOfSubArray(vector<int> array) 
  {
      if(array.size() == 0)
	  {
	    return 0;
	  }
       int Max=0x80000000;
	   int sum=0;
	   for(int i=0;i<(int)array.size();++i)
	   {
	      if(sum <=0 )
		   {
		     sum = array[i];
		   }
		   else
		   {
		    sum += array[i];
		   }
		 
		   if(sum > Max)
		   {
		      Max = sum; 
		   }
	   }

	   return Max;
  }
void test_31()
{
    vector<int> array;
	array.push_back(6);
	array.push_back(-3);
	array.push_back(-2);
	array.push_back(7);
	array.push_back(-15);
    array.push_back(1);
	array.push_back(2);
	array.push_back(2);
	cout<<FindGreatestSumOfSubArray(array)<<endl;
}

//31扩展   打印出和最大的子序列
int FindGreat(vector<int> array)
{
	if (array.size() == 0)
	{
		return 0;
	}
	int Max = 0x80000000;
	int sum = 0;
	int end = 0;
	stack<int>st;
	for (int i = 0; i<(int)array.size(); ++i)
	{
		if (sum <= 0)
		{
			sum = array[i];
		}
		else
		{
			sum += array[i];
		}
		if (sum > Max)
		{
			Max = sum;
			end = i;
		}
	}
	int tmp=Max;
	for (int j = end; j >= 0; --j)
	{
		tmp -=array[j];
		if ( tmp== 0)
		{
			st.push(array[j]);
			break;
		}
		else
		{
			st.push(array[j]);
		}
	}
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	return Max;
}
void test_31_()
{
	vector<int> array;
	array.push_back(6);
	array.push_back(-3);
	array.push_back(-2);
	array.push_back(7);
	array.push_back(-15);
	array.push_back(1);
	array.push_back(2);
	array.push_back(2);
	cout << FindGreat(array) << endl;
}

//32.整数中1出现的次数（从1到n整数中1出现的次数）
  int NumberOf1Between1AndN_Solution(int n)
  {
	  if(n<=0 )
	  {
	  return 0;
	  }
	  int count=0;
      for(int i=1;i<=n;++i)
	  {
		  int tmp = i;
		  while(tmp)
		  {
	        if(tmp%10 == 1)
		      {
		        count++;
		      }
			  tmp/=10;
		  }
	  }
	  return count;
  }
  void test_32()
  {
     cout<<NumberOf1Between1AndN_Solution(13)<<endl;
  }
//33.把数组排成最小的数
/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
string My_itoa(int x)
{
    return (x>9?My_itoa(x/10):"")+ (char)(x%10+'0');
}
bool cmp(int a,int b)
{
   return My_itoa(a)+My_itoa(b) < My_itoa(b)+My_itoa(a);
}

string PrintMinNumber(vector<int> vec)
{
   sort(vec.begin(),vec.end(),cmp);
   string str="";
   for(int i=0;i<(int)vec.size();++i)
	{
      str += My_itoa(vec[i]);
    }
    return str;
 }

void test_33()
{
	vector<int> arr;
	arr.push_back(3);
    arr.push_back(32);
	arr.push_back(321);
   cout<<PrintMinNumber(arr)<<endl;
}

//34.丑数
/*
把只包含因子2、3和5的数称作丑数（Ugly Number)
例如6、8都是丑数，但14不是，因为它包含因子7
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数
*/

int min(int a,int b,int c)
{
   int tmp = a> b ?b:a;
   return tmp>c?c:tmp;
}

 int GetUglyNumber_Solution(int index)
 {
	 if(index <= 0)
	 {
	 return 0;
	 }
    int vec[index];
	int *p2,*p3,*p5;
	p2 = p3 = p5=vec;
	vec[0]=1;
	int NextUglyIndex=1;
 
     while(NextUglyIndex < index)
	 {
	    vec[NextUglyIndex]=min(*p2*2,*p3*3,*p5*5);
		while(*p2*2 <= vec[NextUglyIndex])
		       ++p2;

		while(*p3*3<=vec[NextUglyIndex])
                ++p3;

        while(*p5*5<=vec[NextUglyIndex])
                ++p5;

		++NextUglyIndex;
	 }
    return vec[index-1];
 }

void test_34()
{
   cout<<GetUglyNumber_Solution(20)<<endl;
}

//35 第一个只出现一次的字符
/*
  在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)
  中找到第一个只出现一次的字符,并返回它的位置
*/

 int FirstNotRepeatingChar(string str) 
{
   vector<char> vec(256,0);
   for(int i=0;i<(int)str.size();++i)
	{
      vec[str[i]-'a']++;
   }

   for(int i=0;i<(int)vec.size();++i)
	{
       if(vec[i] == 1)
		{
	     return i;
	   }
   }
   return -1;
 }
void test_35()
{
	string str="google";
    cout<<FirstNotRepeatingChar(str)<<endl;

}
int main()
{
	
	test_31();
	test_31_();
    // test_32();
   //test_33();
   // test_34();
   // test_35();
}