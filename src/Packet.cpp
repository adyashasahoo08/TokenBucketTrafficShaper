#include "../include/Packet.h"
Packet::Packet(int packetId, int packetSize)
{
    id = packetId;
    size = packetSize;  
}
int Packet::getId() const
{
    return id;
}
int Packet::getSize() const
{
    return size;
}
