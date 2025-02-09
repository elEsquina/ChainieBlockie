#ifndef BLOCKCHAINIO_H
#define BLOCKCHAINIO_H

#include "Blockchain.h"
#include <string>

class BlockchainIO {
public:
    static void exportToFile(const Blockchain& blockchain, const std::string& filename);
    static Blockchain importFromFile(const std::string& filename, int difficulty);
};

#endif // BLOCKCHAINIO_H