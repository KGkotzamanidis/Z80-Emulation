#ifndef REGISTERS_H
#define REGISTERS_H

#include <cstdint>
class Registers{
    public:
    /*
     * Συμφωνα με manual σελιδα 61 οι καταχωρητες απο A εως L ειναι 8bit
     * και οι καταχωρητες SP και PC ειναι 16bit.
     * Ακομα υπαρχει συνδιασμος καταχωτητων 2 8bit για την δημιουργεια ενος 16bit
     * AF,BC,DE,HL
     */
    uint8_t A,F,B,C,D,E,H,L;
    uint16_t SP,PC;
    uint16_t AF,BC,DE,HL;

    union Flag{
        struct{
            char regZ:1;
            char regN:1;
            char regH:1;
            char regC:1;
            char regNA:4;
        }
        uint8_t reg;
    };

    void resetFlagRegister();
};

#endif // REGISTERS_H
