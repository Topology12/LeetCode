#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArray(vector<int> &, int, vector<int> &, int);
void displayArray(vector<int> &);
void createArray(vector<int> &, int m, int n);

int main()
{
    int m;
    int n;
    cout << "Nhap m va n ";
    cin >> m >> n;
    vector<int> vec1;
    vector<int> vec2;
    createArray(vec1, m, n);
    createArray(vec2, n, 0);
    cout << "Mang 1 truoc khi merge" << endl;
    displayArray(vec1);
    mergeSortedArray(vec1, m, vec2, n);
    cout << "Mang 1 sau khi merge" << endl;
    displayArray(vec1);
    return 0;
}
void createArray(vector<int> &vec, int m, int n)
{
    for (int i = 0; i < m + n; i++)
    {
        if (i < m)
        {
            int value;
            cout << "Nhap vec[" << i << "]";
            cin >> value;
            vec.push_back(value);
            continue;
        }
        vec.push_back(0);
    }
}
void displayArray(vector<int> &vec)
{
    int size = vec.size();
    for (int i = 0; i < size; i++)
        cout << vec[i] << " ";
    cout << endl;
}
void mergeSortedArray(vector<int> &vec1, int m, vector<int> &vec2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int index = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && vec1[i] > vec2[j])
            vec1[index--] = vec1[i--];
        else
            vec1[index--] = vec2[j--];
    }
}