#ifndef IHASHER_H
#define IHASHER_H

#include <string>

class IHasher {
public:
    virtual std::string generateHash(const std::string& data) = 0;
    virtual ~IHasher() = default;
};

#endif // IHASHER_H