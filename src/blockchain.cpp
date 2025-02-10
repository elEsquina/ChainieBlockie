#include "include/blockchain.h"
#include "include/SHA256Hasher.h"

#include <chrono>
#include <ctime>
#include <iostream>

Blockchain::Blockchain(int diff) : difficulty(diff) {
    createGenesisBlock();
}

void Blockchain::createGenesisBlock() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    Block genesisBlock(0, std::ctime(&now), "Genesis Block", "0");
    SHA256Hasher hasher;
    genesisBlock.mineBlock(hasher, difficulty);
    chain.push_back(genesisBlock);
}

void Blockchain::addBlock(const std::string& data, IHasher& hasher) {
    int newIndex = chain.size();
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    Block newBlock(newIndex, std::ctime(&now), data, chain.back().hash);
    newBlock.mineBlock(hasher, difficulty);
    chain.push_back(newBlock);
}

const std::vector<Block>& Blockchain::getChain() const {
    return chain;
}

bool Blockchain::validateChain() const {
    for (size_t i = 1; i < chain.size(); i++) {
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];
        SHA256Hasher hasher;

        // Recalculate the block's hash to ensure integrity
        std::string calculatedHash = hasher.generateHash(std::to_string(currentBlock.index) + currentBlock.timestamp + currentBlock.data + currentBlock.previousHash + std::to_string(currentBlock.nonce));
        if (currentBlock.hash != calculatedHash) {
            std::cout << "Blockchain validation failed at block " << i << "\n";
            return false;
        }

        // Check the previous hash link
        if (currentBlock.previousHash != previousBlock.hash) {
            std::cout << "Blockchain link broken at block " << i << "\n";
            return false;
        }
    }
    std::cout << "Blockchain is valid!\n";
    return true;
}
