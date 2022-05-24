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
    struct Date date1;

    do
    {
        printf("Geben sie ein Jahr ein: "); //Eingabe Jahr
        scanf("%i", &date1.year);

        printf("\nGeben sie einen Monat ein: "); //Eingabe Monat
        scanf("%i", &date1.month);

        printf("\nGeben sie einen Tag ein: "); // Eingabe Tage
        scanf("%i", &date1.days);

        if(!exists_date(date1)) // Prüfung ob das Datum existiert
        {
            printf("\nFalsche eingabe!\n versuchen sie es ernuert.\n");
        }

    }while(!exists_date(date1));

    printf("\nDer Tag der Jahres %i ist %i\n", date1.year, day_of_the_Year(date1)); // Ausgabe
    for (int i = 0; i < sizeof(get_day_of_the_week(date1)); i++)
    {
        printf("%c",get_day_of_the_week(date1)[i]);
    }
}
