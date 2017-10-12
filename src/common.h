/*

   vdexExtractor
   -----------------------------------------

   Anestis Bechtsoudis <anestis@census-labs.com>
   Copyright 2017 by CENSUS S.A. All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/

#ifndef _COMMON_H_
#define _COMMON_H_

#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "log.h"

#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;
typedef int8_t s1;
typedef int16_t s2;
typedef int32_t s4;
typedef int64_t s8;

#define CHECK_IMPL(c1, op, c2)                                \
  do {                                                        \
    u8 v1 = (u8)(c1);                                         \
    u8 v2 = (u8)(c2);                                         \
    if (UNLIKELY(!(v1 op v2)))                                \
      LOGMSG(l_FATAL, "(" #c1 ") " #op " (" #c2 ")", v1, v2); \
  } while (false) /**/

#define CHECK(a) CHECK_IMPL((a), !=, 0)
#define CHECK_EQ(a, b) CHECK_IMPL((a), ==, (b))
#define CHECK_NE(a, b) CHECK_IMPL((a), !=, (b))
#define CHECK_LT(a, b) CHECK_IMPL((a), <, (b))
#define CHECK_LE(a, b) CHECK_IMPL((a), <=, (b))
#define CHECK_GT(a, b) CHECK_IMPL((a), >, (b))
#define CHECK_GE(a, b) CHECK_IMPL((a), >=, (b))

#define PROG_NAME "vdexExtractor"
#define PROG_VERSION "0.1.0"
#define PROG_AUTHORS                                    \
  "    Anestis Bechtsoudis <anestis@census-labs.com>\n" \
  "  Copyright 2017 by CENSUS S.A. All Rights Reserved."

#define AB ANSI_BOLD
#define AC ANSI_CLEAR
#define ANSI_BOLD "\033[1m"
#define ANSI_CLEAR "\033[0m"

typedef struct {
  char *inputFile;
  char **files;
  size_t fileCnt;
} infiles_t;

#endif
