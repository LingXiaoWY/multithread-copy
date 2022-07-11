#include<thread_copy.h>

void copy(const char* sfile,const char*dfile,int blocksize,int pos)
{
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));
	ssize_t readlen;
	int sfd = open(sfile,O_RDONLY);
	int dfd = open(dfile,O_RDWR|O_CREAT,0664);
	//修改偏移量
	lseek(sfd,pos,SEEK_SET);
	lseek(dfd,pos,SEEK_SET);
	//拷贝读写
	readlen = read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,readlen);
	close(sfd);
	close(dfd);
}
