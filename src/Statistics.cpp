#include "../include/Statistics.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
Statistics::Statistics()
{
    totalPackets = 0;
    acceptedPackets = 0;
    droppedPackets = 0;
    totalBytes = 0;
    acceptedBytes = 0;
}
void Statistics::record(const Packet& packet, bool accepted)
{
    totalPackets++;
    totalBytes += packet.getSize();
    if (accepted)
    {
        acceptedPackets++;
        acceptedBytes += packet.getSize();
    }
    else
    {
        droppedPackets++;
    }
}
void Statistics::display() const
{
    double dropPercentage = 0;

    if (totalPackets > 0)
    {
        dropPercentage =
            ((double)droppedPackets / totalPackets) * 100;
    }
    cout << "\n=========================================\n";
    cout << "        TRAFFIC STATISTICS\n";
    cout << "=========================================\n";
    cout << "Total Packets       : " << totalPackets << endl;
    cout << "Accepted Packets    : " << acceptedPackets << endl;
    cout << "Dropped Packets     : " << droppedPackets << endl;
    cout << "Total Bytes         : " << totalBytes << endl;
    cout << "Accepted Bytes      : " << acceptedBytes << endl;
    cout << fixed << setprecision(2);
    cout << "Drop Percentage     : "
         << dropPercentage << "%\n";
    cout << "=========================================\n";
}
void Statistics::saveToCSV(const char* filename) const
{
    ofstream file(filename);
    if (!file)
    {
        cout << "Error creating CSV file.\n";
        return;
    }
    double dropPercentage = 0;

    if (totalPackets > 0)
    {
        dropPercentage =
            ((double)droppedPackets / totalPackets) * 100;
    }
    file << "Metric,Value\n";
    file << "Total Packets," << totalPackets << "\n";
    file << "Accepted Packets," << acceptedPackets << "\n";
    file << "Dropped Packets," << droppedPackets << "\n";
    file << "Total Bytes," << totalBytes << "\n";
    file << "Accepted Bytes," << acceptedBytes << "\n";
    file << fixed << setprecision(2);
    file << "Drop Percentage," << dropPercentage << "\n";
    file.close();
}
