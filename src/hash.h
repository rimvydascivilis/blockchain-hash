#ifndef HASH_H
#define HASH_H

#include <string>
#include <bitset>

using namespace std;

bitset<256> get_256_bits(const char chr, const unsigned long idx) {
    bitset<256> res;
    srand(int(chr) * (idx + 0xF00DBABE));
    for (size_t i = 0; i < 256; i++) {
        res[i] = rand() % 2;
    }
    return res;
}

bitset<256> hash_f(const string inp) {
    bitset<256> res("1011001001000000101010111001001100101001000111101011000101001111010011111101010110110101010100010110110111001001101111000000111001111111110011000110001011100110000100111110010001111110001010001110110101010100101100011010010101011111100101101101001100010000");
    for (size_t i = 0; i < inp.length(); i++) {
        res = res ^ get_256_bits(inp.at(i), i);
    }
    return res;
}

#endif // HASH_H
