// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <windows.h>

using DictionaryMap = std::map <std::string, std::string>;

#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE
#include <boost/algorithm/string/replace.hpp>

#define BOOST_TEST_INCLUDED
#pragma warning (disable: 4702)
#include <boost/test/unit_test.hpp>



// TODO: reference additional headers your program requires here
