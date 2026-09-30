#include "registers.h"
#include "opcode.h"
#include "../MMU/memory.h"

Registers registers;
MMU mmu;

int opcode::NOP() {
    //simply return 4 for the cycles
    return 4;
}

int opcode::LDr16N16(uint16_t &reg) {
    //since this is 16 bit integer we have to get low and high bits
    uint8_t highbits = mmu.readROM(registers.PC++);
    //increment again to get the high bit
    uint8_t lowbits = mmu.readROM(registers.PC++);
    //shift 8 bits left to add 8 0s towards the end and bitwise OR it to add the low bit
    reg = (highbits << 8) | lowbits;
    return 12;
}

int opcode::LDr16memA(uint16_t &reg) {
    //to seperate A shift the bits to the right then AND by 0xFF to only get the right side bits
    uint8_t A = (registers.AF >> 8) & 0xFF;
    //if address is between these two hex then it goes into vram according to memory map
    if(reg > 0x7FFF & reg <= 0x9FFF) {
        uint8_t address = reg - 8000;
        mmu.writeVRAM(address, A);
    }
    else if(reg > 0x9FFF & reg <= 0xBFFF) {
        uint8_t address = reg - 0xA000;
        mmu.writeERAM(address, A);
    }
    else if(reg > 0xBFFF & reg <= 0xDFFF) {
        uint8_t address = reg - 0xC000;
        mmu.writeWRAM(address, A);
    }
    else if(reg > 0xFDFF & reg <= 0xFE9F) {
        uint8_t address = reg - 0xFE00;
        mmu.writeOAM(address, A);
    }
    else if(reg > 0xFeFF & reg <= 0xFF7F) {
        uint8_t address = reg - 0xFF00;
        mmu.writeIO(address, A);
    }
    else if(reg > 0xFF7F & reg <= 0xFFFE) {
        uint8_t address = reg - 0xFF80;
        mmu.writeHRAM(address, A);
    }
    return 12;
}

int opcode::INCr16(uint16_t &reg) {
    reg++;
}

