#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv) 
{
  if(argc < 3) {
     std::cerr << "command file commandToExec\n";
     return -1;
  }

  struct stat fileInfo;
  char* fileName = argv[1];
  int ret = stat(fileName, &fileInfo);
  if(ret != 0) {
    std::cerr << "there is no access to the file: " << fileName << std::endl;
    return -1;
  }

  time_t start_size = fileInfo.st_size;
  time_t current_size = start_size;
  while(current_size == start_size) {
     ret = stat(fileName, &fileInfo);
     if(ret != 0) {
       std::cerr << "there is no access to the file: " << fileName << std::endl;
       return -1;
     }
     current_size = fileInfo.st_size;
     std::cout << current_size << std::endl;
     std::cout << "file is not changed yet\n";
     sleep(3);
  }
  std::cout << "File is modified - executing command: " << argv[2] << std::endl;

  execl(argv[2], argv[2], NULL); 
  std::cerr << "call to execl failed\n";

  return 0;
}
