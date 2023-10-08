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
	int numOfPlaceForSleep; //То на чём можно спать в этой комнате(диван/кровать и т.д.)
};

typedef enum BathroomWallTypes { Плитка,Стандартные};

typedef enum BathroomWashTypes {Душ,Ванна};

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
	char* street;
};


//функция для перевода BathroomWallTypes в строку
char* BathroomWallTypetostring(BathroomWallTypes type)
{
	char* strType = (char*)calloc(LENGHT, sizeof(char));
	
	switch (type)
	{
	case Плитка:
		strcpy(strType, "Плитка");
		break;
	case Стандартные:
		strcpy(strType, "Стандартные");
		break;
	default:
		break;
	}
	return strType;
}

//функция для перевода BathroomWashTypes в строку
char* BathroomWashTypetostring(BathroomWashTypes type)
{
	char* strType = (char*)calloc(LENGHT, sizeof(char));

	switch (type)
	{
	case Душ:
		strcpy(strType, "Душ");
		break;
	case Ванна:
		strcpy(strType, "Ванна");
		break;
	default:
		break;
	}
	return strType;
}

//функция для перевода BuildingStatus в строку
char* BuildingStatustostring(BuildingStatus type)
{
	char* strType = (char*)calloc(LENGHT, sizeof(char));

	switch (type)
	{
	case Строится:
		strcpy(strType, "Строится");
		break;
	case Готова:
		strcpy(strType, "Готова");
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
		printf("Неправильно введены данные! Выход...");
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
		printf("Неправильно введены данные! Выход...");
		exit(EXIT_SUCCESS);
	}
}

Bathroom* CreateBathroom(char* floor, char* ceil, BathroomWallTypes walltype, BathroomWashTypes washtype)
{
	if (strlen(floor) != 0 && strlen(ceil) != 0 && walltype >= Плитка && walltype <= Стандартные && washtype >= Душ && washtype <= Ванна)
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
		printf("Неправильно введены данные! Выход...");
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
		printf("Неправильно введены данные! Выход...");
		exit(EXIT_SUCCESS);
	}
}

Apartment* CreateApartment(Kitchen kitchen, Hall hall, Bathroom bathroom, SleepingRooms sleepingrooms, BuildingStatus status, int numOfRooms, int floor, int housenum, float square, char* street)
{
	if (numOfRooms >= 0 && floor > 0 && housenum > 0 && square > 0 && strlen(street) > 0 &&status>Строится&&status<Готова)
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
		printf("Неправильно введены данные! Выход...");
		exit(EXIT_SUCCESS);
	}
}



Kitchen* InputKitchen()
{
	char* floor = (char*)calloc(LENGHT, sizeof(char));
	char* ceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\tВвод параметров кухни\n");
	printf("Введите материал пола: ");
	gets_s(floor, LENGHT);
	printf("Введите материал потолка: ");
	gets_s(ceil, LENGHT);
	while (getchar() != '\n');
	return CreateKitchen(floor, ceil);

}



Hall* InputHall()
{
	int numOfPlaceForSleep;
	char* floor = (char*)calloc(LENGHT, sizeof(char));
	char* ceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\tВвод параметров Зала\n");
	printf("Введите материал пола: ");
	gets_s(floor, LENGHT);
	printf("Введите материал потолка: ");
	gets_s(ceil, LENGHT);
	printf("Введите кол-во мест для сна(Диван/Кровать): ");
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

	printf("\tВвод параметров Ванной комнаты\n");
	printf("Введите материал пола: ");
	gets_s(floor, LENGHT);
	printf("Введите материал потолка: ");
	gets_s(ceil, LENGHT);
	printf("Введите")

}