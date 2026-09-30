#pragma once
#include <cstdint>
class opcode {
    public:
        // does nothing for one cycle. 1 byte long
        int NOP();
        //Load 16 bit integer to 16 bit register. 3 cycles and 3 bytes long
        int LDr16N16(uint16_t &reg);
        //Instruction LD [r16], A: Copy the value of register A into the memory location pointed to by r16
        int LDr16memA(uint16_t &reg);
        //Instruction INC BC: Increment the value in r16 by 1
        int INCr16(uint16_t &reg);

};