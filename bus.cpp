#include "bus.h"

BUS::BUS(){
    mem.cleanRAM();
    cpu.connctCPU(this);
}

uint8_t BUS::readRAM(uint16_t address,bool isRead){
    if(address >= mem._MinStack && address <= mem._MaxStack){
        return mem._RAM[address];
    }
    return 0x00;
}

void BUS::writeRAM(uint16_t address,uint8_t data){
    if(address >= mem._MinStack && address <= mem._MaxStack){
        mem._RAM[address] = data;
    }
}
