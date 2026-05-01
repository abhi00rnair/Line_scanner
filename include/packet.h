#ifndef PACKET_H
#define PACKET_H

struct DataPacket
{
 int p1;
 int p2;

 int row1;
 int colo1;

 int row2;
 int colo2;

 bool isend=false; // for indicating the lsst packet
};

#endif