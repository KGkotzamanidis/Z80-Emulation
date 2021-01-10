#include "cpu.h"
#include "bus.h"

void CPU::connctCPU(BUS *n){
    bus =n;
}

uint8_t CPU::readCPU(uint16_t address){
    return bus->readRAM(address);
}

void CPU::writeCPU(uint16_t address,uint8_t data){
    bus->writeRAM(address,data);
}

uint8_t CPU::getFLAG(regF anFlag){
    return ((regStatus & anFlag) >0) ? 1:0;
}

void CPU::setFLAG(regF anFlag,bool avalue){
    if(avalue){
        regStatus |= anFlag;
    }else{
        regStatus &= ~anFlag;
    }
}
