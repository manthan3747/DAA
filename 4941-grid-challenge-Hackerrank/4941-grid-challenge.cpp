
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string grid[100];

        for(int i = 0; i < n; i++)
        {
            cin >> grid[i];
            sort(grid[i].begin(), grid[i].end());
        }

        bool flag = true;

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] > grid[i + 1][j])
                {
                    flag = false;
                    break;
                }
            }

            if(!flag)
                break;
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