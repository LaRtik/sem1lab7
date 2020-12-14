#include <iostream>

using namespace std;

void dec(int &n, int q = -1)
{
    n = n + q;
}

int main()
{
    cout << "Enter the dividend number: ";
    int n, old_n;
    cin >> n;
    old_n = n;

    cout << "Enter the divider number: ";
    int b;
    cin >> b;

    while (true)
    {
        if (n >= b)
        {
            for (int i = 0; i < b; i++)
            {
                dec(n);
            }
            continue;
        }

        if (n == 0)
        {
            cout << "The number " << old_n << " can be divided by number " << b << endl;
            return 0;
        }

        cout << "The number " << old_n << " can not be divided by number " << b << endl;
        return 0;

    }
}
