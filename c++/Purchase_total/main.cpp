#include <iostream>
#include <iomanip>

using namespace std;

//constants
//const double Tax_Rate;

int main()
{
    //Define variables
    double dblSubtotal;
    double Tax_Rate;
    Tax_Rate = 0.065;
    double Tax_Amount;
    double Total;

    //Prompt user for subtotal
    cout << "Enter the item total:\n";
    cin >> dblSubtotal;

    //Find tax amount
    Tax_Amount = dblSubtotal * Tax_Rate;
    cout << "Tax on purchase is:\n";
    cout << Tax_Amount;
    cout << endl;

    //Print total cost with tax
    Total = dblSubtotal + Tax_Amount;
    cout << "Total cost of purchase with tax:\n";
    cout << Total;
    return 0;
}
