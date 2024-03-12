#include <iostream>
#include <vector>
using namespace std;

int climbingStairs(int n);
void backtracking(int start, int &result, int n);
int countClimb(int n, vector<int> &);
int main()
{
    int n;
    cout << "Enter Stairs = ";
    cin >> n;
    cout << climbingStairs(n);
    return 0;
}

int climbingStairs(int n)
{
    vector<int> vec(n + 1, -1);
    return countClimb(n, vec);
}

void backtracking(int location, int &result, int n)
{
    if (location >= n)
    {
        if (location == n)
            result += 1;
        return;
    }
    int loca = location;
    vector<int> vec = {1, 2};
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        loca += vec[i];
        backtracking(loca, result, n);
        loca -= vec[i];
    }
}

int countClimb(int n, vector<int> &vecprev)
{
    if (n <= 1)
        return 1;
    if (vecprev[n] != -1)
        return vecprev[n];
    return vecprev[n] = countClimb(n - 1, vecprev) + countClimb(n - 2, vecprev);
}