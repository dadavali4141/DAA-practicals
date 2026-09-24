#include <iostream>
#include<vector>
using namespace std ;


int combCoin(vector<int>coin,int amount ){
    int m = coin.size();
    int n = amount ;
    int dp[m+1][n+1];

    // We fill the value with 1 for the amount 0 
   for(int i = 0 ; i <= m ; i++){
     dp[i][0] = 1;
   }
   
   //if we have no coins then we can't pay means zero ways 
   for (int j = 1; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    // We construct whole dynamic programming table 
   for (int i = 1 ; i <= m ; i++){
        for (int j = 1 ; j <= n ; j++){
            if (coin[i - 1] > j){
                    dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]];
            }
        }
   }
   return dp[m][n];
}


int main (){
    int n,amount  ;
    vector<int> coin;

    cout << "Enter the amount you want to pay  : ";
    cin >> amount  ; 

    cout <<"Enter the  number of  varients of the coin : " ;
    cin >> n;

    coin.resize(n);

    cout << "Enter the varients of the coin : " ;
    for (int i = 0 ; i < n ; i++){
        cin >> coin[i];
    }

    int result = combCoin(coin , amount  );

    cout << "Number of ways to give the amount is : " << result ;

    return 0 ;
}