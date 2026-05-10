#include "include/core/logging/blackframelogs.hpp"
#include <fstream>

namespace blackframe::log {
static std::ofstream core_log;
static std::ofstream lua_log;
static std::ofstream glfw_log;
static std::ofstream vulkan_log;
void InitilizeLogs() {
  core_log.open(BF_CORE_LOG_PATH);
  lua_log.open(BF_LUA_LOG_PATH);
  glfw_log.open(BF_GLFW_LOG_PATH);
  vulkan_log.open(BF_VULKAN_LOG_PATH);
}

template <> std::ofstream &GetStream<Outlet::Lua>() { return lua_log; }
template <> std::ofstream &GetStream<Outlet::Core>() { return core_log; }
template <> std::ofstream &GetStream<Outlet::GLFW>() { return glfw_log; }
template <> std::ofstream &GetStream<Outlet::Vulkan>() { return vulkan_log; }
template <> void LogMsg<LogLevel::Trace>(std::string &str) {
  str = TRACE + str;
}
template <> void LogMsg<LogLevel::Info>(std::string &str) { str = INFO + str; }
template <> void LogMsg<LogLevel::Warning>(std::string &str) {
  str = WARNING + str;
}
template <> void LogMsg<LogLevel::Error>(std::string &str) {
  str = ERROR + str;
}
template <> void LogMsg<LogLevel::Fatal>(std::string &str) {
  str = FATAL + str;
}
}; // namespace blackframe::log
