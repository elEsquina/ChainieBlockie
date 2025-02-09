#ifndef SHA256HASHER_H
#define SHA256HASHER_H

#include "IHasher.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

class SHA256Hasher : public IHasher {
public:
    std::string generateHash(const std::string& data) override;
};

#endif // SHA256HASHER_H