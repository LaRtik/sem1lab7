#include <iostream>

using namespace std;

/// Lazuk Ilya, individual task 1 without arrays

char ost(int n)
{
    /*
    returns the remainder for 17-base system
    if the remained >= 10 returns the appropriate letter (from A to F)
    */

    if (n <= 9) return n + '0';
    else return char(n - 10 + 'a');
}

void reverse(string &s) // reverses the string
{
    string s1;
    for (int i = size(s) - 1; i >= 0; i--)
    {
        s1 += s[i];
    }
    s = s1;
}

int pow(int n, int step) // analog for "cmath" pow
{
    int ans = 1;
    for (int i = 1; i <= step; i++)
    {
        ans *= n;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of 3-base number: ";
    cin >> n;
    int current_step = pow(3, n - 1);
    char curr;
    int ten = 0;
    string ans;
    cout << "Enter the 3-base number: ";
    for (int i = 0; i < n; i++)
    {
        cin >> curr;
        ten += (curr - '0') * current_step;
        current_step /= 3;
    }

    while (ten != 0)
    {
        ans += ost(ten % 17);
        ten /= 17;
    }

    reverse(ans);

    cout << "Your 17-base number: ";
    cout << ans;





}
