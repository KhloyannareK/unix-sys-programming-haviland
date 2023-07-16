#include <iostream>


int main(int argc, char** argv)
{
  std::cout << "Example program\n";
  while(argc) {
    --argc;
    std::cout << *(argv++) << ' ';
  }
  std::cout << std::endl;


   return 0;
}
