#include <iostream>
#include "../include/queue.h"
#include "../include/packet.h"
#include "../include/generator.h"
#include <thread>
#include "../include/filter.h"


using namespace std;

int main()
{
    ThreadSafeQueue<DataPacket> q;
    double thresh;
    cout<<"enter the threshold value"<<endl;
    cin>>thresh;

    int T;
    cout<<"Enter the process time (>=100ns)"<<endl;
    cin>>T;


    thread t1(generator , ref(q), T);
    thread t2(filter, ref(q), thresh);
    t1.join();
    t2.join();

    // while(!q.empty()){
    //   DataPacket temp=q.top();
    //   q.pop();
    //   cout<<temp.p1<<" "<<temp.p2<<endl;

    // }

    // run filter (reads from queue)

    return 0;
}