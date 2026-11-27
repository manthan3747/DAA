
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int luck[100];
    int total = 0;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int l, t;
        cin >> l >> t;

        if(t == 0)
        {
            total += l;
        }
        else
        {
            luck[count] = l;
            count++;
        }
    }

    sort(luck, luck + count, greater<int>());

    for(int i = 0; i < count; i++)
    {
        if(i < k)
            total += luck[i];
        else
            total -= luck[i];
    }

    cout << total;

    return 0;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna