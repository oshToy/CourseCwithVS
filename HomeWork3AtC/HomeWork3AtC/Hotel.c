#include "Hotel.h"

void initHotel(Hotel* hotel) {//2a
	int numerOfFloors;
	int numerOfRooms;
	do {
		printf("Welcome, how many floors there are in the hotel? ");
		scanf("%d", &numerOfFloors);
		printf("OK, and how many rooms there are in the hotel? ");
		scanf("%d", &numerOfRooms);
	} while (numerOfFloors < MIN_NUMBER_OF_FLOORS || numerOfRooms < MIN_NUMBER_OF_ROOMS);
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
			printf("Please fill details of room : %d\n", ((i + 1) * ROOMS_GAP_BETWEEN_FLOORS) + j);
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
	printf("to print all free rooms that has balcon press  '2'\n");
	printf("to print all free rooms that has kettle press  '3'\n");
	printf("to print all free rooms that has Wifi press  '4'\n");
	printf("to print all free rooms that  has sofa press  '5'\n");
	printf("to print all free rooms that has TV press  '6'\n");
	do {
		printf("Please enter your choise :\n");
		scanf("%d", &choise);
	} while (choise < 1 || choise>6);

	int res = 1;//feature=2^(choise-1)
	for (int i = 0; i < choise - 1; i++) {
		res *= 2;
	}
	printFreeRoomThatContainFeature(hotel, res);
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
			if (isContainFeature && !isOccupied) {
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
void encryptHotel(Hotel* hotel) {//Q5

	FILE *file = fopen(ENCRYPT_TEXT_FILE_NAME, "w");
	if (file == NULL)//check if open file failed
	{
		printf("Failed opening the file. Exiting!\n");
		return;
	}


	srand((unsigned)time(NULL));
	int x = rand() % NUMBERS_RANGE;
	fprintf(file, "%d", x);
	fclose(file);
	printf("%d", x);
	int numberOfFloors = hotel->numberOfFloors;//need to know true size
	int numberOfRooms = hotel->numberOfRoomsPerFloor;//need to know true size
	for (int i = 0; i < hotel->numberOfFloors; i++)
	{
		encrypt(hotel->roomsMatrix[i], sizeof(Room)*(hotel->numberOfRoomsPerFloor), x);

	}
	encrypt(&hotel->numberOfFloors, sizeof(int), x);
	encrypt(&hotel->numberOfRoomsPerFloor, sizeof(int), x);
	saveHotelToBinaryFile(hotel, numberOfFloors, numberOfRooms);
}
void saveHotelToBinaryFile(Hotel* hotel, int numberOfFloors, int numberOfRooms) {//q5

	FILE *file = fopen(HOTEL_FILE_NAME, "wb");
	if (file == NULL)//check if open file failed
	{
		printf("Failed opening the file. Exiting!\n");
		return;
	}

	fwrite(&hotel->numberOfFloors, sizeof(int), 1, file);
	fwrite(&hotel->numberOfRoomsPerFloor, sizeof(int), 1, file);

	for (int i = 0; i < numberOfFloors; i++)
	{
		fwrite(hotel->roomsMatrix[i], sizeof(Room), numberOfRooms, file);
	}
	fclose(file);



}
void loadHotelFromEncryptFile(Hotel* hotel, char* HotelBinaryfileName, char* xTextfileName) {//q6
	FILE *textFile = fopen(xTextfileName, "r");//read x
	if (textFile == NULL)//check if open file failed
	{
		printf("Failed opening the file. Exiting!\n");
		return;
	}
	int x = 0;
	fscanf(textFile, "%d", &x);
	fclose(textFile);

	FILE* binaryFile = fopen(HotelBinaryfileName, "rb");//read binary hotel data
	if (binaryFile == NULL)//check if open file failed
	{
		printf("Failed opening the file. Exiting!\n");
		return;
	}

	printf("x  = %d ", x);
	fread(&(hotel->numberOfFloors), sizeof(int), 1, binaryFile);//READ NUMBER OF FLOOR
	decrypt(&hotel->numberOfFloors, sizeof(int), x);//decrypt NUMBER OF FLOOR
	fread(&hotel->numberOfRoomsPerFloor, sizeof(int), 1, binaryFile);//READ NUMBER OF ROOMS PER FLOOR
	decrypt(&hotel->numberOfRoomsPerFloor, sizeof(int), x);//decrypt NUMBER OF ROOMS PER FLOOR

	hotel->roomsMatrix = (Room**)malloc(sizeof(Room*)*(hotel->numberOfFloors));
	for (int i = 0; i < hotel->numberOfFloors; i++) {
		hotel->roomsMatrix[i] = (Room*)calloc(hotel->numberOfRoomsPerFloor, sizeof(Room));
		fread(hotel->roomsMatrix[i], sizeof(Room), hotel->numberOfRoomsPerFloor, binaryFile);
		decrypt(hotel->roomsMatrix[i], sizeof(Room)*(hotel->numberOfRoomsPerFloor), x);//decrypt NUMBER OF FLOOR
	}

	fclose(binaryFile);
}