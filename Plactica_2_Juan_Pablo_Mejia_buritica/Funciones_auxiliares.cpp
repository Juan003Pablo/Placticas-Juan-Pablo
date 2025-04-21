#include <unistd.h>
#include <cctype>

int valorRomano(char a)
{
    a = toupper(a);
    switch (a) {
    case 'M':
        return 1000;
    case 'D':
        return 500;
    case 'C':
        return 100;
    case 'L':
        return 50;
    case 'X':
        return 10;
    case 'V':
        return 5;
    case 'I':
        return 1;
    default:
        return -1;
    }
}
unsigned long long int factorial(int n) {
    unsigned long long int res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}
