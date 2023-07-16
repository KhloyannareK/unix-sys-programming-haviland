#include <iostream>
#include <sys/types.h>
#include <unistd.h>



int main()
{
   std::cout << "hello processes!\n";
   auto pid = fork();
   std::cout << "new process created - current process is: " << pid << std::endl; 



   return 0;
}
