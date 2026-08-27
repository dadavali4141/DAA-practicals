#include <iostream>
using namespace std;


long long factorialIterative(int n)
{
    long long result = 1;

    for(int i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}


long long factorialRecursive(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;
    while(1) {

    cout << "Enter a number: ";
    cin >> n;

    if(n < 0)
    {
        cout << "Factorial is not defined for negative numbers.";
        return 0;
    }

    cout << "\nUsing Iterative Method:";
    cout << "\nFactorial = " << factorialIterative(n);

    cout << "\n\nUsing Recursive Method:";
    cout << "\nFactorial = " << factorialRecursive(n);

    }
    

    return 0;
}
