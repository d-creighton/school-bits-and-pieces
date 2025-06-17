#include <iostream>

using namespace std;

int main()
{
    double prices[9] = {};
    size_t n = sizeof(prices)/sizeof(prices[0]);
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter the values for the prices:" << endl;
        cin >> prices[i];
        cout << prices[i] << ' ';
    }

    //double prices[] = {10.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59};



    /*
        cout << prices[i] << ' ';
        if ((i % 3) == 2)
        {
            cout << std::endl;
        }*/


    //cout << prices[0];

// Print contents of an array in C++ using array indices
	//int input[] = { 1, 2, 3, 4, 5 };
	//size_t n = sizeof(input)/sizeof(input[0]);

	// loop through the elements of the array
	//for (size_t i = 0; i < n; i++) {
		//std::cout << input[i] << ' ';


	return 0;
}
