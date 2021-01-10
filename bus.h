#ifndef _BUS_H
#define _BUS_H

#include <cstdint>

#include "cpu.h"
#include "mem.h"

class BUS{
public:
    uint8_t readRAM(uint16_t address,bool isRead = false);
    void writeRAM(uint16_t address,uint8_t data);
    CPU cpu;
    MEM mem;
    BUS();
};

#endif
