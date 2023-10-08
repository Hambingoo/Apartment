#pragma once
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define LENGHT 25


typedef struct Kitchen
{
	char* kitchenfloor;
	char* kitchenceil;

};

typedef struct Hall
{
	char* hallfloor;
	char* hallceil;
	int numOfPlaceForSleep; //�� �� ��� ����� ����� � ���� �������(�����/������� � �.�.)
};

typedef enum BathroomWallTypes { ������,�����������};

typedef enum BathroomWashTypes {���,�����};

typedef struct Bathroom
{
	char* bathroomfloor;
	char* bathroomceil;
	BathroomWallTypes walltype;
	BathroomWashTypes washtype;
};


typedef struct SleepingRooms
{
	char* sleepingroomsfloor;
	char* sleepingroomsceil;
	int numOfPlaceForSleep; //�� �� ��� ����� ����� � ���� �������(�����/������� � �.�.)
};

typedef enum BuildingStatus {��������, ������};

typedef struct Apartment
{
	Kitchen kitchen;
	Hall hall;
	Bathroom bathroom;
	SleepingRooms sleepingrooms;
	BuildingStatus status;
	int numOfRooms, floor, housenum;
	float square;
	char* street;
};


//������� ��� �������� BathroomWallTypes � ������
char* BathroomWallTypetostring(BathroomWallTypes type)
{
	char* strType = (char*)calloc(LENGHT, sizeof(char));
	
	switch (type)
	{
	case ������:
		strcpy(strType, "������");
		break;
	case �����������:
		strcpy(strType, "�����������");
		break;
	default:
		break;
	}
	return strType;
}

//������� ��� �������� BathroomWashTypes � ������
char* BathroomWashTypetostring(BathroomWashTypes type)
{
	char* strType = (char*)calloc(LENGHT, sizeof(char));

	switch (type)
	{
	case ���:
		strcpy(strType, "���");
		break;
	case �����:
		strcpy(strType, "�����");
		break;
	default:
		break;
	}
	return strType;
}

//������� ��� �������� BuildingStatus � ������
char* BuildingStatustostring(BuildingStatus type)
{
	char* strType = (char*)calloc(LENGHT, sizeof(char));

	switch (type)
	{
	case ��������:
		strcpy(strType, "��������");
		break;
	case ������:
		strcpy(strType, "������");
		break;
	default:
		break;
	}
	return strType;
}

Kitchen* CreateKitchen(char* floor, char* ceil)
{
	if (strlen(floor) != 0 && strlen(ceil) != 0)
	{
		Kitchen* kitchen = (Kitchen*)calloc(1, sizeof(Kitchen));
		kitchen->kitchenfloor = (char*)calloc(LENGHT, sizeof(char));
		kitchen->kitchenceil = (char*)calloc(LENGHT, sizeof(char));
		strcpy(kitchen->kitchenceil, ceil);
		strcpy(kitchen->kitchenfloor, floor);
		return kitchen;
	}
	else
	{
		printf("����������� ������� ������! �����...");
		exit(EXIT_SUCCESS);
	}
}

Hall* CreateHall(char* floor, char* ceil, int numOfPlaceForSleep) 
{
	if (strlen(floor) != 0 && strlen(ceil) != 0 && numOfPlaceForSleep >= 0)
	{
		Hall* hall = (Hall*)calloc(1, sizeof(Hall));
		hall->hallfloor = (char*)calloc(LENGHT, sizeof(char));
		hall->hallceil = (char*)calloc(LENGHT, sizeof(char));
		hall->numOfPlaceForSleep = numOfPlaceForSleep;
		strcpy(hall->hallceil, ceil);
		strcpy(hall->hallfloor, floor);
		return hall;
	}
	else
	{
		printf("����������� ������� ������! �����...");
		exit(EXIT_SUCCESS);
	}
}

Bathroom* CreateBathroom(char* floor, char* ceil, BathroomWallTypes walltype, BathroomWashTypes washtype)
{
	if (strlen(floor) != 0 && strlen(ceil) != 0 && walltype >= ������ && walltype <= ����������� && washtype >= ��� && washtype <= �����)
	{
		Bathroom* bathroom = (Bathroom*)calloc(1, sizeof(Bathroom));
		bathroom->bathroomfloor = (char*)calloc(LENGHT, sizeof(char));
		bathroom->bathroomceil = (char*)calloc(LENGHT, sizeof(char));
		bathroom->walltype = walltype;
		bathroom->washtype = washtype;
		strcpy(bathroom->bathroomceil, ceil);
		strcpy(bathroom->bathroomfloor, floor);
		return bathroom;
	}
	else
	{
		printf("����������� ������� ������! �����...");
		exit(EXIT_SUCCESS);
	}
}

SleepingRooms* CreateSleepRooms(char* floor, char* ceil, int numOfPlaceForSleep)
{
	if (strlen(floor) != 0 && strlen(ceil) != 0 && numOfPlaceForSleep >= 0)
	{
		SleepingRooms* sleepingRooms = (SleepingRooms*)calloc(1, sizeof(SleepingRooms));
		sleepingRooms->sleepingroomsfloor = (char*)calloc(LENGHT, sizeof(char));
		sleepingRooms->sleepingroomsceil = (char*)calloc(LENGHT, sizeof(char));
		sleepingRooms->numOfPlaceForSleep = numOfPlaceForSleep;
		strcpy(sleepingRooms->sleepingroomsceil, ceil);
		strcpy(sleepingRooms->sleepingroomsfloor, floor);
		return sleepingRooms;
	}
	else
	{
		printf("����������� ������� ������! �����...");
		exit(EXIT_SUCCESS);
	}
}

Apartment* CreateApartment(Kitchen kitchen, Hall hall, Bathroom bathroom, SleepingRooms sleepingrooms, BuildingStatus status, int numOfRooms, int floor, int housenum, float square, char* street)
{
	if (numOfRooms >= 0 && floor > 0 && housenum > 0 && square > 0 && strlen(street) > 0 &&status>=��������&&status<=������)
	{
		Apartment* apartment = (Apartment*)calloc(1, sizeof(Apartment));
		apartment->street = (char*)calloc(LENGHT, sizeof(char));
		strcpy(apartment->street, street);
		apartment->kitchen = kitchen;
		apartment->hall = hall;
		apartment->bathroom = bathroom;
		apartment->sleepingrooms = sleepingrooms;
		apartment->status = status;
		apartment->floor = floor;
		apartment->numOfRooms = numOfRooms;
		apartment->housenum = housenum;
		apartment->square = square;
	}
	else
	{
		printf("����������� ������� ������! �����...");
		exit(EXIT_SUCCESS);
	}
}



Kitchen* InputKitchen()
{
	char* kitchenfloor = (char*)calloc(LENGHT, sizeof(char));
	char* kitchenceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\t���� ���������� �����\n");
	printf("������� �������� ����: ");
	gets_s(kitchenfloor, LENGHT);
	printf("������� �������� �������: ");
	gets_s(kitchenceil, LENGHT);
	return CreateKitchen(kitchenfloor, kitchenceil);

}



Hall* InputHall()
{
	int numOfPlaceForSleep;
	char* hallfloor = (char*)calloc(LENGHT, sizeof(char));
	char* hallceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\t���� ���������� ����\n");
	printf("������� �������� ����: ");
	gets_s(hallfloor, LENGHT);
	printf("������� �������� �������: ");
	gets_s(hallceil, LENGHT);
	printf("������� ���-�� ���� ��� ���(�����/�������): ");
	scanf("%d", &numOfPlaceForSleep);
	while (getchar() != '\n');
	return CreateHall(hallfloor, hallceil, numOfPlaceForSleep);
}


Bathroom* InputBathroom()
{
	char* bathroomfloor = (char*)calloc(LENGHT, sizeof(char));
	char* bathroomceil = (char*)calloc(LENGHT, sizeof(char));
	BathroomWallTypes walltype;
	BathroomWashTypes washtype;

	printf("\t���� ���������� ������ �������\n");
	printf("������� �������� ����: ");
	gets_s(bathroomfloor, LENGHT);
	printf("������� �������� �������: ");
	gets_s(bathroomceil, LENGHT);
	printf("������� ������� ����(������ - 0, ����������� - 1): ");
	scanf("%d", &walltype);
	printf("������� �������� ��� �����(��� - 0, ����� - 1): ");
	scanf("%d", &washtype);
	while (getchar() != '\n');
	return CreateBathroom(bathroomfloor, bathroomceil, walltype, washtype);
}

SleepingRooms* InputSleepRooms()
{
	int numOfPlaceForSleep;
	char* sleepingroomsfloor = (char*)calloc(LENGHT, sizeof(char));
	char* sleepingroomsceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\t���� ���������� �������� ������\n");
	printf("������� �������� ����: ");
	gets_s(sleepingroomsfloor, LENGHT);
	printf("������� �������� �������: ");
	gets_s(sleepingroomsceil, LENGHT);
	printf("������� ���-�� ���� ��� ���(�����/�������): ");
	scanf("%d", &numOfPlaceForSleep);
	while (getchar() != '\n');
	return CreateSleepRooms(sleepingroomsfloor, sleepingroomsceil, numOfPlaceForSleep);
}


Apartment* InputApartment()
{
	printf("\t���� ���������� ��������\n");
	int numOfRooms, floor, housenum; 
	float square;
	char* street = (char*)calloc(LENGHT, sizeof(char));
	printf("������� �������� �����: ");
	gets_s(street, LENGHT);
	printf("������� ������ ����: ");
	scanf("%d", &housenum);
	printf("������� ����� �����: ");
	scanf("%d", &floor);
	printf("������� ������� ��������: ");
	scanf("%f", &square);
	printf("������� ���-�� ������: ");
	scanf("%d", &numOfRooms);
	BuildingStatus status;
	printf("������� ������(�������� - 0, ������ - 1): ");
	scanf("%d", &status);
	while (getchar() != '\n');
	return CreateApartment(*InputKitchen(), *InputHall(), *InputBathroom(), *InputSleepRooms(), status, numOfRooms, floor, housenum, square, street);

}

void PrintApartmentInfo(Apartment apartment)
{
	printf("\t\t���������� � ��������\n");
	printf("������: %s\n", BuildingStatustostring(apartment.status));
	printf("����� %s, ��� %d, ���� %d\n", apartment.street, apartment.housenum,apartment.floor);
	printf("�������: %f\n���-�� ������: %d\n", apartment.square, apartment.numOfRooms);
	
	printf("\t���\n�������� ����: %s\n�������: %s\n���-�� �������� ����: %d\n", apartment.hall.hallfloor, apartment.hall.hallceil,apartment.hall.numOfPlaceForSleep);
	printf("\t�����\n�������� ����: %s\n�������: %s\n", apartment.kitchen.kitchenfloor, apartment.kitchen.kitchenceil);
	printf("\t������ �������\n�������� ����: %s\n�������: %s\n������� ����: %s\n�������� ��� �����: %s\n", apartment.bathroom.bathroomfloor, apartment.bathroom.bathroomceil,BathroomWallTypetostring(apartment.bathroom.walltype),BathroomWashTypetostring(apartment.bathroom.washtype));
	printf("\t�������� �������\n�������� ����: %s\n�������: %s\n���-�� �������� ����: %d\n", apartment.sleepingrooms.sleepingroomsfloor, apartment.sleepingrooms.sleepingroomsceil, apartment.sleepingrooms.numOfPlaceForSleep);

}



void ChangeStatus(Apartment* apartment, BuildingStatus newStatus)
{
	if (newStatus >= �������� && newStatus <= ������)
	{
		apartment->status = newStatus;
		printf("��������� �������� ��������!\n");
	}
	else
	{
		printf("����������� ������� ������! �����...");
		exit(EXIT_SUCCESS);
	}
}