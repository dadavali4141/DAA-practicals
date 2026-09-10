#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int chainMatrix(vector<int>& p, int n)
{
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    cout << "Enter number of Matrix: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter the dimensions of the matrix: ";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    int result = chainMatrix(p, n + 1);

    cout << "Minimum Multiplication cost is: " << result << endl;

    return 0;
}