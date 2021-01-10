#include "mem.h"

void MEM::cleanRAM(){
    for(auto &blocks:_RAM){
        blocks = 0x00;
    }
}
