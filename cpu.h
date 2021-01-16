#ifndef _CPU_H
#define _CPU_H

#include <cstdint>
#include <string>
#include <vector>

typedef uint8_t bit;
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

    void connctCPU(BUS *n);
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
        std::string name;
        uint8_t (CPU::*operate)     (void) = nullptr;
        uint8_t (CPU::*addressmode) (void) = nullptr;
        uint8_t cycles=0;
    };
    /*
     * Για να δεις το table πανε εδω:
     * https://pastraiser.com/cpu/i8080/i8080_opcodes.html
     */
    std::vector<Instruction_CPU> _lookupTable;
    uint8_t fetch();
    /*
     * Λειτουργια διευθυνσεων
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
     */
    uint8_t LD();uint8_t LDA();uint8_t LDI();







    BUS *bus = nullptr;
    uint8_t readCPU(uint16_t address);
    void writeCPU(uint16_t address,uint8_t data);
    uint8_t getFLAG(regF anFlag);
    void setFLAG(regF anFlag,bool avalue);
};
#endif
