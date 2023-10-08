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
	int numOfPlaceForSleep; //То на чём можно спать в этой комнате(диван/кровать и т.д.)
};

typedef enum BathroomWallTypes { Плитка, Стандартные,};

typedef enum BathroomWashTypes {Душ,Ванна};

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
	int numOfPlaceForSleep; //То на чём можно спать в этой комнате(диван/кровать и т.д.)
};

typedef enum BuildingStatus {Строится, Готова};

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