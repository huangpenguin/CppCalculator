#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "Memory.h"
#include "Information.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <regex>

class Parser {
public:
    Information parse(const std::string& input,const Memory& memory);
};

