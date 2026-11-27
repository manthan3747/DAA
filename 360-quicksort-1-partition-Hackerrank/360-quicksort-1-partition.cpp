
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1000];
    int left[1000], right[1000];
    int l = 0, r = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pivot = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < pivot)
        {
            left[l] = arr[i];
            l++;
        }
        else
        {
            right[r] = arr[i];
            r++;
        }
    }

    for(int i = 0; i < l; i++)
        cout << left[i] << " ";

    cout << pivot << " ";

    for(int i = 0; i < r; i++)
        cout << right[i] << " ";

    return 0;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna