#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float item1, item2, item3, item4, item5, total;
    cout << "Enter a price for item 1: ";
    cin >> item1;

    cout << "Enter a price for item 2: ";
    cin >> item2;

    cout << "Enter a price for item 3: ";
    cin >> item3;

    cout << "Enter a price for item 4: ";
    cin >> item4;

    cout << "Enter a price for item 5: ";
    cin >> item5;

    total = item1 + item2 + item3 + item4 + item5;

    cout << "*********************************" << endl;
    cout << "* Item             * Price      *" << endl;
    cout << "*********************************" << endl;
    cout << "* 1 Item           * " << setw(10) << item1 << " *" << endl;
    cout << "* 2 Item           * " << setw(10) << item2 << " *" << endl;
    cout << "* 3 Item           * " << setw(10) << item3 << " *" << endl;
    cout << "* 4 Item           * " << setw(10) << item4 << " *" << endl;
    cout << "* 5 Item           * " << setw(10) << item5 << " *" << endl;
    cout << "*********************************" << endl;
    cout << "* Item             * " << setw(10) << total << " *" << endl;
    cout << "*********************************" << endl;

    string firstname;
    string lastname;
    int w, h, a;

    cout << "Enter patient first name: ";
    cin >> firstname;
    cout << "Enter patient last name: ";
    cin >> lastname;

    cout << "Enter weight (kg): ";
    cin >> w;

    cout << "Enter height (cm): ";
    cin >> h;

    cout << "Enter age: ";
    cin >> a;

    cout << "-------------------------------" << endl;
    cout << "| patient: " << setw(15) << firstname << " " << lastname << " |" << endl;
    cout << "-------------------------------" << endl;
    cout << "| weight: " << setw(16) << w << " kg |" << endl;
    cout << "| height: " << setw(16) << h << " cm |" << endl;
    cout << "| age: " << setw(16) << a << " years |" << endl;
    cout << "-------------------------------" << endl;

    return 0;

}

