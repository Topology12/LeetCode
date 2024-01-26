#include <iostream>
#include <string>
using namespace std;
int strStr(string haystack, string needle)
{
    int first = haystack.find(needle, 0);

    return first;
}


int main()
{
    string h, n; 
    cin>>h>>n;
    cout<<strStr(h, n);
    return 0;
}