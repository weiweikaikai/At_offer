/*************************************************************************
	> File Name: 11-15.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sun 22 May 2016 08:57:18 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
 
//11.打印 1到--N个数字组成的最大数
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

void test_11()
{
  Print1ToMaxOfNdigit(2); 
}

//12.用O(1)的复杂度删除链表节点
typedef struct ListNode
{
	struct ListNode *next;
	int data;
}ListNode;

void push_back(ListNode *&head,int dt)
{
    if(head == NULL)
	{
	   head = new ListNode;
	   head->data = dt;
	   head->next = NULL;
	}
     else
	{
	   ListNode *cur=head;
	   while(cur->next != NULL)
		{
	     cur=cur->next;
	    }
		ListNode *tmp =new ListNode;
		tmp->data=dt;
		tmp->next =NULL;
		cur->next =tmp;
     }
}

void print(ListNode *head)
{
	if(head == NULL)
	{
	  return;
	}
    ListNode *cur=head;

	while(cur != NULL)
	{
		cout<<cur->data;
	   if(cur->next != NULL)
		   cout<<"->";
	   cur=cur->next;
	}
	cout<<endl;
}

void del_node(ListNode*&head,ListNode*delnode)
{
   if(head == NULL || delnode == NULL)
	{
      return;
   }
   if(delnode->next == NULL)
	{
      ListNode *cur=head;
	  if(cur == delnode)//是头节点
		{
			head=cur->next;
	    }
		else//是尾节点
		{
	       while(cur->next != delnode)
	     {
	         cur=cur->next;
	     }
	      cur->next==NULL;
		}
	  delete delnode;
	  delnode=NULL;
    }
	else //不是头节点也不是尾节点
	{
	  delnode->data=delnode->next->data;
	  ListNode *tmp = delnode->next;
	  delnode->next = delnode->next->next;

	  delete tmp;
	  tmp=NULL;
	}
}


void test_12()
{

  ListNode *head =NULL;
  for(int i=0;i<10;++i)
  push_back(head,i);
    print(head);

  del_node(head,head);
  print(head);
}

int main()
{
  test_12();
return 0;
}