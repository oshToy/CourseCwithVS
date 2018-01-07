#ifndef __HOTEL_H
#define __HOTEL_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "encryption.h"

typedef struct {
	int numberOfFloors;
	int numberOfRoomsPerFloor;
	Room** roomsMatrix;

}Hotel;
void initHotel(Hotel* hotel);
void freeHotel(Hotel* hotel);
void showHotelStatus(Hotel* hotel);
void checkFreeRoomsByFeature(Hotel* hotel);
void printFreeRoomThatContainFeature(Hotel* hotel, features feature);
#endif
