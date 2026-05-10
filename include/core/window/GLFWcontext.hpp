#pragma once
#include "include/core/logging/blackframelogs.hpp"
#include <GLFW/glfw3.h>
#include <string>

class GLFWContext {
private:
  GLFWwindow *window;

public:
  GLFWContext(std::string name, int w, int h) {
    if (!glfwInit()) {
      blackframe::log::Write<Outlet::GLFW, LogLevel::Fatal>(
          "Failed to initialize GLFW");
      exit(-1);
    }

    // WHEN VULKAN CONTEXT SOUPORTED glfwWindowHint(GLFW_CLIENT_API,
    // GLFW_NO_API);
    window = glfwCreateWindow(w, h, name.c_str(), nullptr, nullptr);

    if (!window) {
      blackframe::log::Write<Outlet::GLFW, LogLevel::Fatal>(
          "Failed to initialize GLFW");

      glfwTerminate();
      exit(-1);
    }
    blackframe::log::Write<Outlet::GLFW, LogLevel::Info>(
        "GLFW Initialized secsefully");
  }

  ~GLFWContext() {
    glfwDestroyWindow(window);
    glfwTerminate();
    blackframe::log::Write<Outlet::GLFW, LogLevel::Info>(
        "GLFW terminated secsefully");
  }
  void GLFW_Run();
};
