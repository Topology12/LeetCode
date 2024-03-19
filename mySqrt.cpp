#include <iostream>
using namespace std;

int mySqrtOne(int x)
{
    int i = 0;
    while (i * i <= x)
    {
        if (i * i == x)
            return i;
        i++;
    }
    return i - 1;
}

int main()
{
    int x;
    cout << "Nhap so muon tim can bac hai ";
    cin >> x;
    cout << mySqrtOne(x);
    return 0;
}