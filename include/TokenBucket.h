#ifndef TOKENBUCKET_H
#define TOKENBUCKET_H
#include "Packet.h"
class TokenBucket
{
private:
    double capacity;
    double tokenRate;
    double tokens;
public:
    TokenBucket(double bucketCapacity, double rate);
    bool processPacket(const Packet& packet);
    void addTokens(double amount);
    double getTokens() const;
    double getCapacity() const;
    double getTokenRate() const;
};
#endif
