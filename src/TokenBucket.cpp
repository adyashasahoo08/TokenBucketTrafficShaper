#include "../include/TokenBucket.h"

TokenBucket::TokenBucket(double bucketCapacity, double rate)
{
    capacity = bucketCapacity;
    tokenRate = rate;
    tokens = bucketCapacity;
}

void TokenBucket::addTokens(double amount)
{
    tokens += amount * tokenRate;

    if (tokens > capacity)
    {
        tokens = capacity;
    }
}

bool TokenBucket::processPacket(const Packet& packet)
{
    if (tokens >= packet.getSize())
    {
        tokens -= packet.getSize();
        return true;
    }

    return false;
}

double TokenBucket::getTokens() const
{
    return tokens;
}

double TokenBucket::getCapacity() const
{
    return capacity;
}

double TokenBucket::getTokenRate() const
{
    return tokenRate;
}

