#pragma once

#include "iostream"
#include <string>
#include <vector>
class Memory
{
public:
    Memory()=default;
    void addANS(int value);
    std::string get_last_ans() const;
    void allclear() const;
    int get_size()const;
private:
    mutable std::vector<std::string> data = {"0"};
};

