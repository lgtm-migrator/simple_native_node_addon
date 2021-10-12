#include <napi.h>
#include <iostream>
#include "boost/format.hpp"
#include "logger.h"
#include "memory"

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::cout <<  boost::format("writing %1%,  x=%2% : %3%-th try") % "toto" % 40.23 % 50;
  auto logger = std::make_shared<Logger>();
  std::string myString("called shared lib");
  logger->PrintString(myString);
  return Napi::String::New(env, "word");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(addon, Init)
