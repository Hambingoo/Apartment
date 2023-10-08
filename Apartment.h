#pragma once
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define LENGHT 25


typedef struct Kitchen
{
	char* floor;
	char* ceil;

};

typedef struct Hall
{
	char* floor;
	char* ceil;
	int numOfPlaceForSleep; //�� �� ��� ����� ����� � ���� �������(�����/������� � �.�.)
};

typedef enum BathroomWallTypes { ������,�����������};

typedef enum BathroomWashTypes {���,�����};

typedef struct Bathroom
{
	char* floor;
	char* ceil;
	BathroomWallTypes walltype;
	BathroomWashTypes washtype;
};


typedef struct SleepingRooms
{
	char* floor;
	char* ceil;
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
		kitchen->floor = (char*)calloc(LENGHT, sizeof(char));
		kitchen->ceil = (char*)calloc(LENGHT, sizeof(char));
		strcpy(kitchen->ceil, ceil);
		strcpy(kitchen->floor, floor);
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
		hall->floor = (char*)calloc(LENGHT, sizeof(char));
		hall->ceil = (char*)calloc(LENGHT, sizeof(char));
		hall->numOfPlaceForSleep = numOfPlaceForSleep;
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
		bathroom->floor = (char*)calloc(LENGHT, sizeof(char));
		bathroom->ceil = (char*)calloc(LENGHT, sizeof(char));
		bathroom->walltype = walltype;
		bathroom->washtype = washtype;
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
		sleepingRooms->floor = (char*)calloc(LENGHT, sizeof(char));
		sleepingRooms->ceil = (char*)calloc(LENGHT, sizeof(char));
		sleepingRooms->numOfPlaceForSleep = numOfPlaceForSleep;
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
	if (numOfRooms >= 0 && floor > 0 && housenum > 0 && square > 0 && strlen(street) > 0 &&status>��������&&status<������)
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
	char* floor = (char*)calloc(LENGHT, sizeof(char));
	char* ceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\t���� ���������� �����\n");
	printf("������� �������� ����: ");
	gets_s(floor, LENGHT);
	printf("������� �������� �������: ");
	gets_s(ceil, LENGHT);
	while (getchar() != '\n');
	return CreateKitchen(floor, ceil);

}



Hall* InputHall()
{
	int numOfPlaceForSleep;
	char* floor = (char*)calloc(LENGHT, sizeof(char));
	char* ceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\t���� ���������� ����\n");
	printf("������� �������� ����: ");
	gets_s(floor, LENGHT);
	printf("������� �������� �������: ");
	gets_s(ceil, LENGHT);
	printf("������� ���-�� ���� ��� ���(�����/�������): ");
	scanf("%d", &numOfPlaceForSleep);
	while (getchar() != '\n');
	return CreateHall(floor, ceil, numOfPlaceForSleep);
}


Bathroom* InputBathroom()
{
	char* floor = (char*)calloc(LENGHT, sizeof(char));
	char* ceil = (char*)calloc(LENGHT, sizeof(char));
	BathroomWallTypes walltype;
	BathroomWashTypes washtype;

	printf("\t���� ���������� ������ �������\n");
	printf("������� �������� ����: ");
	gets_s(floor, LENGHT);
	printf("������� �������� �������: ");
	gets_s(ceil, LENGHT);
	printf("�������")

}