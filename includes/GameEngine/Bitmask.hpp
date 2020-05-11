#ifndef BITMASK_HPP
#define BITMASK_HPP

#include <vector>
#include <algorithm>

class BitMask {
private:
    std::vector<bool> bits;
public:
    BitMask();
    void setMask(BitMask& other);
    std::vector<bool> getMask() const; 
    bool getBit(unsigned int pos) const; 
    void putBit(unsigned int pos, bool on);
    void setBit(unsigned int pos); 
    void clearBit(unsigned int pos);
    void clearAll(); 
};

BitMask::BitMask() : bits(std::vector<bool>(32, false)) { }

void BitMask::setMask(BitMask& other) {
    bits = other.getMask();
}

std::vector<bool> BitMask::getMask() const {
    return bits;
}

bool BitMask::getBit(unsigned int pos) const {
    return bits[pos];
}

void BitMask::putBit(unsigned int pos, bool on) {
    if(on)
        setBit(pos);
    else
        clearBit(pos);
}

void BitMask::setBit(unsigned int pos) {
    bits[pos] = true;
}

void BitMask::clearBit(unsigned int pos) {
    bits[pos] = false;
}

void BitMask::clearAll() {
    std::fill(bits.begin(), bits.end(), false);
}

#endif // !BITMASK_HPP