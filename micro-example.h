///////////////////////////////////////////////////////////////////////
// SPDX-License-Identifier: MIT
//
// micro-example.h
// ===============
//
// An example header-only library in C99 used as a template project,
// in the style of the great micro-headers.
//
// Author:  Giovanni Santini
// Mail:    giovanni.santini@proton.me
// Github:  @San7o
//
//
// Example
// -------
//
//
//     int main(void)
//     {
//         micro_example_hello();
//         return 0;
//     }
//
//
// Usage
// -----
//
// Do this:
//
//   #define MICRO_EXAMPLE_IMPLEMENTATION
//
// before you include this file in *one* C or C++ file to create the
// implementation.
//
// i.e. it should look like this:
//
//   #include ...
//   #include ...
//   #include ...
//   #define MICRO_EXAMPLE_IMPLEMENTATION
//   #include "micro-example.h"
//
// You can tune the library by #defining certain values. See the
// "Config" comments under "Configuration" below.
//
//
// Code
// ----
//
// The official git repository of micro-example.h is hosted at:
//
//     https://github.com/San7o/micro-example.h
//
// This is part of a bigger collection of header-only C99 libraries
// called "micro-headers", contributions are welcome:
//
//     https://github.com/San7o/micro-headers
//

#ifndef MICRO_EXAMPLE
#define MICRO_EXAMPLE

#define MICRO_EXAMPLE_MAJOR 2
#define MICRO_EXAMPLE_MINOR 1
#define MICRO_EXAMPLE_VERSION \
  ((MICRO_EXAMPLE_MAJOR << 8) | MICRO_EXAMPLE_MINOR)

#ifdef __cplusplus
extern "C" {
#endif

//
// Configuration
//

// Config: Prefix for all functions
// For function inlining, set this to `static inline` and then define
// the implementation in all the files
#ifndef MICRO_EXAMPLE_DEF
  #define MICRO_EXAMPLE_DEF extern
#endif
  
//
// Macros
//

//
// Errors
//

#define MICRO_EXAMPLE_OK          0
#define _MICRO_EXAMPLE_ERROR_MAX -1

//
// Types
//

typedef struct {
  int foo;
  float bar;
} MicroExample;

//
// Function declarations
//

MICRO_EXAMPLE_DEF int micro_example_hello(void);

MICRO_EXAMPLE_DEF int micro_example_major(void);
MICRO_EXAMPLE_DEF int micro_example_minor(void);
MICRO_EXAMPLE_DEF int micro_example_version(void);
  
//
// Implementation
//
  
#ifdef MICRO_EXAMPLE_IMPLEMENTATION

#include <stdio.h>
  
MICRO_EXAMPLE_DEF int micro_example_hello(void)
{
  const char* micro_headers_url = "https://github.com/San7o/micro-headers";
  printf("Hello, from micro-example.h! v%d.%d\n\n",
         micro_example_major(), micro_example_minor());
  printf("Check out the micro-headers: %s\n", micro_headers_url);
  return MICRO_EXAMPLE_OK;
}

MICRO_EXAMPLE_DEF int micro_example_major(void)
{
  return MICRO_EXAMPLE_MAJOR;
}

MICRO_EXAMPLE_DEF int micro_example_minor(void)
{
  return MICRO_EXAMPLE_MINOR;
}

MICRO_EXAMPLE_DEF int micro_example_version(void)
{
  return MICRO_EXAMPLE_VERSION;
}

  
#endif // MICRO_EXAMPLE_IMPLEMENTATION

//
// Examples
//
  
#if 0

#define MICRO_EXAMPLE_IMPLEMENTATION
#include "micro-example.h"

int main(int argc, char** argv)
{
  micro_example_hello();
  return 0;
}
  
#endif // 0
  
#ifdef __cplusplus
}
#endif

#endif // MICRO_EXAMPLE
