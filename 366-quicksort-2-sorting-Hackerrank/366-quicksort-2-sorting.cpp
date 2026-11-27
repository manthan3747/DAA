
#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &arr) {

    if(arr.size() <= 1)
        return;

    int pivot = arr[0];

    vector<int> left, right;

    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] < pivot)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }

    quickSort(left);
    quickSort(right);

    for(int i = 0; i < left.size(); i++)
        cout << left[i] << " ";

    cout << pivot << " ";

    for(int i = 0; i < right.size(); i++)
        cout << right[i] << " ";

    cout << endl;

    arr.clear();

    for(int i = 0; i < left.size(); i++)
        arr.push_back(left[i]);

    arr.push_back(pivot);

    for(int i = 0; i < right.size(); i++)
        arr.push_back(right[i]);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna