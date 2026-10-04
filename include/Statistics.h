#ifndef STATISTICS_H
#define STATISTICS_H
#include "Packet.h"
class Statistics
{
private:
    int totalPackets;
    int acceptedPackets;
    int droppedPackets;
    long long totalBytes;
    long long acceptedBytes;
public:
    Statistics();
    void record(const Packet& packet, bool accepted);
    void display() const;
    void saveToCSV(const char* filename) const;
};
#endif
