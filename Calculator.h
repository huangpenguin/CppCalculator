#pragma once

#include <vector>
#include <string>
#include <stack>
#include <stdexcept>
#include <cmath>
#include "Memory.h"

class Calculator {
public:
 
    int calculate(const std::vector<std::string>& tokens,Memory& memory);

private:
 
    int performOperation(const std::string& op, int a, int b);
};

