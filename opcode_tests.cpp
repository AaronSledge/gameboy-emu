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
    //Test load 16 bit registers from 16 number
    Opcode opcode;
    MMU mmu;
    mmu.loadROM("C:/Users/User/OneDrive/Documents/gameboy-emu/testROM.txt");
    int cycles = opcode.LDr16N16(opcode.BC, mmu);
    EXPECT_EQ(opcode.BC, 0x1234);

    //Test LD value of A to address stored in BC
    uint16_t oldValue = opcode.BC;
    opcode.BC = 0xC000;
    opcode.AF = 0x1234;
    cycles = opcode.LDr16memA(opcode.BC, mmu);
    uint8_t index = opcode.BC - 0xC000;
    EXPECT_EQ(0x12, mmu.readWRAM(index));
    opcode.BC = oldValue;

    //Test Load 8 bit register from 8 bit number
    opcode.BC = 0x1034;
    uint8_t highbits = (opcode.BC >> 8) & 0xFF;
    uint8_t lowbits = opcode.BC & 0xFF;
    opcode.PC = 0;
    cycles = opcode.LDr8N8(highbits, mmu);
    opcode.BC = (highbits << 8) | lowbits;
    EXPECT_EQ(opcode.BC, 0x1234);

}

TEST(OpcodeTest, sixteenBitArithmetic) {
    Opcode opcode;
    opcode.BC = 0x1234;
    int cycles = opcode.INCr16(opcode.BC);
    EXPECT_EQ(opcode.BC, 4661);
}

TEST(OpcodeTest, eightBitArithmetic) {
    //Test increase
    Opcode opcode;
    uint8_t B = 0x12;
    int cycles = opcode.INCr8(B);
    EXPECT_EQ(B, 19);

    //Test decrease
    cycles = opcode.DECr8(B);
    EXPECT_EQ(B, 18);
}

TEST(OpcodeTest, bitshift) {
    Opcode opcode;
    opcode.AF = 0xDC00;
    int cycles = opcode.RLCA();
    EXPECT_EQ(opcode.AF, 0xB810);

}