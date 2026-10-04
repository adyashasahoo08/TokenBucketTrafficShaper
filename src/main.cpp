#include <iostream>
#include <random>
#include <iomanip>
#include "../include/Packet.h"
#include "../include/TokenBucket.h"
#include "../include/Statistics.h"
using namespace std;
int main()
{
    double bucketCapacity;
    double tokenRate;
    int numberOfPackets;
    cout << "=============================================\n";
    cout << " TOKEN-BUCKET NETWORK BANDWIDTH SHAPER\n";
    cout << "       & TRAFFIC POLICER\n";
    cout << "=============================================\n";
    cout << "\nEnter bucket capacity (bytes): ";
    cin >> bucketCapacity;
    cout << "Enter token generation rate (bytes/sec): ";
    cin >> tokenRate;
    cout << "Enter number of packets: ";
    cin >> numberOfPackets;
    if (bucketCapacity <= 0 ||
        tokenRate <= 0 ||
        numberOfPackets <= 0)
    {
        cout << "\nInvalid input.\n";
        cout << "All values must be greater than zero.\n";
        return 1;
    }
    TokenBucket bucket(bucketCapacity, tokenRate);
    Statistics statistics;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> packetSizeGenerator(100, 1000);
    cout << "\n";
    cout << "------------- PACKET PROCESSING -------------\n";
    for (int i = 1; i <= numberOfPackets; i++)
    {
        int packetSize = packetSizeGenerator(generator);
        bucket.addTokens(0.1);
        Packet packet(i, packetSize);
        bool accepted = bucket.processPacket(packet);
        statistics.record(packet, accepted);
        cout << "Packet "
             << setw(3)
             << packet.getId();
        cout << " | Size: "
             << setw(4)
             << packet.getSize()
             << " bytes";
        cout << " | ";
        if (accepted)
        {
            cout << "ACCEPTED";
        }
        else
        {
            cout << "DROPPED";
        }
        cout << " | Tokens: "
             << fixed
             << setprecision(2)
             << bucket.getTokens();
        cout << "\n";
    }
    statistics.display();
    statistics.saveToCSV("data/traffic_statistics.csv");
    cout << "\nStatistics saved to:\n";
    cout << "data/traffic_statistics.csv\n";
    return 0;
}
