#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <utility>
namespace blackframe::utils {

template <typename... Args> std::string BuildString(Args &&...args) {
  std::ostringstream stream;
  (stream << ... << std::forward<Args>(args));
  return stream.str();
}
void Write(std::ofstream &ffile, std::string messege);
void Open(std::string path);

}; // namespace blackframe::utils
