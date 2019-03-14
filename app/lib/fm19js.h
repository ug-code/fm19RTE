#pragma once
#ifndef FM19JS_H
#define FM19JS_H
#define WIN32_LEAN_AND_MEAN

#include <node.h>
#include <windows.h>

using v8::Isolate;

class fm19js {

public:
  fm19js();
  ~fm19js();

  static void throwError(char* error, Isolate* isolate);
};
#endif
#pragma once