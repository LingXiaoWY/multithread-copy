/*=============================================================
# File Name: thread_create.c
# Author: Guo Weiye
# Mail: guoweiyelai@qq.com
# Created Time: Mon 11 Jul 2022 11:48:52 AM CST
=============================================================*/
#include<thread_copy.h>

struct jpack
{
	const char*sfile,*dfile;
	int flag,blocksize;
};

void* jobs(void* arg)
{
	struct jpack* pjp = (struct jpack*)arg;
	int pos = pjp->flag*pjp->blocksize;
	char str_blocksize[50];
	char str_pos[50];
	bzero(str_blocksize,sizeof(str_blocksize));
	bzero(str_pos,sizeof(str_pos));
	sprintf(str_blocksize,"%d",pjp->blocksize);
	sprintf(str_pos,"%d",pos);
	printf("Copy thread tid 0x:%x Copy_Pos %d Copy_size %d\n",(unsigned int)pthread_self(),pos,pjp->blocksize);
	//通过重载方法使用copy功能
	//./copy sfile dfile blocksize pos
	execl("/home/guo/linuxHighLevel/Pthread/multithread_copy/module/copy","copy",pjp->sfile,pjp->dfile,str_blocksize,str_pos,NULL);//重载后覆盖
	return NULL;
}

int thread_create(const char* sfile,const char* dfile,int blocksize,int thrnum)
{
	pthread_t tid[110] = {0};
	int flag;
	struct jpack jp;
	jp.blocksize = blocksize;
	jp.dfile = dfile;
	jp.sfile = sfile;
	for(flag=0;flag<thrnum;flag++){
		jp.flag = flag;
		printf("flag=%d\n",flag);
		pthread_create(&tid[flag],NULL,jobs,(void*)&jp);
	}
	return 0;
}
