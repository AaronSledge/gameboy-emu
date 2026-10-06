#include "memory.h"
#include <fstream>
#include <iostream>
#include <cstdio>
MMU::MMU() 
:   rom(32768),
    vram(8192),
    eram(8192),
    wram(8192),
    oam(160),
    io(128),
    hram(127){
}

uint8_t MMU::readROM(uint16_t address) {
    return rom.at(address);
}

uint8_t MMU::readVRAM(uint8_t address) {
    return vram.at(address);
}

uint8_t MMU::readERAM(uint8_t address) {
    return eram.at(address);
}

uint8_t MMU::readWRAM(uint8_t address) {
    return wram.at(address);
}

uint8_t MMU::readOAM(uint8_t address) {
    return oam.at(address);
}

uint8_t MMU::readIO(uint8_t address) {
    return io.at(address);
}

uint8_t MMU::readHRAM(uint8_t address) {
    return hram.at(address);
}

uint8_t MMU::readIE() {
    return IE;
}

void MMU::loadROM(std::string filename) {
    //update this to read raw bits
    std::ifstream romFile(filename);

    if(!romFile.is_open()) {
        std::perror("Error opening ");
        std::cout << "fileName: " << filename << std::endl;
        return;
    }

    std::string value;
    int index = 0;
    while(romFile >> value) {
        uint8_t byte = static_cast<uint8_t>(std::stoul(value, nullptr, 16));
        if(rom.size() <= 32768) {
            rom.at(index) = byte;
            index++;
        }
        else {
            rom.push_back(byte);
        }

    }
    romFile.close();
    return;
}

void MMU::writeVRAM(uint8_t address, uint8_t data) {
    vram.at(address) = data;
}

void MMU::writeERAM(uint8_t address, uint8_t data) {
    eram.at(address) = data;
}

void MMU::writeWRAM(uint8_t address, uint8_t data) {
    wram.at(address) = data;
}

void MMU::writeOAM(uint8_t address, uint8_t data) {
    oam.at(address) = data;
}

void MMU::writeIO(uint8_t address, uint8_t data) {
    io.at(address) = data;
}

void MMU::writeHRAM(uint8_t address, uint8_t data) {
    hram.at(address) = data;
}

void MMU::writeIE(uint8_t data) {
    IE = data;
}


