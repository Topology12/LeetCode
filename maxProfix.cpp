#include <vector>
#include <iostream>
using namespace std;

int maxProfix(vector<int> &prices);

int main()
{
    int n;
    cout << "Nhap n = ";
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; i++)
    {
        int price_i;
        cout << "Nhap value i = ";
        cin >> price_i;
        prices.push_back(price_i);
    }
    cout << maxProfix(prices);
    return 0;
}

int maxProfix(vector<int> &prices)
{
    int result = 0;
    int curr_price = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - curr_price > result)
            result = prices[i] - curr_price;
        if (prices[i] < curr_price)
            curr_price = prices[i];
    }
    return result;
}