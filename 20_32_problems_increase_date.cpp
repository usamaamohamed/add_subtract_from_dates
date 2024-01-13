#include <iostream>
#include <limits>
#include <ctime>

using namespace std;

struct st_date
{
    short day ;
    short month ;
    short year ;
};

bool is_leap_year(short year) 
{ 
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); 
} 

short days_in_month(short month , short year)
{
    short days[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 }; 
    (is_leap_year(year))? days[2] = 29 : days[2] = 28;
    return days[month];
}

char is_last_day_in_month(st_date date)
{
    return (date.day == days_in_month(date.month , date.year));
}

char is_last_month_in_year(st_date date)
{
    return (date.month == 12);
}

st_date increase_date_by_one_day(st_date & date)
{    
    if (is_last_day_in_month(date))
    {
        if (is_last_month_in_year(date))
        {
            date.day = 1;
            date.month = 1;
            date.year ++;
        }
        else
        {
            date.day = 1;
            date.month ++;
        }
    }
    else
    {
        date.day ++;
    }
    return date;
}

st_date increase_date_by_x_days(st_date & date , short & x_days)
{
    for (int i = 1; i <= x_days; i++)
    {
        increase_date_by_one_day(date);
    }
    return date;
}

st_date increase_date_by_one_week(st_date & date)
{
    for (int i = 1; i <= 7; i++)
    {
        increase_date_by_one_day(date);
    }
    return date;
}

st_date increase_date_by_x_weeks(st_date & date , short & x_weeks)
{
    for (int i = 1; i <= x_weeks; i++)
    {
        increase_date_by_one_week(date);
    }
    return date;
}

st_date increase_date_by_one_month(st_date & date)
{
    if (date.month == 12)
    {
        date.year ++;
        date.month =1;
    }
    else date.month ++;

    short number_of_days_in_current_month = days_in_month(date.month , date.year);
    if (date.day > number_of_days_in_current_month)
    {
        date.day = number_of_days_in_current_month;
    }
    
    return date;
}

st_date increase_date_by_x_months(st_date & date , short & x_months)
{
    for (int i = 1; i <= x_months; i++)
    {
        increase_date_by_one_month(date);
    }
    return date;
}

st_date increase_date_by_one_year(st_date & date)
{
    date.year++;
    return date;
}

st_date increase_date_by_x_years(st_date & date , short & x_years)
{
    for (int i = 1; i <= x_years; i++)
    {
        increase_date_by_one_year(date);
    }
    return date;
}

st_date increase_date_by_x_years_faster(st_date & date , short & x_years)
{
    date.year += x_years;
    return date;
}

st_date increase_date_by_one_decade(st_date & date)
{
    for (int i = 1; i <= 10; i++)
    {
        increase_date_by_one_year(date);
    }
    return date;
}

st_date increase_date_by_x_decades(st_date & date , short & x_decades)
{
    for (int i = 1; i <= x_decades; i++)
    {
        increase_date_by_one_decade(date);
    }
    return date;
}

st_date increase_date_by_x_decades_faster(st_date & date , short & x_decades)
{
    date.year += (x_decades*10);
    return date;
}

st_date increase_date_by_one_century(st_date & date)
{
    date.year +=100;
    return date;
}

st_date increase_date_by_one_millennium(st_date & date)
{
    date.year +=1000;
    return date;
}

short read_year(st_date date)
{
    int year = 0;
    cout << "enter year: ";
    cin >> year;
    while (cin.fail())     
    { 
        // user didn't input a number    
        cin.clear();      
        cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n');          
        cout << "Invalid input data type ,Enter a valid number:" << endl;         
        cin >> year;     
    } 
    while (year < 0)
    {
        cout << "year number must be postive.\n";
        cin >> year;
    }

    while (date.day == 29 && date.month ==2)
    {
        if (is_leap_year(year))
        {
            break;
        }
        cout << "you choosed month FEB and days 29 so you must choose a leap year.\n";
        cin >> year;
    }
    
    return year;
}

short read_month(st_date date)
{
    int month = 1;
    cout << "enter month number: ";    
    cin >> month;
    while (cin.fail())     
    { 
        // user didn't input a number    
        cin.clear();      
        cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n');          
        cout << "Invalid input data type ,Enter a number from 1 to 12:" << endl;         
        cin >> month;     
    } 

    while (month < 1 || month > 12)
    {
        cout << "month must be between 1 , 12.\n";
        cin >> month;
    }

    while (date.day > 30)
    {
        if (month == 1 || month == 3 || month == 5|| month == 7 || month == 8 || month == 10 || month == 12 )
        {
            break;
        }
        cout << "month " << month << " has less 30 days.\n";
        cin >> month;
    }
    while (date.day > 29)
    {
        if (month != 2 )
        {
            break;
        }
        cout << "month " << month << " has only can't be " << date.day << " days.\n";
        cin >> month;
    }
    return month;
}

short read_day()
{
    int day = 1;
    cout << "enter day number: "; 
    cin >> day;
    while (cin.fail())     
    { 
        // user didn't input a number    
        cin.clear();      
        cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n');          
        cout << "Invalid input data type ,Enter a number from 1 to 31:" << endl;         
        cin >> day;     
    } 
    while (day < 1 || day > 31)
    {
        cout << "day must be between 1 , 31.\n";
        cin >> day;
    }
    return day;
}

st_date read_date()
{
    st_date date;
    date.day = read_day();
    date.month = read_month(date);
    date.year = read_year(date);
    return date;
}

void print_new_date(st_date  date , string message1 = "" )
{
    cout << message1 ;
    cout << " " << date.day << "/" << date.month << "/" << date.year << endl;
}

int main()
{
    short x_days = 10;
    short x_weeks = 10;
    short x_months = 5;
    short x_years = 10;
    short x_decades = 10;

    st_date date = read_date();

    date = increase_date_by_one_day(date);
    print_new_date(date , "date after adding one day:" );
    
    date = increase_date_by_x_days(date , x_days);
    cout << "date after adding " << x_days << " days:";
    print_new_date(date);
    
    increase_date_by_one_week(date);
    print_new_date(date , "date after adding one week:" );

    increase_date_by_x_weeks(date , x_weeks);
    cout << "date after adding " << x_weeks << " weeks:";
    print_new_date(date);

    increase_date_by_one_month(date);
    print_new_date(date , "date after adding one month:" );

    increase_date_by_x_months(date , x_months);
    cout << "date after adding " << x_months << " months:";
    print_new_date(date);

    increase_date_by_one_year(date);
    print_new_date(date , "date after adding one year:" );
    
    increase_date_by_x_years(date , x_years);
    cout << "date after adding " << x_years << " years:";
    print_new_date(date);

    increase_date_by_x_years_faster(date , x_years);
    cout << "date after adding " << x_years << " years (faster):";
    print_new_date(date);

    increase_date_by_one_decade(date);
    print_new_date(date , "date after adding one decade");

    increase_date_by_x_decades(date , x_decades);
    cout << "date after adding " << x_years << " decades:";
    print_new_date(date);
    
    increase_date_by_x_decades_faster(date , x_decades);
    cout << "date after adding " << x_years << " decades (faster):";
    print_new_date(date);

    increase_date_by_one_century(date);
    print_new_date(date , "date after adding one century");
    
    increase_date_by_one_millennium(date);
    print_new_date(date , "date after adding one millennium");
    
    return 0;
}
