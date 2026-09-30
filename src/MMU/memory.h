#pragma once
#include <vector>
class MMU {
    private:
        std::vector<uint8_t> rom;
        std::vector<uint8_t> vram;
        std::vector<uint8_t> eram;
        std::vector<uint8_t> wram;
        std::vector<uint8_t>oam;
        std::vector<uint8_t>io;
        std::vector<uint8_t>hram;
        uint8_t IE{};
    public:
        MMU();
        uint8_t readROM(uint16_t address);
        uint8_t readVRAM(uint8_t address);
        uint8_t readERAM(uint8_t address);
        uint8_t readWRAM(uint8_t address);
        uint8_t readOAM(uint8_t address);
        uint8_t readIO(uint8_t address);
        uint8_t readHRAM(uint8_t address);
        uint8_t readIE();

        void writeVRAM(uint8_t address, uint8_t data);
        void writeERAM(uint8_t address, uint8_t data);
        void writeWRAM(uint8_t address, uint8_t data);
        void writeOAM(uint8_t address, uint8_t data);
        void writeIO(uint8_t address, uint8_t data);
        void writeHRAM(uint8_t address, uint8_t data);
        void writeIE(uint8_t data);
};