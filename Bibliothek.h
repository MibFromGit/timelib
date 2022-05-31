struct Date {
    int year;
    int month;
    int days;
    int tempmonth;
};

int day_of_the_Year(struct Date); // gibt an der wievielte tag im Jahr das Datum ist

int is_leapyear(int year); // Prüft ob das Jahr ein Schaltjahr ist

int get_days_for_months(struct Date); // gibt die anzahl der tage in einem Monat zurück

int exists_date(struct Date); // Prüft ob das Jahr existiert

int get_day_of_the_week(struct Date); // Gibt den Wochentag zurück
