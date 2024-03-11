// #include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int side;
    cout << "Input the side amount: ";
    cin >> side;
    cout << "Volume of the cube: " << side * side * side << endl; 
    cout << endl;
    int w, l;
    cout << "Input width and length of rectangle: ";
    cin >> w >> l;
    cout << "Area of the rectangle: " << w * l << endl;
    cout << endl;
    char s;
    cout << "Input char: ";
    cin >> s;
    char lowerChar = tolower(s);
    cout << "Lower case: " << lowerChar << endl;
    cout << endl;
    int a;
    cout << "Input integer: ";
    cin >> a;
    cout << "You entered the number " << a << endl;
    cout << endl;
    string name;
    cout << "What's your name: ";
    cin >> name;
    cout << "Hello " << name << "!!!!!!";
    return 0;
}