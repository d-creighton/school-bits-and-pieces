#include <iostream>
#include <string>

using namespace std;

int main()
{
    //declare variables
    string sales_choice;
    bool sales;
    bool flag = true;

    double sun;
    double mon;
    double tue;
    double wed;
    double thu;
    double fri;
    double sat;
    double week;

    double jan;
    double feb;
    double mar;
    double apr;
    double may;
    double jun;
    double jul;
    double aug;
    double sep;
    double oct;
    double nov;
    double dec;
    double year;

  //Prompt user for weekday or monthly sales
  do {
    cout << "Would you like to enter the sales based on weekdays, w, or months, m?\n";
    cin >> sales_choice;

    if (sales_choice == "w"){
      sales = true;
      flag = false;
    }
    else if (sales_choice == "m"){
      sales = false;
      flag = false;
    }
    else {
      cout << "Please enter either w or m." << endl;
    }
  } while (flag == true);

  //Sales of week or year
  if (sales == true){
    //Sales for week
      cout << "Enter the sales for each day: " << endl;
      cout << "Sunday: ", cin >> sun;
      cout << "Monday: ", cin >> mon;
      cout << "Tuesday: ", cin >> tue;
      cout << "Wednesday: ", cin >> wed;
      cout << "Thursday: ", cin >> thu;
      cout << "Friday: ", cin >> fri;
      cout << "Saturday: ", cin >> sat;
      week = sun += mon += tue += wed += thu += fri += sat;
      cout << "Total sales for the week: $" << week;
  }
  else {
    //Sales for year
      cout << "Enter the sales for each month: " << endl;
      cout << "January: ", cin >> jan;
      cout << "February: ", cin >> feb;
      cout << "March: ", cin >> mar;
      cout << "April: ", cin >> apr;
      cout << "May: ", cin >> may;
      cout << "June: ", cin >> jun;
      cout << "July: ", cin >> jul;
      cout << "August: ", cin >> aug;
      cout << "September: ", cin >> sep;
      cout << "October: ", cin >> oct;
      cout << "November: ", cin >> nov;
      cout << "December: ", cin >> dec;
      year = jan += feb += mar += apr += may += jun += jul += aug += sep += oct += nov += dec;
      cout << "Total sales for the year: $" << year;
  }
    return 0;
}
