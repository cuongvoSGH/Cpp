#include <iostream>
#include <iomanip>
using namespace std;

string addstring(string x,string y) {
    while (x.length() != y.length()) {
        if (x.length() > y.length()) {y = '0' + y;}
        else {x = '0' + x;}
    }
    int carry = 0;
    int u = 0;
    int v = 0;
    string result = "";
    for (int i = x.length()-1; i >= 0; i--){
        u = int(x[i]) - 48;
        v = int(y[i]) - 48;
        int total = u + v + carry ;
        carry = total / 10;
        total = total % 10;
        result = char(total + 48) + result;
    }
    if (carry > 0) {result = '1' + result;}
    return result;
}

int main(){
    int input[10];
    for (int i = 0; i < 10; i++){
        std::cin >> input[i];
    }
    
    string fibo[3];
    
    for (int i = 0; i < 10; i++){
        fibo[0] = "1";
        fibo[1] = "1";
        for (int j = 2; j < input[i]; j++){
            fibo[2] = addstring(fibo[0], fibo[1]);
            fibo[0] = fibo[1];
            fibo[1] = fibo[2];        
        }
        std::cout << fibo[2][0] << "\n";
    }
}
