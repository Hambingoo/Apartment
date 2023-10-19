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
	int numOfPlaceForSleep; //То на чём можно спать в этой комнате(диван/кровать и т.д.)
};

typedef enum BathroomWallTypes { Плитка,Стандартные};

typedef enum BathroomWashTypes {Душ,Ванна};

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
		kitchen->kitchenfloor = (char*)calloc(LENGHT, sizeof(char));
		kitchen->kitchenceil = (char*)calloc(LENGHT, sizeof(char));
		strcpy(kitchen->kitchenceil, ceil);
		strcpy(kitchen->kitchenfloor, floor);
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
		hall->hallfloor = (char*)calloc(LENGHT, sizeof(char));
		hall->hallceil = (char*)calloc(LENGHT, sizeof(char));
		hall->numOfPlaceForSleep = numOfPlaceForSleep;
		strcpy(hall->hallceil, ceil);
		strcpy(hall->hallfloor, floor);
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
		printf("Неправильно введены данные! Выход...");
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
		printf("Неправильно введены данные! Выход...");
		exit(EXIT_SUCCESS);
	}
}

Apartment* CreateApartment(Kitchen kitchen, Hall hall, Bathroom bathroom, SleepingRooms sleepingrooms, BuildingStatus status, int numOfRooms, int floor, int housenum, float square, char* street)
{
	if (numOfRooms >= 0 && floor > 0 && housenum > 0 && square > 0 && strlen(street) > 0 &&status>=Строится&&status<=Готова)
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
	char* kitchenfloor = (char*)calloc(LENGHT, sizeof(char));
	char* kitchenceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\tВвод параметров кухни\n");
	printf("Введите материал пола: ");
	gets_s(kitchenfloor, LENGHT);
	printf("Введите материал потолка: ");
	gets_s(kitchenceil, LENGHT);
	return CreateKitchen(kitchenfloor, kitchenceil);

}



Hall* InputHall()
{
	int numOfPlaceForSleep;
	char* hallfloor = (char*)calloc(LENGHT, sizeof(char));
	char* hallceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\tВвод параметров Зала\n");
	printf("Введите материал пола: ");
	gets_s(hallfloor, LENGHT);
	printf("Введите материал потолка: ");
	gets_s(hallceil, LENGHT);
	printf("Введите кол-во мест для сна(Диван/Кровать): ");
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

	printf("\tВвод параметров Ванной комнаты\n");
	printf("Введите материал пола: ");
	gets_s(bathroomfloor, LENGHT);
	printf("Введите материал потолка: ");
	gets_s(bathroomceil, LENGHT);
	printf("Введите обделку стен(Плитка - 0, Стандартные - 1): ");
	scanf("%d", &walltype);
	printf("Введите средство для мытья(Душ - 0, Ванна - 1): ");
	scanf("%d", &washtype);
	while (getchar() != '\n');
	return CreateBathroom(bathroomfloor, bathroomceil, walltype, washtype);
}

SleepingRooms* InputSleepRooms()
{
	int numOfPlaceForSleep;
	char* sleepingroomsfloor = (char*)calloc(LENGHT, sizeof(char));
	char* sleepingroomsceil = (char*)calloc(LENGHT, sizeof(char));
	printf("\tВвод параметров Спальных комнат\n");
	printf("Введите материал пола: ");
	gets_s(sleepingroomsfloor, LENGHT);
	printf("Введите материал потолка: ");
	gets_s(sleepingroomsceil, LENGHT);
	printf("Введите кол-во мест для сна(Диван/Кровать): ");
	scanf("%d", &numOfPlaceForSleep);
	while (getchar() != '\n');
	return CreateSleepRooms(sleepingroomsfloor, sleepingroomsceil, numOfPlaceForSleep);
}


Apartment* InputApartment()
{
	printf("\tВвод параметров квартиры\n");
	int numOfRooms, floor, housenum; 
	float square;
	char* street = (char*)calloc(LENGHT, sizeof(char));
	printf("Введите название улицы: ");
	gets_s(street, LENGHT);
	printf("Введите номера дома: ");
	scanf("%d", &housenum);
	printf("Введите номер этажа: ");
	scanf("%d", &floor);
	printf("Введите площадь квартиры: ");
	scanf("%f", &square);
	printf("Введите кол-во комнат: ");
	scanf("%d", &numOfRooms);
	BuildingStatus status;
	printf("Введите статус(Строится - 0, Готова - 1): ");
	scanf("%d", &status);
	while (getchar() != '\n');
	return CreateApartment(*InputKitchen(), *InputHall(), *InputBathroom(), *InputSleepRooms(), status, numOfRooms, floor, housenum, square, street);

}

void PrintApartmentInfo(Apartment apartment)
{
	printf("\t\tИнформация о квартире\n");
	printf("Статус: %s\n", BuildingStatustostring(apartment.status));
	printf("Улица %s, дом %d, этаж %d\n", apartment.street, apartment.housenum,apartment.floor);
	printf("Площадь: %f\nКол-во комнат: %d\n", apartment.square, apartment.numOfRooms);
	
	printf("\tЗал\nМатериал пола: %s\nПотолок: %s\nКол-во спальных мест: %d\n", apartment.hall.hallfloor, apartment.hall.hallceil,apartment.hall.numOfPlaceForSleep);
	printf("\tКухня\nМатериал пола: %s\nПотолок: %s\n", apartment.kitchen.kitchenfloor, apartment.kitchen.kitchenceil);
	printf("\tВанная комната\nМатериал пола: %s\nПотолок: %s\nОбделка стен: %s\nСредство для мытья: %s\n", apartment.bathroom.bathroomfloor, apartment.bathroom.bathroomceil,BathroomWallTypetostring(apartment.bathroom.walltype),BathroomWashTypetostring(apartment.bathroom.washtype));
	printf("\tСпальные комнаты\nМатериал пола: %s\nПотолок: %s\nКол-во спальных мест: %d\n", apartment.sleepingrooms.sleepingroomsfloor, apartment.sleepingrooms.sleepingroomsceil, apartment.sleepingrooms.numOfPlaceForSleep);

}


//функция изменения статуса квартиры
void ChangeStatus(Apartment* apartment, BuildingStatus newStatus)
{
	if (newStatus >= Строится && newStatus <= Готова)
	{
		apartment->status = newStatus;
		printf("Состояние квартиры изменено!\n");
	}
	else
	{
		printf("Неправильно введены данные! Выход...");
		exit(EXIT_SUCCESS);
	}
}
//Функция для освобождения памяти
void FreeMemory(Apartment* apartment)
{
	free(apartment->bathroom.bathroomceil);
	free(apartment->bathroom.bathroomfloor);
	free(apartment->kitchen.kitchenceil);
	free(apartment->kitchen.kitchenfloor);
	free(apartment->sleepingrooms.sleepingroomsceil);
	free(apartment->sleepingrooms.sleepingroomsfloor);
	free(apartment->hall.hallceil);
	free(apartment->hall.hallfloor);
}
