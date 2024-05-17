#include <iostream>
#include "Factorial.h"

void printInfo(std::string appname) {
  std::string hdr = std::string(LIBCNEAREST_HEADER);
  std::string vmaj = std::string(LIBCNEAREST_VERSION_MAJOR);
  std::string vmin = std::string(LIBCNEAREST_VERSION_MINOR);
  std::string vpat = std::string(LIBCNEAREST_VERSION_PATCH);

  std::cout << hdr << "\t"
            << " Version (" << vmaj << "." << vmin << "." << vpat << ")" << std::endl;
}
 
std::string getdatafolder(){
    std::string path;
    LibcNearest::cnst::currentWorkingDirectory(path); 
    path+="/data/"; 
    return path;
  
}


int main(int argc, char* argv[])
{   

  // ensure the correct number of parameters are used.
  if (argc < 3) {
    std::string use = std::string(LIBCNEAREST_USAGE);
    std::string desc = std::string(LIBCNEAREST_USAGE_DESC);
    std::cout << use << std::endl;
    std::cout << desc << std::endl;
    return 1;
  }

  printInfo(argv[0]);
  int n = atoi(argv[1]);
    auto factorial = Factorial::GetFactorial(n);
    std::cout << "The factorial of " << n << " = " << factorial << std::endl;    
    return 0;
}