/*=============================================================
# File Name: thread_create.c
# Author: Guo Weiye
# Mail: guoweiyelai@qq.com
# Created Time: Mon 11 Jul 2022 11:48:52 AM CST
=============================================================*/
#include<thread_copy.h>

pthread_rwlock_t lock;

struct jpack
{
	const char*sfile,*dfile;
	int pos,blocksize;
};

void* jobs(void* arg)
{
	pthread_rwlock_wrlock(&lock);
	struct jpack* pjp = (struct jpack*)arg;
	printf("Copy thread tid 0x:%x Copy_Pos %d Copy_size %d\n",(unsigned int)pthread_self(),pjp->pos,pjp->blocksize);	
	copy(pjp->sfile,pjp->dfile,pjp->blocksize,pjp->pos);
	pthread_rwlock_unlock(&lock);
	return NULL;
}

int thread_create(const char* sfile,const char* dfile,int blocksize,int thrnum)
{
	pthread_rwlock_init(&lock,NULL);
	pthread_t tid[110] = {0};
	int flag;
	int ret;
	struct jpack jp;
	void* result = NULL;
	jp.blocksize = blocksize;
	jp.dfile = dfile;
	jp.sfile = sfile;
	for(flag=0;flag<thrnum;flag++){
		jp.pos = flag * blocksize;
		//printf("blocksize = %d,flag=%d\n",blocksize,flag);
		ret = pthread_create(&tid[flag],NULL,jobs,(void*)&jp);
		if(ret)printf("thread create failed:%s\n",strerror(ret));
		usleep(1000);
	}
	//手动回收
	for(flag=0;flag<thrnum;flag++){
		pthread_cancel(tid[flag]);
		if(pthread_join(tid[flag],&result)==0){
			printf("join success!\n");
		}
	}
	printf("main thread join end...\n");
	pthread_rwlock_destroy(&lock);
	return 0;
}
