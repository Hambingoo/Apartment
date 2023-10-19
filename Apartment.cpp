#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include "Apartment.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Apartment staticApartment = *InputApartment();
    PrintApartmentInfo(staticApartment);


    Apartment* dynamicApartment = (Apartment*)calloc(1, sizeof(Apartment));
    dynamicApartment = InputApartment();
    PrintApartmentInfo(*dynamicApartment);
    ChangeStatus(dynamicApartment, Строится);
    PrintApartmentInfo(*dynamicApartment);
    FreeMemory(dynamicApartment);
    free(dynamicApartment);
}