#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main() {
    // int deg;
    // cout << "Input temp in (Cecius Degree): ";
    // cin >> deg;

    // if (deg <= 0) cout << "There is frost today !!!!! Wear warm" << endl;
    //     else cout << "There is not frost today !!! Great !!!!" << endl;

    // int water_deg;
    // cout << "Input water temp in (Cecius Degree): ";
    // cin >> water_deg;

    // if (water_deg <= 0) cout << "That is ICE" << endl;
    //     else if (water_deg >= 100) cout << "That is steam" << endl;
    //     else cout << "That is liquid" << endl;

    // string color;
    // cout << "Input car color: ";
    // cin >> color;

    // if (color == "red") cout << "The car is red" << endl;
    //     else cout << "The car is not red" << endl;   

    float PLNUSD, PLNJPY, PLNGBP, PLNCHF;
    PLNUSD = 0.2531;
    PLNJPY = 37.76;
    PLNGBP = 0.1986;
    PLNCHF = 0.2235;

    float amount;
    cout << "Enter the amount from (PLN): ";
    cin >> amount;

    string currency;
    cout << "Enter currency to (USD/ JPY/ CHF/ GBP): ";
    cin >> currency;

    string loc;
    float amount_to, rate;

    if (currency == "USD") {
        loc = "USA";
        rate = PLNUSD;
        amount_to = amount * rate;
    }
    else if (currency == "JPY") {
        loc = "Japan";
        rate = PLNJPY;
        amount_to = amount * rate;
    } 
    else if (currency == "CHF") {
        loc = "Switzerland";
        rate = PLNCHF;
        amount_to = amount * rate;
    }
    else if (currency == "GBP") {
        loc = "UK";
        rate = PLNGBP;
        amount_to = amount * rate;
    }

    cout << "********************************" << endl;
    cout << "* Country    * " << setw(15) << loc << " *" << endl;
    cout << "* Currency   * " << setw(15) << currency << " *" << endl;
    cout << "* Rate       * " << setw(15) << rate << " *" << endl;
    cout << "* Amount to  * " << setw(15) << amount_to << " *" << endl;
    cout << "********************************" << endl;

    return 0;

}