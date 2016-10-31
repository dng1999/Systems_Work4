#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
/*
int getFileSize(struct stat buf){ //in bytes
return (int)buf.st_size;
}

int getMode(struct stat buf){
return (int)buf.st_mode;
}

int getTimeofAccess(struct stat buf){
return ctime(&buf.st_atime);
}

int getLLMode(struct stat buf){

}
*/
int main(){
  struct stat buf;
  stat("10_25_16.c",&buf);
  printf("File Size: %d B\n",(int)buf.st_size);
  printf("Mode: %o\n",(unsigned int)buf.st_mode);
  printf("Time of Last Access: %s\n",ctime(&buf.st_atime));
  return 0;
}
