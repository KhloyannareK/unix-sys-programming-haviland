#include <iostream>
#include <sys/types.h>
#include <unistd.h>



int main()
{
   std::cout << "hello processes!\n";
   auto pid_0_1 = fork();
   if(0 != pid_0_1) {
      std::cout << "pid_0_1: " << pid_0_1 << std::endl;
      auto pid_0_2 = fork();
      if(0 != pid_0_2) {
          std::cout << "pid_0_2: " << pid_0_2 << std::endl;
      }
      else {
         auto pid_0_2_1 = fork();
         if(0 != pid_0_2_1) {
            std::cout << "pid_0_2_1: " << pid_0_2_1 << std::endl;
         }
      }
   }
   else {
      auto pid_0_1_1 = fork();
      if(0 != pid_0_1_1) {
         std::cout << "pid_0_1_1: " << pid_0_1_1 << std::endl;
      }
   }
   std::cout << "all processes come to this point\n";

   return 0;
}
