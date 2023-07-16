#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
   pid_t pid = fork();
   if(0 == pid) {
      for(int i = 0; i < 5; ++i) {
         std::cout << "...\n";
         sleep(1);
      }
      abort();
   }
  
   int status = 0, sig_no = 0;
   wait(&status);
   if(WIFSIGNALED(status))
   {
     sig_no = WTERMSIG(status);
     std::cerr << "child got signal " << sig_no << std::endl;
     if(WCOREDUMP(status)) {
        std::cerr << "core file was created\n";
     }
   }
  

   return 0;
}
