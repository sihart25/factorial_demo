#include <iostream>
#include "Factorial.h"

void printInfo(std::string appname) {
  std::string hdr = std::string(FACTORIAL_HEADER);
  std::string vmaj = std::string(FACTORIAL_VERSION_MAJOR);
  std::string vmin = std::string(FACTORIAL_VERSION_MINOR);
  std::string vpat = std::string(FACTORIAL_VERSION_PATCH);

  std::cout << hdr << "\t"
            << " Version (" << vmaj << "." << vmin << "." << vpat << ")" << std::endl;
}
 
std::string getdatafolder(){
    std::string path;
    FACTORIAL_::cnst::currentWorkingDirectory(path); 
    path+="/data/"; 
    return path;
  
}


int main(int argc, char* argv[])
{   

    // ensure the correct number of parameters are used.
    if (argc < 3) {
      std::string use = std::string(FACTORIAL_USAGE);
      std::string desc = std::string(FACTORIAL_USAGE_DESC);
      std::cout << use << std::endl;
      std::cout << desc << std::endl;
      return 1;
    }

    printInfo(argv[0]);
    int numCalc = atoi(argv[1]);
    auto factorial = Factorial::GetFactorial(numCalc);
    std::cout << "The factorial of " << numCalc << " = " << factorial << std::endl;
    return 0;
}