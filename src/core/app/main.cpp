#include "include/core/logging/blackframelogs.hpp"
#include "include/core/window/GLFWcontext.hpp"
#include <iostream>
int main() {
  std::cout << "Hello game engine" << std::endl;

  blackframe::glfw::Context::GLFWContext window =
      blackframe::glfw::Context::GLFWContext("Blackframe engine", 10, 10);

  blackframe::log::InitilizeLogs();

  window.GLFW_Run();

  return 0;
}
