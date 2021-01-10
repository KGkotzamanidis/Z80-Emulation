#ifndef _MEM_H
#define _MEM_H

#include <array>
#include <cstdint>
class MEM{
public:
    std::array<uint16_t, 64*1024> _RAM;
    uint16_t _MinStack = 0x0000, _MaxStack = 0xFFFF;

    void cleanRAM();
};
#endif
