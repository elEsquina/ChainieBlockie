#include <iostream>
#include "Blockchain.h"
#include "BlockchainIO.h"
#include "SHA256Hasher.h"

int main() {
    SHA256Hasher hasher;
    Blockchain myBlockchain(4);
    
    myBlockchain.addBlock("First Block", hasher);
    myBlockchain.addBlock("Second Block", hasher);
    
    BlockchainIO::exportToFile(myBlockchain, "blockchain.json");
    Blockchain importedBlockchain = BlockchainIO::importFromFile("blockchain.json", 4);
    
    importedBlockchain.validateChain();
    return 0;
}
