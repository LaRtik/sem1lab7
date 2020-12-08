#include <iostream>
#include <iomanip>

using namespace std;

/// Lazuk Ilya, individual task 2

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
    return;
}


int todec(string s) // converts binary number to 10-base number
{
    reverse(s);
    int curr = 1;
    int ans = 0;
    for (int i = 0; i < size(s); i++)
    {
        ans += curr * (s[i] - '0');
        curr *= 2;
    }
    return ans;
}

double todec_drob(string s) // converts binary number to 10-base float number
{
    double ans = 0, curr = 2;
    for (int i = 0; i < size(s); i++)
    {
        ans += double(s[i] - '0') / curr;
        curr *= 2;
    }
    return ans;
}

int main()
{
    string obr; // first digit is iconic (0 means that number < 0, else number >=0)
    cout << "Number in a reverse code form: ";
    cin >> obr;
    int n = size(obr);
    if (obr[0] == '1') // making all ones zeros and vice versa if the number is negative
    {
        for (int i = 1; i < n; i++)
        {
            if (obr[i] == '0') obr[i] = '1';
            else if (obr[i] == '1') obr[i] = '0';
        }

    }
    string curr;
    double ans;
    for (int i = 1; i < n; i++)
    {
        if (obr[i] == '.') // when . is reached, starting to calculate the fractional part
        {
            ans += todec(curr);
            curr = ""; // clear the string
        }
        else curr += obr[i];
    }
    if (obr[0] == '1') ans *= -1;
    cout << "The number in natural form: ";
    cout << fixed << setprecision(12); // always adding . and zeros to the answer (w/o this answer would be "1" but not "1.0"
    cout << ans + todec_drob(curr);
}
