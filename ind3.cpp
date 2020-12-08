#include <iostream>

using namespace std;

int size(string s) // returns the size of string
{
    for (int i = 0; i < 1000000; i++)
    {
        if (s[i] == '\0') return i;
    }
    return -1;
}


void nat_to_rev(string &s) // converting number from natural binary form to reverse binary form
{
    if (s[0] == '0') return;
    for (int i = 1; i < size(s); i++)
    {
        if (s[i] == '1') s[i] = '0';
        else if (s[i] == '0') s[i] = '1';
    }
    return;
}

int drobn_size(string s) // returns the size of the fractional part of the number
{
    int i = 0;
    for (; i < size(s); i++)
    {
        if (s[i] == '.') break;
    }

    return size(s) - i;
}

int cel_size(string s) // returns the size of the integer part of the number
{
    int i = 1;
    for (; i < size(s); i++)
    {
        if (s[i] == '.') break;
    }
    return i;
}

string plusing_rev(string number1, string number2) // summing two numbers in reverse binary form
{
    string result;

    // making all fractional parts the same size
    while (drobn_size(number1) > drobn_size(number2))
    {
        number2 += '0';
    }

    while (drobn_size(number1) < drobn_size(number2))
    {
        number1 += '0';
    }

    int sz = size(number1);

    bool add = false; // additional bit
    for (int i = sz - 1; i >= 0; i--)
    {
        if (number1[i] == '.')
        {
            result = '.' + result;
            continue;
        }

        int curr1 = number1[i] - '0';
        int curr2 = number2[i] - '0';

        switch (curr1 + curr2 + add)
        {
        case 3:
            result = '1' + result;
            add = true;
            break;
        case 2:
            result = '0' + result;
            add = true;
            break;
        case 1:
            result = '1' + result;
            add = false;
            break;
        case 0:
            result = '0' + result;
            add = false;
            break;
        default:
            break;
        }
    }
    if (add == true) // if the additional bit is true, adding "1" to last bits
    {
        string to_add;
        for (int i = 0; i < 16; i++) to_add += '0';
        to_add += '.';
        for (int i = 0; i < drobn_size(number1) - 2; i++) to_add += '0';
        to_add += '1';
        result = plusing_rev(result, to_add);
    }
    return result;
}

void fix(string &s) // if the integer part size is <16, making it's size equal 16
{
    string result;
    result += s[0];
    for (int i = 0; i < 16 - cel_size(s); i++)
    {
        result += '0';
    }
    for (int i = 0; i < size(s) - 1; i++)
    {
        result += s[i + 1];
    }
    s = result;
}

int main()
{
    string number1, number2;
    cout << "Enter two numbers to sum in binary natural form: " << endl << endl;
    cout << "NOTE: use the format x000000.00000 where zeros are any binary digit and X is sign bit" << endl;
    cout << "NOTE: SIGN BIT - 0 means that the given number is positive, otherwise it's negative" << endl;
    cout << "NOTE: you can't use more than 15 digits in the integer part of the number" << endl;
    cout << "NOTE: integer part of the number must contain at least 2 digits, fractional must contain at least 1" << endl << endl;
    cin >> number1 >> number2;
    fix(number1);
    fix(number2);
    nat_to_rev(number1);
    nat_to_rev(number2);

    string ans = plusing_rev(number1, number2);
    nat_to_rev(ans);
    cout << "The result of summing two numbers (binary natural form): " << endl;
    cout << ans;

    return 0;
}
