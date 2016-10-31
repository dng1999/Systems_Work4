#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

void getFileSize(struct stat buf){
  printf("File Size: ");
  int size = (int)buf.st_size; //in byte
  if (size > 1000000000){
    printf("%d GB\n", size/1000000000);
  }
  if (size > 1000000){
    printf("%d MB\n", size/100000);
  }
  if (size > 1000){
    printf("%d KB\n", size/1000);
  }
  printf("%d B\n", size);
}

void getMode(struct stat buf){
  printf("Mode: %o\n",(unsigned int)buf.st_mode&(S_IRWXU|S_IRWXG|S_IRWXO));
}

void getTimeofAccess(struct stat buf){
  printf("Time of Last Access: %s\n",ctime(&buf.st_atime));
}

void getLLMode(struct stat buf){
  printf("(ls -l)Mode: ");
  int mode = buf.st_mode;
  int i = 0;
  if (mode & S_IRUSR){
    printf("r");
  }
  else{
    printf("-");
  }

  if (mode & S_IWUSR){
      printf("w");
  }
  else{
    printf("-");
  }

  if (mode & S_IXUSR){
    printf("x");
  }
  else{
    printf("-");
  }
  if (mode & S_IRGRP){
    printf("r");
  }
  else{
    printf("-");
  }

  if (mode & S_IWGRP){
    printf("w");
  }
  else{
    printf("-");
  }

  if (mode & S_IXGRP){
    printf("x");
  }
  else{
    printf("-");
  }
  if (mode & S_IROTH){
    printf("r");
  }
  else{
    printf("-");
  }

  if (mode & S_IWOTH){
    printf("w");
  }
  else{
    printf("-");
  }

  if (mode & S_IXOTH){
    printf("x");
  }
  else{
    printf("-");
  }
  printf("\n");
}

int main(){
  struct stat buf;
  stat("README.md",&buf);
  getFileSize(buf);
  getMode(buf);
  getLLMode(buf);
  getTimeofAccess(buf);
  return 0;
}
