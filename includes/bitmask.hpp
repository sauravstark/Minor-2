#ifndef BITMASK_HPP
#define BITMASK_HPP

#include <vector>
#include <algorithm>

class Bitmask {
private:
    std::vector<bool> bits;
public:
    Bitmask();
    void SetMask(Bitmask& other);
    std::vector<bool> GetMask() const; 
    bool GetBit(unsigned int pos) const; 
    void PutBit(unsigned int pos, bool on);
    void SetBit(unsigned int pos); 
    void ClearBit(unsigned int pos);
    void ClearAll(); 
};

Bitmask::Bitmask() : bits(std::vector<bool>(32, false)) { }

void Bitmask::SetMask(Bitmask& other) {
    bits = other.GetMask();
}

std::vector<bool> Bitmask::GetMask() const {
    return bits;
}

bool Bitmask::GetBit(unsigned int pos) const {
    return bits[pos];
}

void Bitmask::PutBit(unsigned int pos, bool on) {
    if(on)
        SetBit(pos);
    else
        ClearBit(pos);
}

void Bitmask::SetBit(unsigned int pos) {
    bits[pos] = true;
}

void Bitmask::ClearBit(unsigned int pos) {
    bits[pos] = false;
}

void Bitmask::ClearAll() {
    std::fill(bits.begin(), bits.end(), false);
}

#endif // !BITMASK_HPP