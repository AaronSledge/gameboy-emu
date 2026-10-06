#include "SRC\MMU\memory.h"
#include "src\CPU\opcode.h"
#include <iostream>
#include <cstdint>

int main() {
    //Test purposes for now
    Opcode opcode;
    MMU mmu;
    mmu.loadROM("C:/Users/User/OneDrive/Documents/gameboy-emu/testROM.txt");
    int cycles = opcode.LDr16N16(opcode.BC, mmu);

    uint16_t oldValue = opcode.BC;
    opcode.BC = 0xC000;
    opcode.AF = 0x1234;
    cycles = opcode.LDr16memA(opcode.BC, mmu);

    return 0;
}