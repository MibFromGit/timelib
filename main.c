#include <stdio.h>
#include <stdlib.h>

int day_of_the_Year(int days, int month, int year)
{
    int tempdays = 0;
    int tempmonth;
    for (int i = 0; i < month - 1; i++)
    {
        tempmonth = i + 1;
        tempdays += get_days_for_months(tempmonth, year);
    }
    return tempdays += days;
}

int is_leapyear(int year)
{
    if(year < 1582)
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
            return 1;
        }
    }
    return 0;
}


int get_days_for_months(int month, int year)
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (is_leapyear(year))
    {
        tage_pro_monat[1] = 29;
    }
    if (month < 13 && month > 0)
    {
        return tage_pro_monat[month - 1];
    }
    return -1;
}

int exists_date(int days, int month, int year)
{
    if (year > 1582)
    {
        if (month > 0 && month < 13)
        {
            if (days > 0 && days <= get_days_for_months(month,year))
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
        printf("Geben sie ein Jahr ein: ");
        scanf("%i", &year);

        printf("\nGeben sie einen Monat ein: ");
        scanf("%i", &month);

        printf("\nGeben sie einen Tag ein: ");
        scanf("%i", &days);

        if(!exists_date(days, month, year))
        {
            printf("\nFalsche eingabe!\n versuchen sie es ernuert.\n");
        }

    }while(!exists_date(days, month, year));

    printf("\nDer Tag der Jahres %i ist %i", year, day_of_the_Year(days,month,year));
}
