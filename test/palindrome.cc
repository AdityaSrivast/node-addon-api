#include "napi.h"
#include <iostream>

using namespace Napi;

Value IsPalindrome(const CallbackInfo& info) {
  if (info[0].IsString()) {
    std::string input = info[0].ToString().Utf8Value();
    int n = input.length();
    for (int32_t i = 0;i<n/2;i++) {
      if (input[i]!=input[n-i-1]) {
        return String::New(info.Env(), "Not a Palindrome");
      }
    }
    return String::New(info.Env(), "Palindrome");
  }
  return String::New(info.Env(), "Not a string");
}

Object InitPalindrome(Env env) {
  Object exports = Object::New(env);
  exports["IsPalindrome"] = Function::New(env, IsPalindrome);
  return exports;
}
