/*************************************************************************
	> File Name: thread.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sat 17 Sep 2016 03:54:24 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<pthread.h>
#include<vector>
#include<algorithm>
#include<sys/types.h>
#include<semaphore.h>
#include<unistd.h>
using namespace std;
#include<string.h>
 


/*
pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;  //互斥锁
pthread_cond_t mycond = PTHREAD_COND_INITIALIZER;    //条件变量
int num=0;

void* thread_func(void *arg)
{
          int key = *(int*)arg;
          cout<<key<<endl;
	      pthread_mutex_lock(&mylock);

		  while(key != num)
		   {
		      pthread_cond_wait(&mycond,&mylock);
		   }
		   cout<<key<<endl;
		   num = (num+1)%3;
		   pthread_mutex_unlock(&mylock);
		   pthread_cond_broadcast(&mycond);

      return (void*)0;
}


int main()
{
    pthread_t tid[3];
    for(int i = 0; i < 3; i++)
        pthread_create(&tid[i], NULL, thread_func, (void *) &i);

    for(int i = 0; i < 3; i++)
        pthread_join(tid[i],NULL);
    return 0;
}
*/
/*
void* thirdFunc(void *arg)
{
    cout<<"A"<<endl;
}

void *secondFunc(void *arg)
{
   pthread_t id3;
   pthread_create(&id3,NULL,&thirdFunc,NULL);
    pthread_join(id3,NULL);
	cout<<"B"<<endl;
	return NULL;
}

void* firstFunc(void *arg)
{
	pthread_t id2;
   pthread_create(&id2,NULL,&secondFunc,NULL);
   pthread_join(id2,NULL);
          cout<<"C"<<endl;
  return NULL;
}


int main()
{
    pthread_t id1;
    pthread_create(&id1,NULL,&firstFunc,NULL);
    pthread_join(id1,NULL);
}
*/
/*

sem_t sem1;
sem_t sem2;
sem_t sem3;

void* func1(void *)
{
  sem_wait(&sem1);
  cout<<"A"<<endl;
  sem_post(&sem2);
}

void* func2(void *)
{
  sem_wait(&sem2);
  cout<<"B"<<endl;
  sem_post(&sem3);
}
void* func3(void *)
{
  sem_wait(&sem3);
  cout<<"C"<<endl;
  sem_post(&sem1);
}


int main()
{
   sem_init(&sem1,0,1); //信号量一个
   sem_init(&sem2,0,0);
   sem_init(&sem3,0,0);

     pthread_t tid[3];

     pthread_create(&tid[0], NULL, func1, NULL);
	 pthread_create(&tid[1], NULL, func2, NULL);
	 pthread_create(&tid[2], NULL, func3, NULL);

     for(int i = 0; i < 3; i++)
     pthread_join(tid[i],NULL);

}
*/