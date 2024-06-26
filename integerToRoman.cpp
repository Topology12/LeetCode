#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

string intToRoman(int num)
{
    string result = "";
    map<int, string> lst = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IX"},
        {1, "I"}};
    map<int, string>::reverse_iterator iter;
    for (iter = lst.rbegin(); iter != lst.rend(); iter++)
    {
        while (num >= iter->first)
        {
            result += iter->second;
            num -= iter->first;
        }
        if (num == 0)
            break;
    }
    cout << result;
    return result;
}

int main()
{
    int n;
    cout << "Nhap n= ";
    cin >> n;
    intToRoman(n);
    return 0;
}