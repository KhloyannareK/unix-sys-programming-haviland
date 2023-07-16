#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

const char fileName[] = "fileForParallelWriting.txt";

void print(int fd, const char* expr, int sz)
{
   int ret = 0;
   for(int i = 0; i < 1000; ++i) {
      if(-1 == (ret = write(fd, expr, sz))) {
         perror("failed during write ");
         return;
      }
   }
}

int main()
{
   int d = open(fileName, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
   if(-1 == d) {
      perror("failed during open");
      return -1;
   }

   pid_t pid = fork();
   if(0 == pid) {
      print(d, " child ", 7); 
   }
   else { 
      print(d, " parent ", 8); 
   }
   close(d);
   return 0;
}
