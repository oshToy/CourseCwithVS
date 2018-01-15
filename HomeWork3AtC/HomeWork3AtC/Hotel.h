#ifndef __HOTEL_H
#define __HOTEL_H
#define HOTEL_FILE_NAME   "hotel_data"
#define  MIN_NUMBER_OF_FLOORS 1
#define  MIN_NUMBER_OF_ROOMS 1
#define  ROOMS_GAP_BETWEEN_FLOORS 100
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "encryption.h"
#pragma warning(disable: 4996)

typedef struct {
	int numberOfFloors;
	int numberOfRoomsPerFloor;
	Room** roomsMatrix;

}Hotel;
void initHotel(Hotel* hotel);
void freeHotel(Hotel* hotel);
void encryptHotel(Hotel* hotel);
void saveHotelToBinaryFile(Hotel* hotel, int numberOfFloors, int numberOfRooms);
void showHotelStatus(Hotel* hotel);
void checkFreeRoomsByFeature(Hotel* hotel);
void printFreeRoomThatContainFeature(Hotel* hotel, features feature);
void loadHotelFromEncryptFile(Hotel* hotel, char* binaryFileName, char* textFileName);
#endif
