#pragma once
#include "include/core/utils/bfutils.hpp"
#include <utility>
#define BF_CORE_LOG_PATH "logs/core.log"
#define BF_LUA_LOG_PATH "logs/lua.log"
#define BF_GLFW_LOG_PATH "logs/glfw.log"
#define BF_VULKAN_LOG_PATH "logs/vulkan.log"
#define TRACE "[TRACE]"
#define INFO "[INFO]"
#define WARNING "[WARNING]"
#define ERROR "[ERROR]"
#define FATAL "[FATAL]"

enum class LogLevel {
  Trace,
  Info,
  Warning,
  Error,
  Fatal

};
enum class Outlet {
  Lua,
  Core,
  GLFW,
  Vulkan

};

namespace blackframe::log {

void InitilizeLogs();
template <Outlet ot> std::ofstream &GetStream();

template <LogLevel ll> void LogMsg(std::string &body);

template <Outlet ot, LogLevel ll, typename... Args> void Write(Args... args) {
  std::string body =
      blackframe::utils::BuildString(std::forward<Args>(args)...);
  LogMsg<ll>(body);

  blackframe::utils::Write(GetStream<ot>(), body);
}

}; // namespace blackframe::log
