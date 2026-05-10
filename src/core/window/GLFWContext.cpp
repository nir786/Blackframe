
#include "include/core/window/GLFWcontext.hpp"

void blackframe::glfw::Context::GLFWContext::GLFW_Run() {
  glfwMakeContextCurrent(window);
  while (!glfwWindowShouldClose(window)) {

    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  }
}
