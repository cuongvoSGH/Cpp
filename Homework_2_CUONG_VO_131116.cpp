#include <iostream>

using namespace std;

// Group 1
// 1. Toy Car Workshop
// You work in a toy car workshop, and your job is to build toy cars from a collection of parts. Each 
// toy car needs 4 wheels, 1 car body, and 2 figures of people to be placed inside. Given the total 
// number of wheels, car bodies and figures available, how many complete toy cars can you make?

// Group 2
// 1. Mini Peaks
// Write a program that prints all the elements that are strictly greater than their adjacent left and right 
// neighbors. Use 6 values. Do not count boundary numbers, since they only have one left/right 
// neighbor. If no such numbers exist, return text: „no values”.

// Group 3
// 3. Get the Excel Column
// Excel column names are in the following format:
// A, B, ..., Z, AA, ..., AZ, BA, ..., ZZ, AAA, AAB, ...
// Write a program that returns the column number from the row name.

int main() {
    cout << "==========================================" << endl;
    float wheels, bodies, figures ;
    cout << "Group 1 - Ex 1 - Toy Car Workshop" << endl;
    cout << "input the total number of: " << endl;
    cout << "wheels: ";
    cin >> wheels;
    cout << "car bodies: ";
    cin >> bodies;
    cout << "figues: ";
    cin >> figures;

    int n_wheels = wheels / 4;
    int n_bodies = bodies / 1;
    int n_figures = figures / 2;

    int n_car = n_wheels;

    if (n_car > n_bodies) {
        n_car = n_bodies;
    } else if (n_car > n_figures) {
        n_car = n_figures;
    }
    cout << "cars: " << n_car << endl;
    
    cout << "==========================================" << endl;
    cout << "Group 2 - Ex 1 - Mini Peak" << endl;
    double a[6];
    for (int i=0; i < 6; i++) {
        cout << "enter value " << i+1 <<": ";
        cin >> a[i];
    }
    bool result[6] = {false};
    int flag = 0;
    for (int i=1; i <5; i++) {
        if ((a[i] > a[i-1]) && (a[i] > a[i+1])){
            result[i] = true;
            flag = 1;
        }
    }

    if (flag == 1) {
        cout << "mini peaks:";
        for (int i = 0; i < 6; i ++) {
            if (result[i] == true) cout << " " << a[i];
        } 
    } else if (flag == 0) {
            cout << "no values";
        } 

    cout << endl;
    
    cout << "==========================================" << endl;
    cout << "Group 3 - Ex 3 - Get the Excel Column" << endl;
    cin.ignore();
    cout << "enter column: ";
    string col_name;
    getline(cin, col_name);
    int i = col_name.length() - 1;
    int index = 0;
    long running = 1;
    while (i >= 0){
        char c = col_name[i];
        c = toupper(c);
        index += running * (int(c) - 65 + 1);
        running = running * 26;
        i -- ;
    }

    cout << "number: " << index;  

    return 0;
}