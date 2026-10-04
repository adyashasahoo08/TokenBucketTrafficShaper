#include <iostream>
#include <cassert>
#include "../include/Packet.h"
#include "../include/TokenBucket.h"
using namespace std;
int main()
{
    cout << "Running Token Bucket Tests...\n\n";
    TokenBucket bucket(1000, 100);
    Packet packet1(1, 400);
    bool result1 =
        bucket.processPacket(packet1);
    assert(result1 == true);
    cout << "Test 1 passed: Packet accepted.\n";
    Packet packet2(2, 700);
    bool result2 =
        bucket.processPacket(packet2);
    assert(result2 == false);
    cout << "Test 2 passed: Packet dropped.\n";
    bucket.addTokens(2);
    bool result3 =
        bucket.processPacket(packet2);
    assert(result3 == true);
    cout << "Test 3 passed: Packet accepted after tokens added.\n";
    cout << "\nAll tests passed successfully!\n";
    return 0;
}
