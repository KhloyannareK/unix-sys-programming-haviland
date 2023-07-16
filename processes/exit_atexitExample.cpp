#include <iostream>
#include <stdlib.h>
#include <unistd.h>

void bye()
{
  std::cout << "function that is called upon exit() - registered by atext\n";
}

int main()
{
   if(-1 == atexit(bye)) {
      perror("failed during atexit");
      exit(-1);
   }
   
   std::cout << "before termination\n";
   exit(0);
}
