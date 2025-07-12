///////////////////////////////////////////////////////////////////////////
// /home/doug/CLionProjects/semigraphics/std.h    2025/07/12 02:47 dwg - //
// Copyright (c) 2021-2025 Douglas Wade Goodall. All Rights Reserved.    //
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// The purpose of this file is to emulate the functionality if the   //
// "import std;" line which is not yet supported in our devo tools.  //
///////////////////////////////////////////////////////////////////////

// 2024/12/29 05:00 dwg - updated modern includes from C++17 SLQR
// 2024/12/22 07:00 dwg - added stdlib.h for system()

#pragma once

// OLD STYLE SYSTEM INCLUDES (Ad Hoc List)
#include <arpa/inet.h>
//#include <errno.h>        // deprecated by <cerrno>
#include <fcntl.h>
#include <memory.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
//#include <stdio.h>        // deprecated by <cstdio>
//#include <stdlib.h>       // deprecated by <cstdlib>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/types.h>
//#include <string.h>         // deprecated by <cstring>
#include <strings.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>
#include <uuid/uuid.h>


/*
 * MODERN STYLE SYSTEM INCLUDES
 * See C++17 Standard Library Quick Reference (2e)
 * Appendix: Standard Library Headers Pages 271-277
 */
#include <algorithm>       // STL algorithms
#include <chrono>          // Time utilities
#include <filesystem>      // File system operations
#include <memory>          // Smart pointers
#include <vector>          // Dynamic arrays
#include <any>
#include <array>
#include <atomic>
#include <bitset>
#include <cassert>
#include <ccomplex>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <charconv>
#include <cinttypes>
#include <climits>      // added 2025-01-16 10:25 dwg -
#include <clocale>
#include <cmath>
#include <codecvt>
#include <complex>
#include <condition_variable>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cuchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <execution>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory_resource>
#include <mutex>
#include <new>
#include <numeric>
#include <optional>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <shared_mutex>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <stack>
#include <system_error>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <stdexcept>
#include <string>
#include <string_view>
//#include <strstream>
#include <thread>
#include <ctime>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>


#define RETURN_SUCCESS EXIT_SUCCESS
#define RETURN_FAILURE EXIT_FAILURE

/////////////////
// eof - std.h //
/////////////////