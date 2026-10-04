## Token-Bucket Network Bandwidth Shaper & Traffic Policer
1. Introduction
Good morning/afternoon.
My project title is **Token-Bucket Network Bandwidth Shaper and Traffic Policer**.
This project is developed using **C++** and belongs to **Domain 3: Networking, Firewalls and Traffic Control**.
The main purpose of this project is to control network traffic using the Token-Bucket algorithm.
2. Show the Project Structure
First, I will show the project structure.
The project contains:

* `include` – header files
* `src` – C++ implementation files
* `tests` – test program
* `data` – generated traffic statistics
* `docs` – project documentation
* `README.md` – project information
* `.gitignore` – files excluded from Git
3. Run the Application
Now I will demonstrate the application.
I run:

```bash
./traffic_shaper
```

The program asks for three inputs:

* Bucket capacity
* Token generation rate
* Number of packets

For example, I can enter:

```text
Bucket capacity: 5000
Token generation rate: 1000
Number of packets: 20
```

The system then generates packets with different sizes and processes them using the Token-Bucket algorithm.

---

### 4. Explain Packet Processing

Here we can see the packet processing results.

For example:

```text
Packet 1 | Size: 500 bytes | ACCEPTED
Packet 2 | Size: 800 bytes | ACCEPTED
Packet 3 | Size: 900 bytes | DROPPED
```

When enough tokens are available, the packet is **accepted**, and its size is deducted from the available tokens.

When there are not enough tokens, the packet is **dropped**.

The available token count is also displayed after each packet.

---

5. Show Traffic Statistics

After processing all packets, the application displays the traffic statistics.

For example:

```text
Total Packets       : 20
Accepted Packets    : 4
Dropped Packets     : 16
Total Bytes         : 10797
Accepted Bytes      : 1907
Drop Percentage     : 80.00%
```

These statistics help us understand how effectively the traffic-control mechanism is working.

---

6. Show CSV Output

The program also saves the statistics into:

```text
data/traffic_statistics.csv
```

This file contains the calculated traffic metrics and can be used for further analysis.

---

### 7. Demonstrate Unit Testing

Now I will demonstrate the unit tests.

I run:

```bash
./test_token_bucket
```

The test checks:

1. Whether a packet is accepted when enough tokens are available.
2. Whether a packet is dropped when tokens are insufficient.
3. Whether a packet can be accepted after additional tokens are generated.

The output is:

```text
Test 1 passed: Packet accepted.
Test 2 passed: Packet dropped.
Test 3 passed: Packet accepted after tokens added.

All tests passed successfully!
```

This confirms that the core Token-Bucket functionality is working correctly.

---
8. Show GitHub

Finally, I will show the GitHub repository.

The repository contains the complete source code, tests, documentation, README, and project files.

This makes the project easy to understand, execute, and maintain.

Closing
To conclude, this project demonstrates how the Token-Bucket algorithm can be used for network traffic control.

The current implementation performs traffic policing by accepting packets when sufficient tokens are available and dropping packets when tokens are insufficient.

As future work, I can implement a packet queue for true traffic shaping, along with throughput, queue-length, and packet-delay measurements.

Thank you.

