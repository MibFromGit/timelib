struct Date {
    int year;
    int month;
    int days;
};

int day_of_the_Year(struct Date);

int is_leapyear(int year);

int get_days_for_months(struct Date);

int exists_date(struct Date);

int get_day_of_the_week(struct Date);
