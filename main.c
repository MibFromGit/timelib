/**
*Tag des Jahres Programm
*Autor: Pascal Börger
*erstellt am 10.05.2022
**/
#include <stdio.h>
#include <stdlib.h>

int day_of_the_Year(int days, int month, int year)
{
    int tempdays = 0; // deklaration einer temporären Variable
    int tempmonth; // initialisierung einer Temporären Variable
    for (int i = 0; i < month - 1; i++) // For-Schleife um die Tage im Monat zu bekommen
    {
        tempmonth = i + 1;
        tempdays += get_days_for_months(tempmonth, year);
    }
    return tempdays += days;
}

int is_leapyear(int year)
{
    if(year < 1582) //prüfung ob das Jahr im gregoreanischen Kalender existiert
        return -1;

    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return 1; //Ist ein Schaltjahr
            }
        }else
        {
            return 1; //Ist ein Schaltjahr
        }
    }
    return 0; //Ist kein Schaltjahr
}


int get_days_for_months(int month, int year)
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Deklaration des Arrays

    if (is_leapyear(year)) //Prüfung ob Schaltjahr
    {
        tage_pro_monat[1] = 29;
    }
    if (month < 13 && month > 0) // Validierung des Monats
    {
        return tage_pro_monat[month - 1];
    }
    return -1;// Ausgabe falls Parameter nicht gültig sind
}

int exists_date(int days, int month, int year)
{
    if (year > 1582) // Prüfen ob das Jahr existiert
    {
        if (month > 0 && month < 13) //Prüfung ob der Monat existiert
        {
            if (days > 0 && days <= get_days_for_months(month,year)) // Prüfen ob die Anzahl der Tage im Monat vorhanden sind
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int year;
    int month;
    int days;
    int Tag_des_Jahres = 0;

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

    printf("\nDer Tag der Jahres %i ist %i", year, day_of_the_Year(days,month,year)); // Ausgabe
}
