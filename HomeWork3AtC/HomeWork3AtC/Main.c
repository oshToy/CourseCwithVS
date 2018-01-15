#include "Hotel.h"
#
void  main(int  argc, char*  argv[]) {

	Hotel hotel;
	if (argc == 2) {//Q6 if aregv[1] exist or no
		loadHotelFromEncryptFile(&hotel, argv[1], ENCRYPT_TEXT_FILE_NAME);
	}
	else {
		initHotel(&hotel);
	}
	if (hotel.numberOfRoomsPerFloor > 2) {//2e
		checkIfSpecficRoomsHasFeature(Balcon, &(hotel.roomsMatrix[0][0]), &hotel.roomsMatrix[0][1], &hotel.roomsMatrix[0][2], NULL);
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
	freeHotel(&hotel);
	printf("Good Bye!\n");
	system("pause");



}
