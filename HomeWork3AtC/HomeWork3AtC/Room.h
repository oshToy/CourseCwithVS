#ifndef __ROOM_H
#define __ROOM_H
#include <stdio.h>
typedef enum {PoolView=1,Balcon=2,
Kettle=4,Wifi=8,Sofa=16,TV=32,
Occupied=64}features;

typedef struct {
	int numberOfBeds;
	char features;
}Room;
void initRoom(Room* room);
void toStringRoom(Room* room);
void zeroOrOne(int* answer);
int isRoomHasThisFeature(Room* room, features feature);
void checkIfSpecficRoomsHasFeature(features feature, Room* room, ...);
#endif