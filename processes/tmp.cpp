#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <ulimit.h>


int main(int argc, char **argv, char **envp)
{
   nice(2);
   std::cout << "file max size " << ulimit(UL_GETFSIZE, 0) << std::endl;
   while(*envp) {
     std::cout << *(envp++) << std::endl;
   }
   const char* getResult = getenv("PWD");
   std::cout << "PWD = " << (getResult ? getResult : "NULL");
   pid_t pid = getpid();
   pid_t pgrp = getpgrp();
   pid_t p = fork();
   if(0 == p) {
      std::cout << getpgrp() << ' ' << getsid(0) << std::endl;
      return -1;
    }
   std::cout << pid << ' ' << pgrp << ' ' << getsid(0) << std::endl;   
 
   return 0;
}
