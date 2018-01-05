#include "Hotel.h"

int main() {

		Hotel hotel;
		initHotel(&hotel);
		if(hotel.numberOfRoomsPerFloor>2){//2e
		checkIfSpecficRoomsHasFeature(Balcon, &(hotel.roomsMatrix[0][0]), &hotel.roomsMatrix[0][2], &hotel.roomsMatrix[0][3],NULL);
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
				showHotelStatus(&hotel);
				break;
			}
			case 2: {
				checkFreeRoomsByFeature(&hotel);

				break;
			}
			case 3: {

				break;
			}
			case 4: {

				break;
			}
			case 5: {

				break;
			}
			case 6: {
				
				break;
			}
			case 7: {
				
				break;
			}

			}
		}
		freeHotel(&hotel);
		printf("Good Bye!");
		system("pause");
	
   
	
}
