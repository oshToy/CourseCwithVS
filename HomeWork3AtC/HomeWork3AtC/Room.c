#include "Room.h"

void initRoom(Room * room)//1a
{
	char byteOfFeatures = 0;
	int answer = FALSE;
	do {
		printf("How many beds in the room ?\n");
		scanf("%d", &room->numberOfBeds);
	} while (room->numberOfBeds < MIN_NUMBER_OF_BEDS);
	printf("there is a pool view in the room '0'-false '1'-true  ?\n");
	zeroOrOne(&answer);
	if (answer == TRUE) {
		byteOfFeatures = byteOfFeatures | PoolView;
	}
	printf("there is a balcon in the room '0'-false '1'-true  ?\n");
	zeroOrOne(&answer);
	if (answer == TRUE) {
		byteOfFeatures = byteOfFeatures | Balcon;
	}
	printf("there is a kettle in the room '0'-false '1'-true  ?\n");
	zeroOrOne(&answer);
	if (answer == TRUE) {
		byteOfFeatures = byteOfFeatures | Kettle;
	}
	printf("there is a Wifi in the room '0'-false '1'-true  ?\n");
	zeroOrOne(&answer);
	if (answer == TRUE) {
		byteOfFeatures = byteOfFeatures | Wifi;
	}
	printf("there is a sofa in the room '0'-false '1'-true  ?\n");
	zeroOrOne(&answer);
	if (answer == TRUE) {
		byteOfFeatures = byteOfFeatures | Sofa;
	}
	printf("there is a TV in the room '0'-false '1'-true  ?\n");
	zeroOrOne(&answer);
	if (answer == TRUE) {
		byteOfFeatures = byteOfFeatures | TV;
	}
	printf("there is a Occupied in the room '0'-false '1'-true  ?\n");
	zeroOrOne(&answer);
	if (answer == TRUE) {
		byteOfFeatures = byteOfFeatures | Occupied;
	}
	room->features = byteOfFeatures;
}

void toStringRoom(Room * room)//1b
{
	printf("the room has %d beds\n", room->numberOfBeds);

	printf("the room %s pool view \n", ((room->features&PoolView) == PoolView) ? "has" : "hasn't");
	printf("the room %s balcon\n", ((room->features&Balcon) == Balcon) ? "has" : "hasn't");
	printf("the room %s kettle\n", ((room->features&Kettle) == Kettle) ? "has" : "hasn't");
	printf("the room %s Wifi\n", ((room->features&Wifi) == Wifi) ? "has" : "hasn't");
	printf("the room %s sofa\n", ((room->features&Sofa) == Sofa) ? "has" : "hasn't");
	printf("the room %s TV\n", ((room->features&TV) == TV) ? "has" : "hasn't");
	printf("the room %s occupied\n", ((room->features&Occupied) == Occupied) ? "is" : "isn't");
}
void zeroOrOne(int* answer)
{
	int temp;
	while (1) {
		scanf("%d", &temp);
		if (temp == TRUE || temp == FALSE) {
			*answer = temp;
			return;
		}
		printf("Please enter valid input, 0 or 1 !    ");
	}
}
int isRoomHasThisFeature(Room* room, features feature) {//2c
	return ((room->features&feature) == feature) ? TRUE : FALSE;
}
void checkIfSpecficRoomsHasFeature(features feature, Room* room, ...) {//2e
	va_list allRooms;
	Room* ptrRoom = room;
	int noRooms = TRUE;
	va_start(allRooms, room);
	while (ptrRoom != NULL) {

		if (isRoomHasThisFeature(ptrRoom, feature)) {
			noRooms = FALSE;
			toStringRoom(ptrRoom);
		}
		ptrRoom = va_arg(allRooms, Room*);
	}
	va_end(allRooms);
	if (noRooms) {
		printf("No room avaliable with this feature\n");
	}

}