#include <string>
#include <vector>
#include <iostream>
#include <sstream>


#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  for (int count = 0; count < 4; ++count)
  {
    list.push_back("test");
  }

  for (int count = 0; count < 4; ++count)
  {
    if (!list.empty()) {
      std::cout << list.get(0) << std::endl;
      list.pop_front();
    } else {
      std::cout << "List is empty." << std::endl;
    }
  }

  std::cout << "Size: " << list.size() << std::endl;
  std::cout << "Empty: " << list.empty() << std::endl;

  return 0;
  

  return 0;
}
