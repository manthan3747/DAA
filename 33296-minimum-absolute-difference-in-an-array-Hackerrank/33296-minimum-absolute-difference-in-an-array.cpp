
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[100000];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int minDiff = abs(arr[1] - arr[0]);

    for(int i = 1; i < n - 1; i++)
    {
        int diff = abs(arr[i + 1] - arr[i]);

        if(diff < minDiff)
        {
            minDiff = diff;
        }
    }

    cout << minDiff;

    return 0;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna