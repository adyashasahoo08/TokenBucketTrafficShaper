#ifndef PACKET_H
#define PACKET_H
class Packet
{
private:
    int id;
    int size;
public:
    Packet(int packetId, int packetSize);
    int getId() const;
    int getSize() const;
};
#endif
