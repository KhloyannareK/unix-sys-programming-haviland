#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 


int main()
{
   const char* command[] = {"/bin/sh", "sh", "-c", "ls -l", NULL};
   std::cerr << "in parent before fork\n";
   pid_t pid = fork();
   if(0 == pid) {
     std::cerr << "in child before execl\n";
     execl(command[0], command[1], command[2], command[3], NULL);
     return -1;
   }
   
   std::cerr << "In parent after fork - waiting for child\n";
   wait(0);
   std::cerr << "Child finished its job\n";

   return 0;
}
