#include "Memory.h"

void Memory::addANS(int value)
{
    data.push_back(std::to_string(value));
}

std::string Memory::get_last_ans() const
{   
    if (data.size() != 0) {
        return data.back();
    }
    
}
int Memory::get_size()const
{
    return data.size();
}

void Memory::allclear() const
{
    data.clear();
    data = { "0" };
}
