#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void HandleSignal(int signal)
{
   std::cout << "signal handler was called with signal number " << signal << std::endl;
   sleep(5); // to check wehter other signals are blocked and handled after this function - for example ctrl + Z
}

int main()
{
   static struct sigaction handlerInfo;
   sigfillset(&handlerInfo.sa_mask);
   handlerInfo.sa_handler = HandleSignal;
   sigaction(SIGINT, &handlerInfo, 0);
   
   sigset_t setOfBlockedSignals;
   sigfillset(&setOfBlockedSignals);
   std::cout << "start of critical code\n";
   sigprocmask(SIG_SETMASK, &setOfBlockedSignals, NULL);
   for(int i = 0; i < 10; ++i) {
      std::cout << i << "...\n";
      sleep(1);
   }
   sigprocmask(SIG_UNBLOCK, &setOfBlockedSignals, NULL);
   std::cout << "end of critical code\n";

   
   for(int i = 0; i < 10; ++i) {
      std::cout << "faking a job for " << i+1 << " seconds\n";
      sleep(1);
      if(4 == i) { 
        handlerInfo.sa_handler = SIG_IGN;
        sigaction(SIGINT, &handlerInfo, 0);
        std::cout << "Signal SIGINT will be ignored\n";
      }
      else if(7 == i) {
        handlerInfo.sa_handler = SIG_DFL;
        sigaction(SIGINT, &handlerInfo, 0);
        std::cout << "Signal SIGINT will not be ignored\n";
      }
   }

   return 0;
}
