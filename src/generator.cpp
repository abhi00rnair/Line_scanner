#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "../include/packet.h"
#include "../include/queue.h"
#include <chrono>
#include <thread>


using namespace std;

void generator(ThreadSafeQueue<DataPacket>& q, int T){
  ifstream file("../data/sample.csv");
  // vector<vector<int>>pixels;

string line;
vector<int> buffer;

while(getline(file, line)) {
    stringstream ss(line);
    string val;

    while(getline(ss, val, ',')) {
        buffer.push_back(stoi(val));

        if(buffer.size() == 2) {
            DataPacket p;
            p.p1 = buffer[0];
            p.p2 = buffer[1];

            q.push(p);
            this_thread::sleep_for(chrono::milliseconds(T));

            buffer.clear();
        }
    }
}
  DataPacket endpack;
  endpack.isend=true;
  q.push(endpack);


}