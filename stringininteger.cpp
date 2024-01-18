#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;

int myAtoi(string s)
{
    if (s.size() == 0)
        return 0;
    int i = 0;
    while (s[i] == ' ' && i < s.size())
    {
        i++;
    }

    int dau = 1;
    if (s[i] == '-')
    {
        dau = -1;
        i++;
    }
    else
    {
        if (s[i] == '+')
            i++;
    }
    int result = 0;
    while (isdigit(s[i]) && i < s.size())
    {
        int temp = s[i] - '0';
        if (result > INT_MAX / 10 || temp > 7 && result == INT_MAX / 10)
            return (dau == 1) ? INT_MAX : INT_MIN;
        result = result * (10) + temp;
        i++;
    }
    result = result * dau;
    if (result >= INT_MAX)
        return INT_MAX;
    else
    {
        if (result <= INT_MIN)
            return INT_MIN;
        else
            return result;
    }
}

int main()
{
    string s = "helloeverryone";
    cout << myAtoi(s);
    return 0;
}