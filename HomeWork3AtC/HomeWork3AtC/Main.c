#include "Hotel.h"

void  main(int  argc, char*  argv[]) {

	Hotel hotel;
	if (argc > 1) {
		loadHotelFromEncryptFile(&hotel, argv[1]);
	}
	initHotel(&hotel);
	if (hotel.numberOfRoomsPerFloor > 2) {//2e
		checkIfSpecficRoomsHasFeature(Balcon, &(hotel.roomsMatrix[0][0]), &hotel.roomsMatrix[0][2], &hotel.roomsMatrix[0][3], NULL);

	}
	int choise = 0;
	while (choise != -1) {
		printf("press  '1' , to show hotel status\n");
		printf("press  '2' , to show free rooms by feature\n");
		printf("press '-1' , to exit \n");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1: {
			showHotelStatus(&hotel);//2b
			break;
		}
		case 2: {
			checkFreeRoomsByFeature(&hotel);//2d
			break;
		}

		}
	}
		encryptHotel(&hotel);
		saveHotelToBinaryFile(&hotel);
		freeHotel(&hotel);
		printf("Good Bye!\n");
		system("pause");



	}
