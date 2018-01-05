#include "Hotel.h"

void initHotel(Hotel* hotel) {//2a
	int numerOfFloors;
	int numerOfRooms;
	do {
		printf("Welcome, how many floors there are in the hotel? ");
		scanf("%d", &numerOfFloors);
		printf("OK, and how many rooms there are in the hotel? ");
		scanf("%d", &numerOfRooms);
	} while (numerOfFloors < 1 || numerOfRooms < 1);
	hotel->numberOfFloors = numerOfFloors;
	hotel->numberOfRoomsPerFloor = numerOfRooms;


	hotel->roomsMatrix = (Room**)malloc(numerOfFloors * sizeof(Room*));
	if (!hotel->roomsMatrix) // ( == NULL) --> allocaton didn't succeed
	{
		printf("ERROR! Out of memory!\n");
		return;
	}
	for (int i = 0; i < numerOfFloors; i++) {
		hotel->roomsMatrix[i] = (Room*)calloc(numerOfRooms, sizeof(Room));
		for (int j = 0; j < numerOfRooms; j++) {
			printf("Please fill details of room : %d\n", ((i + 1) * 100) + j);
			initRoom(&(hotel->roomsMatrix[i][j]));
		}
		if (!hotel->roomsMatrix[i]) // ( == NULL) --> allocaton didn't succeed
		{
			printf("ERROR! Out of memory!\n");
			return;
		}
	}
}
	void freeHotel(Hotel* hotel) {
		for (int i = 0; i < hotel->numberOfFloors; i++) {
			free(hotel->roomsMatrix[i]);
		}
		free(hotel->roomsMatrix);

	}

	void showHotelStatus(Hotel* hotel) {//2b

		for (int i = 0; i < hotel->numberOfFloors; i++)
		{

			for (int j = 0; j < hotel->numberOfRoomsPerFloor; j++)
			{
				printf("Details of room number : %d\n", ((i + 1) * 100) + j);
				toStringRoom(&(hotel->roomsMatrix[i][j]));
			}
		}
	}
	void checkFreeRoomsByFeature(Hotel* hotel) {//2d input
		int choise = 0;
		printf("to print all free rooms that has pool view press  '1'\n");
		printf("to print all free rooms that has balcon press  '2'\n" );
		printf("to print all free rooms that has kettle press  '3'\n" );
		printf("to print all free rooms that has Wifi press  '4'\n");
		printf("to print all free rooms that  has sofa press  '5'\n" );
		printf("to print all free rooms that has TV press  '6'\n");
		printf("to print all free rooms that occupied press  '7'\n");
		do{
		printf("Please enter your choise :\n");
		scanf("%d", &choise);
		} while (choise<1 || choise>7);

		int res = 1;//feature=2^(choise-1)
		for (int i = 0; i < choise - 1; i++){
			res *= 2;
		}
		printFreeRoomThatContainFeature(hotel,res);
		{

		}
	}
	void printFreeRoomThatContainFeature(Hotel* hotel, features feature) {//2d
		int noRooms = 1;
		for (int i = 0; i < hotel->numberOfFloors; i++)
		{

			for (int j = 0; j < hotel->numberOfRoomsPerFloor; j++)
			{
				int isContainFeature = isRoomHasThisFeature(&hotel->roomsMatrix[i][j], feature);
				int isOccupied = isRoomHasThisFeature(&hotel->roomsMatrix[i][j], Occupied);
				if(isContainFeature&&!isOccupied){
				noRooms = 0;
				printf("Details of room number : %d\n", ((i + 1) * 100) + j);
				toStringRoom(&(hotel->roomsMatrix[i][j]));
				}
			}
		}
		if (noRooms) {
			printf("No room avaliable with this feature\n");
		}
	}