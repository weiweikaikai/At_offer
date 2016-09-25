#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<deque>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<hash_set>
#include<string.h>
using namespace std;



int leftTopToRightbottom(int (&vec)[4][4])
{

     int (*p)[4] = new int[4][4];

     for(int i=0;i<4;++i)
	 {
	   for(int j=0;j<4;++j)
	   {
	     if(i == 0 && j==0)
		   {
		     p[i][j] += vec[i][j];
		   }
		  else if(i==0 && j>0) //往右边走
		   {
		     p[i][j] = p[i][j-1] + vec[i][j];
		   }
		   else if(i>0 && j==0)//往下面走
		   {
		     p[i][j]=p[i-1][j]+vec[i][j];
		   }
		   else
		   {
		     p[i][j] =(p[i-1][j] > p[i][j-1] ?p[i-1][j]:p[i][j-1] )+vec[i][j];
		   }

	   }
	 
	 }
	 return p[3][3];
}


void test_leftTopToRightbottom()
{

      int arr[4][4]={
	  
		  {1,10,3,8},
		  {12,2,9,6},
		  {5,7,4,11},
		  {3,7,16,5}
	  };

	  cout<<leftTopToRightbottom(arr)<<endl;

}


/*
 已知某次聚会共有N个人参加，这N个人来自26个不同的地区，先将26个地区用a-z进行表示，
 * 使用整数数组Location存储这N个人的地区，请返回一个boolean类型的变量
 * true代表所有人的地区都不一样，false代表存在一样地区的人。
*/

//分析：首先地区是有限的，可以采用空间换时间进行
bool MyLocation(vector<char>&vec)
{
   if(vec.size() == 0)
   {
       return false;
   }
   vector<int> tmp(26,0);
   for(int i=0;i<tmp.size();++i)
   {
          if((++tmp[vec[i]]) == 2)
	      {
		     return false;
		  }
   }
   return true;
}

void test_Location()
{
   char arr[27]="abcdefghijklmnopqrstuvwxyz";

   vector<char> vec(arr,arr+26);

cout<<MyLocation(vec)<<endl;
}



//判断一个整形数组中是否存在三个元素的和为0
bool SumIsZero(vector<int> &vec,int sum,int r,int key)
{
   if(vec.size() <3)
	{
      return false; 
    }
    
	int left = 0;
	int right = r-1;
	int tmp=0;
	while(left < right)
	{
	   tmp = vec[left] + vec[right];
	   if((sum +tmp) == key)
		{
	         cout<<vec[r]<<" "<<vec[left]<<" "<<vec[right]<<endl;
			 return true;
	    }
		if((sum+tmp) > key)
		{
		   right--;
		}
		if((sum + tmp) <key)
		{
		   left++;
		}
	}


}


void test_sumIszero()
{

int arr[10]={1,2,-3,8,4,5,6,7,8,9};

vector<int> vec(arr,arr+9);
sort(vec.begin(),vec.end());
for(int i=9;i>=2;--i)
{
   SumIsZero(vec,vec[i],i,15);
}

}
//一个数组中所有元素都出现了三次，至于一个数字出现了1次，找出这个数字

void Find_Nums(vector<int> &vec)
{
   if(vec.size () == 0)
	{
     return;
    }
    int size = (int)vec.size();
	vector<int> tmp(100,0);
	for(int i=0;i<size;++i)
	{
	    tmp[vec[i]]++;
	}
    for(int i=0;i<tmp.size();++i)
	{
        if(tmp[i] == 1)
		{
		   cout<<i<<endl;
		}
    }

}


size_t  Count_One(int value)
{
   size_t count=0;

   while(value)
	{
      value &= (value-1);
	  count++;
    }
	return count;
}

void Find_Nums_2(vector<int> &vec)
{
   if(vec.size() == 0)
	{
       return;
    }
      size_t sum=0;
	for(int i=0;i<vec.size(); ++i)
	 {
	   sum =sum+Count_One(vec[i]);     
	 }
	 size_t value = sum%3;
	 for(int i=0;i<vec.size();++i)
	{
	    if(Count_One(vec[i]) == value)
		{
		  cout<<vec[i]<<endl;
		  return ;
		}
	 }
}
void test_Find_Num()
{
      int arr[10]={1,2,2,2,3,3,3,4,4,4};

      vector<int> vec(arr,arr+10);
    //Find_Nums(vec);
	Find_Nums_2(vec);
}

class Mystring
{
  public:
	  Mystring(char *str="")
	  {
         if(str == NULL)
		  {
		    data = new char[1];
			data[0]='\0';
		  }
		  else
		  {
		     data=new char[strlen(str)+1];
              strcpy(data,str);
		  }
      }
       Mystring(const Mystring &str)
	   {
		   data = new char[strlen(str.data)];
	       strcpy(data,str.data);
	   }
       Mystring&operator=(const Mystring &str)
	   {
	        if(this != &str)
		     {
			     Mystring tmp(str.data);
				 swap(data,tmp.data);
			 }
			  return *this;
	   }
	   ~Mystring()
	  {
	     if(data != NULL)
		  {
		   delete []data;
		  }
	   }
	   void print()
    	{
	      cout<<data<<endl;  
	    }
	  private:
		  char *data;
};

void test_string()
{
    Mystring str0("");
	Mystring str1(NULL);
    Mystring str2("hello");
    str2.print();
	 str1=str2;
      str1.print();
}

//1.有序二维数组中查找数字 最好O(1) 最坏 O(m+n)
int  Find(int *arr, int rows,int colums,int x)
{
	if (arr == NULL || rows <0 || colums < 0)
	{
		return -1;
	}
	int prow =0;
	int pcol = colums - 1;

	while (prow <rows && pcol >= 0)
	{
		if (arr[prow * colums + pcol] > x)
		{
			pcol--;
		}
		else if (arr[prow *colums + pcol] < x)
		{
			prow++;
		}
		else if (arr[prow *colums + pcol] == x)
		{
			return arr[prow *colums + pcol];
		}
		else
		{
			return -1;
		}
	}
}
void test_1()
{
	int arr[][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	std::cout << Find((int*)arr, 4, 4, 7) << std::endl;
	std::cout << Find((int*)arr, 4, 4, 1) << std::endl;
	std::cout << Find((int*)arr, 4, 4, 15) << std::endl;
	std::cout << Find(NULL, 4, 4, 7) << std::endl;
}

//2.替换字符串中的空格为%20   O(n)
void Replace_Blank(char* dest,int length)
{
	if (dest == NULL || length <=0 )
	{
		return;
	}
	int old_len = 0;
	int num_blank = 0;
	int i = 0;
	while (dest[i] != '\0')
	{
		if (dest[i] == ' ')
		{
			++num_blank;
		}
		++old_len;
		++i;
	}
	int new_len = old_len + num_blank * 2;
	if (new_len > length)
	{
		return;
	}
	int new_cur = new_len;
	int old_cur = old_len;

	while (old_cur >= 0)
	{
		if (dest[old_cur] == ' ')
		{
			dest[new_cur--] = '0';
			dest[new_cur--] = '2';
			dest[new_cur--] = '%';
		}
		else
		{
			dest[new_cur--] = dest[old_cur];
		}
		old_cur--;
	}
}
void test_2()
{
	char str[30] = "I am a boy";
	Replace_Blank(str,30);
	//Replace_Blank(NULL, 30);
	//Replace_Blank(str, 10);
	std::cout << str << std::endl;
}
//3.从尾到头打印链表
typedef struct node
{
	int data;
	struct node *next;
}*Lnode,node;

void push_back(Lnode &phead, int val)
{
	if (phead == NULL)
	{
		phead = new node;
		phead->data = val;
		phead->next = NULL;
	}
	else
	{
		Lnode cur = phead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		Lnode tmp = new node;
		tmp->data = val;
		tmp->next = cur->next;
		cur->next = tmp;
	}
}
void Show_List(Lnode phead)
{
	if (phead == NULL)
	{
		return;
	}
	Lnode cur = phead;
	while (cur != NULL)
	{
	std::cout << cur->data << " ";
	cur = cur->next;
	}
	std::cout << std::endl;
}
void Print_List_By_back(Lnode phead)
{
	if (phead == NULL)
	{
		return;
	}
	std::stack<Lnode> st_node;
	Lnode cur = phead;
	while (cur != NULL)
	{
		st_node.push(cur);
		cur = cur->next;
	}
	while (!st_node.empty())
	{
		cur = st_node.top();
		std::cout << cur->data << " ";
		st_node.pop();
	}
	std::cout << std::endl;
}
void Print_List_By_back_2(Lnode phead)
{
	if (phead == NULL)
	{
		return;
	}
	Lnode cur = phead;
	if (cur->next != NULL)
	{
		Print_List_By_back_2(cur->next);
	}
	std::cout << cur->data << " ";
}

Lnode insertionSortList(Lnode head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Lnode pre = head;
	Lnode cur = head->next;
	pre->next = NULL;
	Lnode nxt = NULL;

	while (cur != NULL)
	{
		nxt = cur->next;
		Lnode tmp = head;
		if (tmp->data > cur->data)
		{
			cur->next = tmp;
			head = cur;
			cur = nxt;
			continue;
		}
		while (tmp->next != NULL && tmp->next->data <cur->data)
		{
			tmp = tmp->next;
		}

		cur->next = tmp->next;
		tmp->next = cur;
		cur = nxt;
	}
	return head;
}


void test_3()
{
	Lnode head = NULL;
	for (int i = 10; i>=0;--i)
	push_back(head, i);
	Show_List(head);
	//insertionSortList(head);
	Show_List(insertionSortList(head));
	//Print_List_By_back(head);
	//Print_List_By_back_2(head);
}

//4.二叉树还原
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//前序 和中序还原
 struct TreeNode * ReconstructBinTreeBy_Pre_In(std::vector<int> pre, std::vector<int>in)
 {
	 if (pre.size() == 0 || in.size() == 0)
	 {
		 return NULL;
	 }
	 std::vector<int> pre_left;
	 std::vector<int> in_left;

	 std::vector<int> pre_right;
	 std::vector<int> in_right;

	 int val = pre[0];
	 struct TreeNode *node = new TreeNode(val); //根节点建立
	 std::vector<int>::size_type offset = 0;
	 for (std::vector<int>::size_type i = 0; i < in.size(); ++i)
	 {
		 if (in[i] == val)
		 {
			 offset = i;
			 break;
		 }
	 }
	 for (std::vector<int>::size_type i = 0; i < pre.size(); ++i)
	 {
		 if (i < offset)
		 {
			 pre_left.push_back(pre[i + 1]); //左子树的前序
			 in_left.push_back(in[i]); //左子树的中序

		 }
		 if (i>offset)
		 {
			 pre_right.push_back(pre[i]); //右子树的前序
			 in_right.push_back(pre[i]);//右子树的中序
		 }
	 }

	 node->left = ReconstructBinTreeBy_Pre_In(pre_left, in_left);
	 node->right = ReconstructBinTreeBy_Pre_In(pre_right, in_right);
	 return node;
 }
 // 中序和后序还原
 struct TreeNode * ReconstructBinTreeBy_In_post(std::vector<int> in, std::vector<int>post)
 {
	 if (in.size() == 0 || post.size() == 0)
	 {
		 return NULL;
	 }
	 std::vector<int> in_left;
	 std::vector<int> in_right;
	 std::vector<int> post_left;
	 std::vector<int> post_right;

	 int val = post[post.size() - 1];
	 struct TreeNode*node = new TreeNode(val);

	 int offset = 0;
	 for (int i = 0; i < (int)in.size(); ++i)
	 {
		 if (in[i] == val)
		 {
			 offset = i;
			 break;
		 }
	 }
	 for (int i = 0; i < (int)in.size(); ++i)
	 {
		 if (i < offset)
		 {
			 in_left.push_back(in[i]);
			 post_left.push_back(post[i]);
		 }
		 if (i>offset)
		 {
			 in_right.push_back(in[i]);
			 post_right.push_back(post[i]);
		 }
	 }
	 ReconstructBinTreeBy_In_post(in_left, post_left);
	 ReconstructBinTreeBy_In_post(in_right, post_right);
	 return node;
 }
void test_4()
 {
 char pre_arr[]="12473568";
 char in_arr[]="47215386";
 char post_arr[]="47258631";
 }

//5.全排列
void Permutations(char *p ,int l, int r)
{
	if (p== NULL)
	{
		return;
	}
	if (l == r)
	{
		for (int j = 0; j <r; ++j)
		{
			std::cout << p[j] << " ";
			
		}
		std::cout << "\n";
	}
	else
	{
		for (int i = l; i < r; ++i)
		{
			std::swap(p[l], p[i]);
			Permutations(p, l + 1, r);
			std::swap(p[l], p[i]);
		}
	}
}


void test_5(void) 
{
	char arr[] = "01235";
	Permutations(arr, 0,5); //排列的个数是数字个数的阶乘这里是5！
}

int main()
{
	//test_1();
//	test_string();
//test_sumIszero();
//test_Find_Num();
//test_Location();
test_leftTopToRightbottom();
    return 0;
}




