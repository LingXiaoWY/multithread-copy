#include<thread_copy.h>

int main(int argc,char** argv)
{

	int thrnum;
	if(argv[3]==0)thrnum = 3;
	else thrnum = atoi(argv[3]);
	//参数校验
	pram_check(argc,argv[1],thrnum);
	//任务量计算
	int blocksize = file_block(argv[1],thrnum);
	//线程创建
	thread_create(argv[1],argv[2],blocksize,thrnum);
	return 0;
}
