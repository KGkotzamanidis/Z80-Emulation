#include "cpu.h"
#include "bus.h"
CPU::CPU(){
    instructionTable = {
    };
}

/*
 *  Λειτουργια διευθυνσεων
 */
//  Immediate_Addressing
uint8_t CPU::Immediate_Addressing(){
    return 0x00;
}
//  Immediate_Extended_Addressing
uint8_t CPU::Immediate_Extended_Addressing(){
    return 0x00;
}
//  Modified_Page_Zero_Addressing
uint8_t CPU::Modified_Page_Zero_Addressing(){
    return 0x00;
}
//  Relative_Addressing
uint8_t CPU::Relative_Addressing(){
    return 0x00;
}
//  Extended_Addressing
uint8_t CPU::Extended_Addressing(){
    return 0x00;
}
//  Indexed_Addressing
uint8_t CPU::Indexed_Addressing(){
    return 0x00;
}
//  Register_Addressing
uint8_t CPU::Register_Addressing(){
    return 0x00;
}
//  Implied_Addressing
uint8_t CPU::Implied_Addressing(){
    return 0x00;
}
//  Register_Indirect_Addressing
uint8_t CPU::Register_Indirect_Addressing(){
    return 0x00;
}

/*
 *  Εντολες CPU
 */

//  NOP Function
uint8_t CPU::NOP(){
    switch (opcodes) {
        case 0x00:
            return 1;
        break;
    }
    return 0;
}

void CPU::connctCPU(BUS *n){
    bus =n;
}

void CPU::printSpect(){
    using namespace std;
    cout<<"~System Information~"<<endl;
    cout<<"CPUname:Z80"<<endl;
    cout<<"CPUarchi:8bit"<<endl;
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












