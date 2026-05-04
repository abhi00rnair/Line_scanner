#include <iostream>
#include <vector>
#include "../include/filter.h"
#include "../include/packet.h"

using namespace std;

void filter(ThreadSafeQueue<DataPacket>& q, double thresh)
{
    deque<int> buffer;

    double weights[9] = {
        0.00025177,
        0.008666992,
        0.078025818,
        0.24130249,
        0.343757629,
        0.24130249,
        0.078025818,
        0.008666992,
        0.000125885
    };

    // double TV = 50.0;

    while(true)
    {
        DataPacket p = q.pop();
        if(p.isend){
            break;
        }

        buffer.push_back(p.p1);
        buffer.push_back(p.p2);

        while(buffer.size() >= 9)
        {
            double result = 0;

            for(int i=0;i<9;i++)
                result += buffer[i] * weights[i];

            int out = (result >= thresh) ? 1 : 0;

            // output_stream.push_back(out);
            cout<<out<<endl;

            buffer.pop_front();
        }
    }
    
}