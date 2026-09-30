#include <gtest/gtest.h>
#include "SRC\MMU\memory.h"
TEST(MemTest, readMem) {
    MMU mmu;
    EXPECT_EQ(mmu.readROM(0), 0);
    EXPECT_EQ(mmu.readVRAM(2), 0);
    EXPECT_EQ(mmu.readERAM(3), 0);
    EXPECT_EQ(mmu.readWRAM(4), 0);
    EXPECT_EQ(mmu.readOAM(5), 0);
    EXPECT_EQ(mmu.readIO(6), 0);
    EXPECT_EQ(mmu.readHRAM(7), 0);
    EXPECT_EQ(mmu.readIE(), 0);
}

TEST(MemTest, writeMem) {
    MMU mmu;
    mmu.writeVRAM(2, 4);
    EXPECT_EQ(mmu.readVRAM(2), 4);
    mmu.writeERAM(25, 39);
    EXPECT_EQ(mmu.readERAM(25), 39);
    mmu.writeWRAM(30, 5);
    EXPECT_EQ(mmu.readWRAM(30), 5);
    mmu.writeOAM(100, 0x88);
    EXPECT_EQ(mmu.readOAM(100), 0x88);
    mmu.writeIO(10, 45);
    EXPECT_EQ(mmu.readIO(10), 45);
    mmu.writeHRAM(28, 4);
    EXPECT_EQ(mmu.readHRAM(28), 4);
    mmu.writeIE(31);
    EXPECT_EQ(mmu.readIE(), 31);
}

