
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

#if 0
#define _C_DEBUG
#endif

/*suppose this structure is one of the state variables.*/
struct dummy
{
  dummy() = default;
  __int32_t one = 0xFFFFFFFF;
  __int32_t two = -1;
  __int32_t three = 1000;
};

dummy dummy_instance;

int main(int argc, const char** argv)
{
  std::ifstream wast_file;
  std::ofstream injectedfile;
  wast_file.open("./proto.wast");
  injectedfile.open("./injected.wast");

  std::string line;
  while(std::getline(wast_file, line))
  {
#if defined(_C_DEBUG)
    std::cout << line << "\n";
#endif

    if (line.find("(func $main (result") != std::string::npos)
    {
      injectedfile << "(syscall injected)" << "\n";
    }

    injectedfile << line << "\n";
  }

  auto dummy_address = &dummy_instance;
  auto dummy_length = sizeof(dummy_instance);

  __int32_t* struct_copy_begin;
  __int32_t destination[dummy_length];

  std::memcpy(destination, dummy_address, dummy_length);

  std::cout << "address: " << dummy_address << " size: " << dummy_length << "\n";
  std::cout << "Contents: " << "\n";

  for (unsigned int i = 0; i < dummy_length; ++i)
  {
    std::cout << std::hex << "0x" << *(destination + i) << "\n";
  }

std::cout << "\n\n";

  injectedfile.close();
  wast_file.close();

  return 0;
}
