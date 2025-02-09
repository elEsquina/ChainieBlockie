#include "Block.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Block::Block(int idx, std::string ts, std::string d, std::string prevHash)
    : index(idx), timestamp(ts), data(d), previousHash(prevHash), nonce(0) {
    hash = ""; // Placeholder
}

void Block::calculateHash(IHasher& hasher) {
    std::stringstream ss;
    ss << index << timestamp << data << previousHash << nonce;
    hash = hasher.generateHash(ss.str());
}

void Block::mineBlock(IHasher& hasher, int difficulty) {
    std::string target(difficulty, '0');
    do {
        nonce++;
        calculateHash(hasher);
    } while (hash.substr(0, difficulty) != target);
    std::cout << "Block mined: " << hash << "\n";
}
