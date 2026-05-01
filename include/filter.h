#ifndef FILTER_H
#define FILTER_H

#include "queue.h"
#include "packet.h"

void filter(ThreadSafeQueue<DataPacket>& q, double thresh);

#endif