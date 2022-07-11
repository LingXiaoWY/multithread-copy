#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

int pram_check(int argc,const char* sfile,int thrnum);

int file_block(const char* sfile,int thrnum);

int thread_create(const char* sfile,const char* dfile,int blocksize,int thrnum);

void copy(const char* sfile,const char*dfile,int blocksize,int pos);

