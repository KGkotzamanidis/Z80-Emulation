#ifndef _CPU_H
#define _CPU_H

#include <iostream>
#include <cstdint>
#include <string>
#include <map>
#include <vector>

class BUS;
class CPU{
    public:
    /*
     * Συμφωνα με manual σελιδα 16 οι καταχωρητες απο A εως L ειναι 8bit
     * και οι καταχωρητες SP,PC,IX,IY ειναι 16bit.
     * Ακομα υπαρχει συνδιασμος καταχωτητων 2 8bit για την δημιουργεια ενος 16bit
     * AF,BC,DE,HL
     */

    //Καταχωρητες Γενικης Χρησης 8-Bit
    uint8_t regA=0x00,/*regF=0x00*/regB=0x00,regC=0x00,
            regD=0x00,regE=0x00,regH=0x00,regL=0x00,
            regAccumulator=0x00,regStatus=0x00;
    //Καταχωρητες Ειδηκης Χρησης 16-Bit
    uint16_t regStackPointer=0x0000,regProgramCounter=0x0000,
             regIX=0x0000,regIY=0x0000;
    /*
     * Καταχωρητης Flag δες σελιδα 79.
     */
    enum regF:uint8_t{
        c=(1<<0),  //0 Bit Carry Flag.
        n=(1<<1),  //1 Bit Add/Subtract Flag.
        pv=(1<<2), //2 Bit Parity/Overflow Flag.
        x0=(1<<3), //3 Bit Not Used!
        h=(1<<4),  //4 Bit Half Carry Flag.
        x1=(1<<5), //5 Bit Not Used!
        z=(1<<6),  //6 Bit Zero Flag.
        s=(1<<7)   //7 Bit Sign Flag.
    };

    CPU();
    void connctCPU(BUS *n);
    void printSpect();
    private:
    uint8_t fetched=0x00,opcodes=0x00,cycles=0;
    uint16_t address_abs=0x0000,address_rel=0x0000;
    uint32_t clock_count;
    /*
     * struct Instruction_CPU:
     * Μια εντολη του cpu εχει το Ονομα της εντολης, τα Bit που συνεργαζονται η διευθυνση και ποσους κυκλου
     * θα χρειαστει.
     */
    struct Instruction_CPU{
        std::string instruction_name;
        uint8_t (CPU::*operate)     (void) = nullptr;
        uint8_t (CPU::*addressmode) (void) = nullptr;
        uint8_t cycles=0;
    };
    /*
     * vector<Instruction_CPU> instructionTable:
     * Για να δεις το table πανε εδω: https://clrhome.org/table/
     */
    std::vector<Instruction_CPU> instructionTable;
    uint8_t fetch();
    /*
     * Λειτουργια διευθυνσεων
     * 9 Εντολες διευθυνσεων(addressing)
     * Βλεπε σελιδα 34.
     */
    uint8_t Immediate_Addressing();             //1
    uint8_t Immediate_Extended_Addressing();    //2
    uint8_t Modified_Page_Zero_Addressing();    //3
    uint8_t Relative_Addressing();              //4
    uint8_t Extended_Addressing();              //5
    uint8_t Indexed_Addressing();               //6
    uint8_t Register_Addressing();              //7
    uint8_t Implied_Addressing();               //8
    uint8_t Register_Indirect_Addressing();     //9
    /*
     * Εντολες CPU
     * 68 Βασικες εντολες(opcodes)
     * Βλεπε σελιδα 70.
     */
    uint8_t ADC();  uint8_t ADD();  uint8_t AND();  uint8_t BIT();
    uint8_t CALL(); uint8_t CCF();  uint8_t CP();   uint8_t CPD();
    uint8_t CPDR(); uint8_t CPI();  uint8_t CPIR(); uint8_t CPL();
    uint8_t DAA();  uint8_t DEC();  uint8_t DI();   uint8_t DJNZ();
    uint8_t EI();   uint8_t EX();   uint8_t EXX();  uint8_t HALT();
    uint8_t IM();   uint8_t IN();   uint8_t INC();  uint8_t IND();
    uint8_t INDR(); uint8_t INI();  uint8_t INIR(); uint8_t JP();
    uint8_t JR();   uint8_t LD();   uint8_t LDD();  uint8_t LDDR();
    uint8_t LDI();  uint8_t LDIR(); uint8_t NEG();  uint8_t NOP();
    uint8_t OR();   uint8_t OTDR(); uint8_t OTIR(); uint8_t OUT();
    uint8_t OUTD(); uint8_t OUTI(); uint8_t POP();  uint8_t PUSH();
    uint8_t RES();  uint8_t RET();  uint8_t RETI(); uint8_t RETN();
    uint8_t RL();   uint8_t RLA();  uint8_t RLC();  uint8_t RLCA();
    uint8_t RLD();  uint8_t RR();   uint8_t RRA();  uint8_t RRC();
    uint8_t RRCA(); uint8_t RRD();  uint8_t RST();  uint8_t SBC();
    uint8_t SCF();  uint8_t SET();  uint8_t SLA();  uint8_t SLL_SL1();
    uint8_t SRA();  uint8_t SRL();  uint8_t SUB();  uint8_t XOR();


    BUS *bus = nullptr;
    uint8_t readCPU(uint16_t address);
    void writeCPU(uint16_t address,uint8_t data);
    uint8_t getFLAG(regF anFlag);
    void setFLAG(regF anFlag,bool avalue);
};
#endif
