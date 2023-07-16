#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>



int main()
{
   std::cout << "In parent before fork\n";
   pid_t pid = fork();
   if(-1 == pid) {
      perror("failed during fork");
      exit(-1);
   }
   if(0 == pid) {
      std::cout << "In child\n";
      for(int i = 1; i < 6; ++i) {
         sleep(1);
         std::cout << "slept for " << i << " seconds.\n";
      }
      exit(1); // returning 1 just for fun
   }
   
   int status, ret;
   while(0 == (ret = waitpid(pid, &status, WNOHANG))) {
      std::cout << "still waiting for child to finish\n";
      sleep(1);
   }
   if(-1 == ret) {
      perror("failed during waitpid");
      exit(-2);
   }
   std::cout << "Child process with id " << pid << " finished its job with status " << status << std::endl;

   return 0;
}
