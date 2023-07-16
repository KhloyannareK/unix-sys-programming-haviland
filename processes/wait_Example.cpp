#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>



int main()
{
   std::cout << "before fork()\n";
   pid_t pid = fork();
   if(0 == pid) {
      for(int i = 0; i < 5; ++i) {
         std::cout << "slept for " << i << " seconds.\n";
         sleep(1);
      }
      exit(1); // just for fun return 1
   }
   
   int status = 0;
   if(-1 == (pid = wait(&status))) {
      perror("failed during wait");
      exit(-1);
   }
   
   std::cout << "child process with id: " << pid << " finished its job with status: " << status << std::endl; // actually the status is the most important 8 bits
   
   return 0;
}
