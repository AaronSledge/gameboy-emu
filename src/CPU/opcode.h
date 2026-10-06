#pragma once
#include <cstdint>
#include "../MMU/memory.h"
class Opcode {
    public:
        //{} initalized values to 0
        
        //16 bit register for accumulator and flag. A is for accumulator for arithmetic operations where f is flag
        uint16_t AF;
        //16 bit register
        uint16_t BC;
        //16 bit register
        uint16_t DE;
        //16 bit register
        uint16_t HL;
        //16 bit stack pointer: Keeps track or most recent value in stack
        uint16_t SP;
        //16 bit program counter: Holds the address of the next instruction to be excuted
        uint16_t PC;

        // does nothing for one cycle. 1 byte long
        Opcode();
        int NOP();
        //Load 16 bit integer to 16 bit register. 3 cycles and 3 bytes long
        int LDr16N16(uint16_t &reg, MMU mmu);
        //Instruction LD [r16], A: Copy the value of register A into the memory location pointed to by r16
        int LDr16memA(uint16_t reg, MMU &mmu);
        //Instruction INC BC: Increment the value in r16 by 1
        int INCr16(uint16_t &reg);

};