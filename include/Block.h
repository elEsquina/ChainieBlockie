#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include "IHasher.h"

class Block {
public:
    int index;
    std::string timestamp;
    std::string data;
    std::string previousHash;
    std::string hash;
    int nonce;

    Block(int idx, std::string ts, std::string d, std::string prevHash);
    void calculateHash(IHasher& hasher);
    void mineBlock(IHasher& hasher, int difficulty);
};

#endif // BLOCK_H