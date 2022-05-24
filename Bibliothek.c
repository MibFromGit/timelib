#include "Bibliothek.h"

int day_of_the_Year(struct Date date1)
{
    int tempdays = 0; // deklaration einer temporären Variable
    int tempmonth; // initialisierung einer Temporären Variable
    for (int i = 0; i < date1.month - 1; i++) // For-Schleife um die Tage im Monat zu bekommen
    {
        tempmonth = i + 1;
        tempdays += get_days_for_months(date1);
    }
    return tempdays += date1.days;
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


int get_days_for_months(struct Date date1)
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Deklaration des Arrays

    if (is_leapyear(date1.year)) //Prüfung ob Schaltjahr
    {
        tage_pro_monat[1] = 29;
    }
    if (date1.month < 13 && date1.year > 0) // Validierung des Monats
    {
        return tage_pro_monat[date1.month - 1];
    }
    return -1;// Ausgabe falls Parameter nicht gültig sind
}

int exists_date(struct Date date1)
{
    if (date1.year > 1582) // Prüfen ob das Jahr existiert
    {
        if (date1.year > 0 && date1.month < 13) //Prüfung ob der Monat existiert
        {
            if (date1.days > 0 && date1.days <= get_days_for_months(date1)) // Prüfen ob die Anzahl der Tage im Monat vorhanden sind
            {
                return 1;
            }
        }
    }
    return 0;
}

char* get_day_of_the_week(struct Date date1)
{
    int weekday = (date1.days += date1.month < 3 ? date1.year-- : date1.year - 2, 23*date1.month/9 + date1.days + 4 + date1.year/4- date1.year/100 + date1.year/400)%7;

    char* tempweekday[7] = {"Sonntag", "Monatag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

    return tempweekday[weekday];
}
