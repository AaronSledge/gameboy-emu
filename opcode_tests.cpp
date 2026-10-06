#include <gtest/gtest.h>
#include "SRC\MMU\memory.h"
#include "src\CPU\opcode.h"
#include <iostream>
#include <cstdint>

TEST(OpcodeTest, misc) {
    Opcode opcode;
    EXPECT_EQ(opcode.NOP(), 4);
}

TEST(OpcodeTest, load) {
    //Test 1
    Opcode opcode;
    MMU mmu;
    mmu.loadROM("C:/Users/User/OneDrive/Documents/gameboy-emu/testROM.txt");
    int cycles = opcode.LDr16N16(opcode.BC, mmu);
    EXPECT_EQ(opcode.BC, 0x1234);

    //Test 2
    uint16_t oldValue = opcode.BC;
    opcode.BC = 0xC000;
    opcode.AF = 0x1234;
    cycles = opcode.LDr16memA(opcode.BC, mmu);
    uint8_t index = opcode.BC - 0xC000;
    EXPECT_EQ(0x12, mmu.readWRAM(index));
    opcode.BC = oldValue;

}

TEST(OpcodeTest, sixteenBitArithmetic) {
    Opcode opcode;
    opcode.BC = 0x1234;
    int cycles = opcode.INCr16(opcode.BC);
    EXPECT_EQ(opcode.BC, 4661);
}