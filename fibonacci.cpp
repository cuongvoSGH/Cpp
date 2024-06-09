#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int input[10];
    for (int i = 0; i < 10; i++)
    {
        std::cin >> input[i];
    }

    long fibo[3];

    for (int j = 0; j < 10; j++)
    {
        fibo[0] = 1 % 1000;
        fibo[1] = 1 % 1000;
        for (int i =2; i < input[j]; i++)
        {
            fibo[2] = (fibo[1] + fibo[0]) % 1000;
            fibo[0] = fibo[1];
            fibo[1] = fibo[2];
        }
        std::cout << std::setw(3) << std::setfill('0') << fibo[2] << "\n";
    }

}

