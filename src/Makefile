.PHONY:clean install disclean

CC=gcc
CFLAGS=-I$(INCLUDE_PATH) -Wall -c -g
LDFLAGS=-lpthread
INCLUDE_PATH=../include
TARGET=thread_copy
RM=sudo rm -rf
CP=sudo cp
SFILE=$(wildcard *.c)
DFILE=$(patsubst %.c,%.o,$(SFILE))

$(TARGET):$(DFILE)#编译主目标
	$(CC) $^ -lpthread -o $@

%.o:%.c
	$(CC) $(CFLAGS) $<

clean:
	$(RM) $(DFILE) $(TARGET)

disclean:
	#卸载程序和删除配置文件

install:
	#拷贝安装到指定位置
