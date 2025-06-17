#include <iostream>
#include <algorithm>

using namespace std;

struct Calendar
{
    //Inputed values
    string month_name;
    int rainfall,
        high_temp,
        low_temp;
    //Calculated values
    float monthly_avg_temp;
};

//Sort by highest temperature
//Didn't call this further down yet, was going to once I got a return value
/*int sorting(month[i].high_temp, int i)
{
    for(i=0, i<12, i++)
    {
        sort(month[i].high_temp, month[i].high_temp + i);
        //Sort in ascending order
        //Output just the highest number, not whole sort
    }
}*/

//Copy function above but using month[i].low_temp
//Output lowest number

int main()
{
    struct Calendar month[12];
    int i;
    int yearly_total_rf = 0;
    float avg_yearly_temp = 0;
    bool flag1 = true;
    bool flag2 = true;
    bool flag3 = true;

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

    //Print for testing
    for(i=0; i<12; i++)
    {
        while(flag3)
        {
            cout << "\nMonth: " << i + 1 << endl;
            cout << month[i].month_name << endl;
            cout << "Rainfall: " << month[i].rainfall << endl;
            cout << "High temperature: " << month[i].high_temp << endl;
            cout << "Low temperature: " << month[i].low_temp << endl;
            cout << "Average temperature for the month: " << month[i].monthly_avg_temp << endl;
            if(i<=12)
            {
                continue;
            }
            else
            {
                flag3 = false;
            }
        }
    }
    cout << "\nTotal yearly rainfall: " << yearly_total_rf << endl;
    //Finish calculation for average temperature of the year
    avg_yearly_temp = avg_yearly_temp/12;
    cout << "Overall average temperature: " << avg_yearly_temp << endl;

    return 0;
}
