#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void parentHandler(int s)
{
    std::cout << "parent got signal number " << s << std::endl;
}

void childHandler(int s)
{
    std::cout << "child got signal number " << s << std::endl;
}


int main()
{
   struct sigaction pact{}, cact{};
   pact.sa_handler = parentHandler;
   cact.sa_handler = childHandler;


   pid_t pid, ppid;
   pid = fork();
   if(0 == pid) {
      ppid = getppid();
      sigaction(SIGUSR1, &cact, 0);
      while(true) {
         sleep(1);
         kill(ppid, SIGUSR1);
         pause();
      }
   }
   else {
      sigaction(SIGUSR1, &pact, 0);
      while(true) {
        sleep(1);
        kill(pid, SIGUSR1);
        pause();
      }
   }
   
   return 0;
}
