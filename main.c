#include <stdio.h>
#include <stdlib.h>

int day_of_the_Year(int T, int M, int J)
{
    int tempdays = 0;
    int tempmonth;
    for (int i = 0; i < M - 1; i++)
    {
        tempmonth = i + 1;
        tempdays += get_days_for_months(tempmonth, J);
    }
    return tempdays += T;
}

int is_leapyear(int j)
{
    if(j < 1581 && j > 2400)
    {
        return -1;
    }
    if(j % 4 == 0) // prüfung ob das Jahr ein Schaltjahr ist
    {
        return 1;
    }
    else if(j %400 == 0)// prüfung ob das Jahr ein Schaltjahr ist
    {
        return 1;
    }
    return 0;
}

int get_days_for_months(int M, int J)
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(is_leapyear(J))
    {
        tage_pro_monat[1] = 29;
    }
    if (M < 13 && M > 0)
    {
        return tage_pro_monat[M - 1];
    }
    return -1;
}

int exists_date(int T, int M, int J)
{
    if(J > 1582 && J < 2400)
    {
        if(M > 0 && M < 13)
        {
            if (T > 0 && T <= get_days_for_months(M,J))
            {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

int main()
{
    int Jahr;
    int Monat;
    int Tage;
    int Tag_des_Jahres = 0;

    do
    {
        printf("Geben sie ein Jahr ein: ");
        scanf("%i", &Jahr);

        printf("\nGeben sie einen Monat ein: ");
        scanf("%i", &Monat);

        printf("\nGeben sie einen Tag ein: ");
        scanf("%i", &Tage);

        if(!exists_date(Tage, Monat, Jahr))
        {
            printf("\nFalsche eingabe!\n versuchen sie es ernuert.\n");
        }

    }while(!exists_date(Tage, Monat, Jahr));

    printf("\nDer Tag der Jahres %i ist %i", Jahr, day_of_the_Year(Tage,Monat,Jahr));
}