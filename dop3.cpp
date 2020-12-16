#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string ans;


    while (n != 0)
    {
        ans = char(n % 3 + '0') + ans;
        n /= 3;
    }


    int pos = ans.find("10");
    while (pos + 1)
    {
        ans.replace(pos, 2, "3");
        pos = ans.find("10");
    }

    pos = ans.find("20");
    while (pos + 1)
    {
        ans.replace(pos, 2, "13");
        pos = ans.find("20");
    }

    pos = ans.find("30");
    while (pos + 1)
    {
        ans.replace(pos, 2, "23");
        pos = ans.find("30");
    }


    cout << ans;

    return 0;
}
