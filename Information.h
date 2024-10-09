#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Memory.h"

class Information {
public:
    Information() = default;

    void addToken(const std::string& token,const Memory& memory);
    const std::vector<std::string>& getTokens() const;
    int get_length() const;
private:
    std::vector<std::string> tokens;
    static const size_t MAX_TOKENS = 10;
};

