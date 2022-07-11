/*=============================================================
# File Name: pram.check.c
# Author: Guo Weiye
# Mail: guoweiyelai@qq.com
# Created Time: Mon 11 Jul 2022 11:42:58 AM CST
=============================================================*/
#include<thread_copy.h>

//./thread_copy xxx.jpg xxx.jpg 20
int pram_check(int argc,const char* sfile,int thrnum)
{
	if(argc<3){
		printf("ERROR:缺少必要参数，请重试!\n");
		exit(0);
	}
	if(access(sfile,F_OK)!=0){
		printf("ERROR:源文件不正确或不存在!\n");
		exit(0);
	}
	if(thrnum<=0||thrnum>100){
		printf("ERROR:进程数量不允许小于0并大于100!\n");
		exit(0);
	}
	return 0;
}
