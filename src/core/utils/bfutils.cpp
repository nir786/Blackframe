#include "include/core/utils/bfutils.hpp"
#include <fstream>
#include <iostream>

namespace blackframe::utils {

void Write(std::ofstream &ffile, std::string body) {

  ffile << body << std::endl;
}
}; // namespace blackframe::utils
