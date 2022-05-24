#include "Bibliothek.h"
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

char* get_day_of_the_week(int days, int month, int year)
{
    int weekday = (days += month < 3 ? year-- : year - 2, 23*month/9 + days + 4 + year/4- year/100 + year/400)%7;

    char* tempweekday[7] = {"Sonntag", "Monatag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

    return tempweekday[weekday];
}
