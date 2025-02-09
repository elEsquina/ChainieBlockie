#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <vector>

class Blockchain {
private:
    std::vector<Block> chain;
    int difficulty;
    void createGenesisBlock();
public:
    Blockchain(int diff);
    void addBlock(const std::string& data, IHasher& hasher);
    const std::vector<Block>& getChain() const;
    bool validateChain() const;
};

#endif // BLOCKCHAIN_H