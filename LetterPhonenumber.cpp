#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;
void backtracking(int i, vector<string> &vec, string digit, string temp)
{
    map<string, vector<string>> table = {
        {"2", {"a", "b", "c"}},
        {"3", {"d", "e", "f"}},
        {"4", {"g", "h", "i"}},
        {"5", {"j", "k", "i"}},
        {"6", {"m", "n", "o"}},
        {"7", {"p", "q", "r", "s"}},
        {"8", {"t", "u", "v"}},
        {"9", {"w", "x", "y", "z"}},
    };
    if (i == digit.length())
    {
        vec.push_back(temp);
    }
    string index;
    index = digit[i];
    vector<string> vectemp = table[index];
    for (int j = 0; j < vectemp.size(); j++)
    {
        temp += vectemp[j];
        backtracking(i + 1, vec, digit, temp);
        temp = temp.substr(0, temp.length() - 2);
    }
}
vector<string> letterCombinations(string digit)
{
    vector<string> result;
    if (digit.length() == 0)
        return result;
    backtracking(0, result, digit, "");
    return result;
}

int main()
{
    string digit;
    do
    {
        cin >> digit;
    } while (digit.length() > 4);
    vector<string> result = letterCombinations(digit);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    return 0;
}