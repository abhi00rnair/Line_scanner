#ifndef GENERATOR_H
#define GENERATOR_H

#include "queue.h"
#include "packet.h"

void generator(ThreadSafeQueue<DataPacket>& q,int T);

#endif