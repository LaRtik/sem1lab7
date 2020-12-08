#include <iostream>
#include <string>

/// Lazuk Ilya, 053502, individual task 1 with arrays

using namespace std;

int size(string s) // returns the size of string
{
    for (int i = 0; i < 1000000; i++)
    {
        if (s[i] == '\0') return i;
    }
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

int from3to10(string troi) // converting number from 3-base system to 17-base system
{
    reverse(troi);
    int ans = 0;
    int curr = 1;
    for (int i = 0; i < size(troi); i++)
    {
        ans += curr * (troi[i] - '0');
        curr *= 3;
    }
    return ans;
}

char ost(int n)
{
    /*
    returns the remainder for 17-base system
    if the remained >= 10 returns the appropriate letter (from A to F)
    */

    if (n <= 9) return n + '0';
    else return char(n - 10 + 'a');
}

string from10to17(int ten) // converts the 10-base number to 17-base number
{
    string ans;
    while (ten != 0)
    {
        ans += ost(ten % 17);
        ten /= 17;
    }

    reverse(ans);
    return ans;
}

int main()
{
    string troi;
    cout << "Enter the 3-base number: ";
    cin >> troi;
    cout << "Your 17-base number: " << endl;
    cout << from10to17(from3to10(troi));
}
