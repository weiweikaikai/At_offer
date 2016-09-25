/*************************************************************************
	> File Name: 36-40.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Mon 25 Jul 2016 11:09:06 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//36数组中的逆序对
static int Mytimes=0;

void merge(vector<int>&vec,int left,int mid,int right,vector<int>&newvec)
{
   int l=left;
   int r=mid+1;
   int i=0;
   while(l<=mid && r<=right)
	{
      if(vec[l] < vec[r])
		{
	      newvec[i++]=vec[l++];
	    }
		else
		{
			Mytimes++;
		  newvec[i++]=vec[r++];
		}
    }
	while(l<=mid)
	{
	  newvec[i++]=vec[l++];
	}
	while(r<=right)
	{
	 newvec[i++]=vec[r++];
	}
    for(int j=0;j<i;++j)
	 {
		vec[left+j]=newvec[j];
	}

}

void mergesort(vector<int>&vec,int left,int right,vector<int>&newvec)
{
     if(left < right)
	 {
	    int mid = left +((right-left)>>1);
        mergesort(vec,left,mid,newvec);
		mergesort(vec,mid+1,right,newvec);
        merge(vec,left,mid,right,newvec);
	 }
}


void InversPairs(vector<int> &vec)
{
   if(vec.size() <2)
	{
     return ;
    }
	int length = vec.size();
	vector<int> newvec(length);
	mergesort(vec,0,length-1,newvec);
}

void test_36()
{
   vector<int> arr;
   arr.push_back(7);
   arr.push_back(5);
   arr.push_back(6);
   arr.push_back(4);

    for(int i=0;i<4;++i)
    {
        cout<<arr[i]<<" ";
    }
	cout<<endl;
    InversPairs(arr);
    for(int i=0;i<4;++i)
    {
        cout<<arr[i]<<" ";
    }
	cout<<endl;
	cout<<"times is "<<Mytimes<<endl;
}

//38.计算一个数字在排序数组中出现的次数

int  NumExistTimes(vector<int>&vec,int key)
{
   if(vec.size() ==0 )
	{
     return -1;
    }
    int left = 0;
	int right = vec.size()-1;
	int length =vec.size();
     int middle=0;
	 int start=0;
	 int end=0;
	while(left <=right)
	{
		middle = left+((right-left)>>1);
	    if(vec[middle] > key)
		{
		 right=middle-1;
		}
		else if(vec[middle] <key)
		{
		  left=middle+1; 
		}
		else
		{
		   if(middle >0 && vec[middle-1] != key) //是第一个
			{
			 start=middle;
			 while(middle<=length-1 && vec[middle] == key)
				{
                   ++middle;
			    }
				end=middle;
			}
			else if(middle < length-1 && vec[middle+1] != key)//是最后一个
			{
			      end =middle;
			    while(middle>=0 && vec[middle] == key)
				{
                   --middle;
			    }
				start=middle; 
			}
			else
			{
				int cur =middle;
			    while(cur<=length-1 && vec[cur] == key)
				{
                   ++cur;
			    }
				end=cur;
                while(middle>=0 && vec[middle] == key)
				{
                   --middle;
			    }
				start=middle; 
			} 
			int times= end-start-1;
			if(times == 0)
			{
			 return 1;
			}
			return times;
		}
	}
		
		return -1;
}

void test_38()
{
   vector<int> vec;
   vec.push_back(1);
   vec.push_back(3);
   vec.push_back(3);
   vec.push_back(3);
   vec.push_back(3);
   vec.push_back(3);
   vec.push_back(3);
   vec.push_back(3);
  cout<<NumExistTimes(vec,3)<<endl;
   cout<<NumExistTimes(vec,1)<<endl;
    cout<<NumExistTimes(vec,5)<<endl;
   cout<<NumExistTimes(vec,10)<<endl;

}
////39.二叉树的深度
//int TreeDepth(BinaryTreeNode* proot)
//{
//  if(proot == NULL)
//	{
//      return 0;
//    }
//	int nleft = TreeDepth(proot->m_pleft);
//	int nright = TreeDepth(proot->m_pright);
//
//    return (nleft > nright) ?(nleft +1):(nright +1);
//}
//bool IsBalanced(BinaryTreeNode * proot)
//{
//    if(proot == NULL)
//	{
//	   return true;
//	}
//	int left = TreeDepth(proot->m_pleft);
//	int right = TreeDepth(proot->m_pright);
//	int pos = right-left;
//	if(pos > 1 || pos <-1)
//	{
//	   return false;
//	}
//	return IsBalanced(proot->m_pleft) && IsBalanced(proot->m_pright);
//}
//
////上边的代码对有些节点遍历了多次
////可以使用后续遍历，可以在遍历到根节点的时候将已经变量过的左右子树的深度记录一下
//bool IsBalanced (BinaryTreeNode * proot,int* pdepth) 
//{
//   if(proot == NULL)
//	{
//      *pdepth =0;
//	  return true;
//    }
//	int left=0;
//	int right=0;
//    
//	if(IsBalanced(proot->m_pleft,&left)&& IsBalanced(proot->m_pRight,&right))
//	{
//	   int pos = left-right;
//	   if(pos <=1 || pos >=-1)
//		{
//          *pdepth= 1 + (left > right ? left : right);
//	       return true;
//	   }
//	}
//	return false;
//}
//40数组中只出现一次的数字
unsigned int FindFirstBitIs1(int value)
{
      int count=0;
      while(((value &1) == 0) && (count<8*sizeof(int)))
	   {
	       value = value>>1;
		   ++count;
	   }
	   return count;
}
bool IsBit1(int value,int index)
{
   value >>= index;
   return (value & 1);
}
void FindNumsAppearOnce(vector<int>&vec,int *num1,int *num2)
{
   if(vec.size() <2)
	{
     return ;
    }
	int length=vec.size();
	int result=0;
    for(int i=0;i<length;++i)
	{
        result ^=vec[i];	   
	}
    
	unsigned int count=FindFirstBitIs1(result);

    *num1 = *num2=0;
	for(int j=0;j<length;++j)
	{
	   if(IsBit1(vec[j],count))
		{
	      *num1 ^= vec[j];
	    }
		else
		{
		  *num2 ^= vec[j];
		}
	}
}
void test_40()
{
   vector<int> vec;
   vec.push_back(2);
   vec.push_back(4);
   vec.push_back(3);
   vec.push_back(6);
   vec.push_back(3);
   vec.push_back(2);
   vec.push_back(5);
   vec.push_back(5);
   int num1=0;
   int num2=0;
   FindNumsAppearOnce(vec,&num1,&num2);
   cout<<num1<<" "<<num2<<endl;
}


int main()
{
	test_36();
	//test_38();
	//test_40();

    return 0;
}

