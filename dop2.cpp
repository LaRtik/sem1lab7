#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(int n)
{
    string binary;
    string string_number = to_string(n);
    for (int i = 0; i < string_number.size(); i++)
    {
        if (string_number[i] != '1' && string_number[i] != '0')
        {
            return 0;
        }
    }
    while (binary.size() < string_number.size())
    {
        ans += (n % 2) + '0';
        n /= 2;
        if (string_number[string_number.size() - binary.size()] != binary.back()) // .back() returns the last char of string
        {
            return false;
        }
    }
    return true;
}

void precalc(vector <int> &answers)
{
    for (int i = 1; i <= 10000000; i++)
    {
        if (check(i)) prec.push_back(i);
        if (prec.size() > 10000) return;
    }
}

int main()
{
    vector <int> answers;
    precalc(answers);
    int number;
    cin >> number;
    cout << answers[n - 1];
}
