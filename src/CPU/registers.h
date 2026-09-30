#pragma once
#include <cstdint>

class Registers {
    public:
        //{} initalized values to 0
        
        //16 bit register for accumulator and flag. A is for accumulator for arithmetic operations where f is flag
        uint16_t AF{};
        //16 bit register
        uint16_t BC{};
        //16 bit register
        uint16_t DE{};
        //16 bit register
        uint16_t HL{};
        //16 bit stack pointer: Keeps track or most recent value in stack
        uint16_t SP{};
        //16 bit program counter: Holds the address of the next instruction to be excuted
        uint16_t PC{};

};