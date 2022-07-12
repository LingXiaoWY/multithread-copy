/*=============================================================
# File Name: file_block.c
# Author: Guo Weiye
# Mail: guoweiyelai@qq.com
# Created Time: Mon 11 Jul 2022 11:38:23 AM CST
=============================================================*/
#include<thread_copy.h>

int file_block(const char* sfile,int thrnum)
{
	//打开文件获取大小
	int fd = open(sfile,O_RDONLY);
	int fsize = lseek(fd,0,SEEK_END);

	//计算任务量
	if(fsize%thrnum==0)return fsize/thrnum;
	else return fsize/thrnum + 1;
}
