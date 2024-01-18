#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s)
{
    int len = s.size();
    if (len == 1)
        return s;
    int i = 0;
    string result = s.substr(0, 1);
    int max_size = 1;
    while (i < len - 1)
    {
        int tempr = i - 1;
        int templ = i + 1;
        int center = i;
        while (s[center] == s[center + 1] && center < len - 1)
        {
            center++;
        }
        if (center > i)
            templ = center + 1;
        string curr = s.substr(i, center - i + 1);
        while (tempr >= 0 && templ < len)
        {
            if (s[templ] == s[tempr])
            {
                curr = s.substr(tempr, templ - tempr + 1);
                tempr--;
                templ++;
            }
            else
                break;
        }
        result = (curr.size() > result.size()) ? curr : result;
        i++;
    }
    return result;
}

int main()
{
    string s; 
    cout<<"Nhap chuoi s: "<<endl;
    cin>>s;
    string result = longestPalindrome(s);
    cout << result;
    return 0;
}