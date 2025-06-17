#include <iostream>

using namespace std;

struct Calendar
{
    //Inputed values
    string month_name;
    int rainfall,
        high_temp,
        low_temp;
    //Calculated values
    int monthly_avg_temp;
};

int main()
{
    int i;
    struct Calendar month[12];
    int yearly_total_rf = 0;
    float avg_yearly_temp = 0;
    bool flag1;
    bool flag2;
    bool flag3;

    //User inputs values
    for(i=0; i<12; i++)
    {
        cout << "Enter data for month: " << i + 1 << endl;
        cout << "Month name:" << endl;
        cin >> month[i].month_name;
        cout << "Rainfall:" << endl;
        cin >> month[i].rainfall;
        cout << "High temperature:" << endl;
        cin >> month[i].high_temp;

        flag1 = true;
        while(flag1)
        {
            if(month[i].high_temp < -100 || month[i].high_temp > 140)
            {
                cout << "Number not valid. Enter a temperature between -100 and 140 degrees." << endl;
                cin >> month[i].high_temp;
            }
            else
            {
                flag1 = false;
            }
        }
        cout << "Low temperature:" << endl;
        cin >> month[i].low_temp;

        flag2 = true;
        while(flag2)
        {
            if(month[i].low_temp < -100 || month[i].low_temp > 140)
            {
                cout << "Number not valid. Enter a temperature between -100 and 140 degrees." << endl;
                cin >> month[i].low_temp;
            }
            else
            {
                flag2 = false;
            }
        }
        //Calculate monthly average temperature
        month[i].monthly_avg_temp = (month[i].high_temp + month[i].low_temp)/2;
        //Begin calculation for average temperature of the year
        avg_yearly_temp += month[i].monthly_avg_temp;
        //Calculate yearly total rainfall
        yearly_total_rf += month[i].rainfall;
    }
    //Print inputed data
    i=0;
    flag3 = true;
    while(flag3)
    {
        cout << "\nMonth: " << i + 1 << endl;
        cout << month[i].month_name << endl;
        cout << "Rainfall: " << month[i].rainfall << endl;
        cout << "High temperature: " << month[i].high_temp << endl;
        cout << "Low temperature: " << month[i].low_temp << endl;
        cout << "Average temperature for the month: " << month[i].monthly_avg_temp << endl;
        i++;
        if(i==12)
        {
            flag3 = false;
        }
    }

    //Print total rainfall
    cout << "\nTotal yearly rainfall: " << yearly_total_rf << endl;
    //Finish calculation for average temperature of the year
    avg_yearly_temp = avg_yearly_temp/12;
    cout << "Overall average temperature: " << avg_yearly_temp << endl;

    //Find highest temperature
    int max_temp = month[0].high_temp;
    int max_loc = 0;
    //Find lowest temperature
    int min_temp = month[0].low_temp;
    int min_loc = 0;
    for (i=0; i<12; i++)
    {
        if(month[i].high_temp >= max_temp)
        {
            max_temp = month[i].high_temp;
            max_loc = i+1;
        }
        if(month[i].low_temp <= min_temp)
        {
            min_temp = month[i].low_temp;
            min_loc = i+1;
        }
    }
    cout << "Highest temperature of the year: " << max_temp << endl;
    cout << "Occurred in month: " << max_loc << endl;
    cout << "Lowest temperature of the year: " << min_temp << endl;
    cout << "Occurred in month: " << min_loc << endl;

    return 0;
}
