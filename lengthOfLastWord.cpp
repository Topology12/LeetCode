#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
    int j = s.length() - 1;
    int result = 0;
    while (s[j] == ' ' && j >= 0)
        j--;
    while (j >= 0)
    {
        if (s[i] == ' ')
            break;
        result++;
        j--;
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLastWord(s);
    return 0;
}