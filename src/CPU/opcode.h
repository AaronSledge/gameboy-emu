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

        //constructor
        Opcode();
        // does nothing for one cycle. 1 byte long
        int NOP();
        //Load 16 bit integer to 16 bit register. 3 cycles and 3 bytes long
        int LDr16N16(uint16_t &reg, MMU &mmu);
        //Instruction LD [r16], A: Copy the value of register A into the memory location pointed to by r16. 2 cycle and 1 bytes long
        int LDr16memA(uint16_t reg, MMU &mmu);
        //Instruction INC r16: Increment the value in r16 by 1. 2 cycle and 1 byte long
        int INCr16(uint16_t &reg);
        //Instruction INC r8: Increment the value in r8 by 1. 1 Cycle and 1 byte long
        int INCr8(uint8_t &reg); 
        //Instruction DEC r8: Deincrement the value in r8 by 1. 1 cycle and 1 byte long
        int DECr8(uint8_t &reg);
        //Instruction LD r8, n8: Load the 8 bit integer to 8 bit register. 2 cycles and 2 bytes long
        int LDr8N8(uint8_t &reg, MMU &mmu);
        //Instruction RLCA: Rotate register A left Circularly(shift each bit to the left and bit 7 is placed in carry flag, carry flag goes to bit 0) 1 cycle and 1 byte long
        int RLCA();

};