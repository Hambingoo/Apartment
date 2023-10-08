#pragma once
#include <malloc.h>
#include <string.h>
#include <stdlib.h>


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

typedef enum BathroomWallTypes { ������, �����������,};

typedef enum BathroomWashTypes {���,�����};

typedef struct Bathroom
{
	char* floor;
	char* ceil;
	BathroomWallTypes type;
	BathroomWashTypes type;
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
	char street;
};