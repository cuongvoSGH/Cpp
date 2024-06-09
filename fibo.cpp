#include <iostream>

unsigned long cache[2000];

unsigned long f(long n) 
{
    if (n == 0) return 1;
    if (n == 1) return 1;

    if (cache[n] != 0) return cache[n];

    unsigned long ret = (f(n-1) + f(n-2));
    cache[n] = ret;
    return ret;
}

int main() {
    std::cout << "Result: " <<f(53)<<"\n";
    return 0;
}