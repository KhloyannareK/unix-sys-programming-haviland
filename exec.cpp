#include <iostream>

#include <unistd.h>


int main()
{
  std::cout << "In current code\n";
  execl("/home/narekmeta/learning/haviland/process/example_prog.out", "example program", "arg1", NULL);

  return 0;
}
