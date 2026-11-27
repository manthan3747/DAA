
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;

    while(q--)
    {
        int n, k;
        cin >> n >> k;

        int a[1000], b[1000];

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        sort(a, a + n);
        sort(b, b + n, greater<int>());

        bool flag = true;

        for(int i = 0; i < n; i++)
        {
            if(a[i] + b[i] < k)
            {
                flag = false;
                break;
            }
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna