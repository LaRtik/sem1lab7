#include <iostream>

/// Lazuk Ilya, ind4 lab7

using namespace std;

char m = 0; // will be added to the answer

int size(string s) // returns the size of string
{
    for (int i = 0; i < 1000000; i++)
    {
        if (s[i] == '\0') return i;
    }
    return -1;
}

void delete_first(string &s) // deletes the first char of the string
{
    string res;
    for (int i = 1; i < size(s); i++)
    {
        res += s[i];
    }
    s = res;
}


int per(char c) // gets the 10-base number of 17-base char
{
    if (c <= '9') return (c - '0');
    return (c - 'A' + 10);
}

char per(int n) // gets the 17-base char of 10-base int
{
    if (n <= 9) return (n + '0');
    return (n - 10 + 'A');
}

void fix(string &s1, string &s2) // makes strings the same size and swaps them, if s2 > s1
{
    while (size(s1) > size(s2))
    {
        s2 = '0' + s2;
    }

    while (size(s1) < size(s2))
    {
        s1 = '0' + s1;
    }

    for (int i = 0; i < size(s1); i++)
    {
        if (per(s1[i]) < per(s2[i]))
        {
            swap(s1, s2);
            m = '-';
            return;
        }

        if (per(s1[i]) > per(s2[i]))
        {
            return;
        }
    }
}


string pl(string s1, string s2) // pluses two numbers in 17-base system
{
    string res;
    int n = size(s1); // size of each number
    int to_add = 0; // additional number
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = per(s1[i]) + per(s2[i]) + to_add;
        to_add = 0;
        if (curr >= 17)
        {
            to_add = curr / 17;
            curr %= 17;
        }

        res = per(curr) + res;
    }
    if (to_add != 0)
    {
        res = per(to_add) + res;
    }
    return res;
}


string mn(string s1, string s2) // subtraction of two 17-base numbers
{
    string res;
    int n = size(s1); // size of each number
    int to_mn = 0; // additional number
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = per(s1[i]) - per(s2[i]) - to_mn;
        to_mn = 0;
        if (curr < 0)
        {
            to_mn = 1;
            curr += 17;
        }

        res = per(curr) + res;
    }
    return res;
}


int main()
{
    string s1, s2;
    cout << "Enter two numbers to sum in 17-base system: " << endl << endl;

    cout << "NOTE: numbers can be negative, but they can't be fractional" << endl << endl;
    cin >> s1 >> s2;
    cout << "The result of summing two 17-base numbers: ";
    if (s1[0] == '-' && s2[0] == '-') // if two numbers are negative just summing them and adding "-" to the answer
    {
        delete_first(s1);
        delete_first(s2);
        fix(s1, s2);
        cout << "-" << pl(s1, s2);
        return 0;
    }

    if (s1[0] == '-')
    {
        delete_first(s1);
        fix(s1, s2);
        cout << m + mn(s1, s1);
        return 0;
    }

    if (s2[0] == '-')
    {
        delete_first(s2);
        fix(s1, s2);
        cout << m + mn(s1, s2);
        return 0;
    }
    cout << pl(s1, s2);
    return 0;
}
