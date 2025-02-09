#include "BlockchainIO.h"
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void BlockchainIO::exportToFile(const Blockchain& blockchain, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }
    json j;
    for (const auto& block : blockchain.getChain()) {
        j.push_back({
            {"index", block.index},
            {"timestamp", block.timestamp},
            {"data", block.data},
            {"previousHash", block.previousHash},
            {"hash", block.hash},
            {"nonce", block.nonce}
        });
    }
    file << j.dump(4);
    file.close();
}

Blockchain BlockchainIO::importFromFile(const std::string& filename, int difficulty) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading." << std::endl;
        return Blockchain(difficulty);
    }
    json j;
    file >> j;
    file.close();

    Blockchain blockchain(difficulty);
    for (const auto& item : j) {
        blockchain.addBlock(item["data"], SHA256Hasher());
    }
    return blockchain;
}