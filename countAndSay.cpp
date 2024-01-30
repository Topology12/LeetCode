#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string temp = countAndSay(n - 1);
    string result = "";
    for (int i = 0; i < temp.length(); i++)
    {
        int count = 1;
        while (temp[i] == temp[i + 1] && i < temp.length())
        {
            count++;
            i++;
        }
        result += to_string(count);
        result += temp[i];
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    string result = countAndSay(n);
    cout<<result;
    return 0;
}