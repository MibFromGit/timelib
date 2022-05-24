/**
*Tag des Jahres Programm
*Autor: Pascal Börger
*erstellt am 10.05.2022
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bibliothek.h"

int main()
{
    int year;
    int month;
    int days;

    do
    {
        printf("Geben sie ein Jahr ein: "); //Eingabe Jahr
        scanf("%i", &year);

        printf("\nGeben sie einen Monat ein: "); //Eingabe Monat
        scanf("%i", &month);

        printf("\nGeben sie einen Tag ein: "); // Eingabe Tage
        scanf("%i", &days);

        if(!exists_date(days, month, year)) // Prüfung ob das Datum existiert
        {
            printf("\nFalsche eingabe!\n versuchen sie es ernuert.\n");
        }

    }while(!exists_date(days, month, year));

    printf("\nDer Tag der Jahres %i ist %i\n", year, day_of_the_Year(days,month,year)); // Ausgabe
    for (int i = 0; i < sizeof(get_day_of_the_week(days, month, year)); i++)
    {
        printf("%c",get_day_of_the_week(days, month, year)[i]);
    }
}
