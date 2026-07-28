// In this practical We will discuss about the Searching Algorithm

#include <iostream>
using namespace std;

void PrintingArray(int arr[], int n){
    cout << "Printing array Element: ";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int linearSearch(int arr[], int n, int t){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == t){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int t){
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while(s <= e){
        if(arr[mid] == t){
            return mid;
        }
        else if(arr[mid] > t){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return -1;
}

int main(){

    while(1){

        int n, choice, target;

        cout << "Enter the size of array: ";
        cin >> n;

        const int MAX_SIZE = 100;
        int arr[MAX_SIZE];

        cout << "Enter the elements of array : ";
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }

        cout << "Enter element for searching :- ";
        cin >> target;

        cout << "\n><====================================================================><\n";
        cout << "1.Linear Search\n2.Binary Search\n3.Exit\n";

        cout << "Enter Your choice (1-3) :- ";
        cin >> choice;

        switch(choice){

            case 1:
            {
                int result = linearSearch(arr, n, target);

                if(result != -1){
                    cout << "Element found at Index : " << result;
                }
                else{
                    cout << "Element not found!";
                }
                cout << endl;
                break;
            }

            case 2:
            {
                int result = binarySearch(arr, n, target);

                if(result != -1){
                    cout << "Element found at Index : " << result;
                }
                else{
                    cout << "Element not found";
                }
                cout << endl;
                break;
            }

            case 3:
            {
                cout << "You are Exiting the Program..........";
                cout << "\nThanking you...............";
                cout << endl;
                
            }

            default:
                cout << "Enter a Valid choice..\n\n";
        }
    }

    return 0;
}

// Conclusion 

//