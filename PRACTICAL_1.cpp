// In this Practical we coverting the sorting algorithm present in cpp
#include <iostream>
using namespace std;

// Selection Sort
void selectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        swap(arr[i],arr[min]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];

    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1)
        arr[k++]=L[i++];

    while(j<n2)
        arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

// Display
void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[100], n, choice;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"\n1. Selection Sort";
    cout<<"\n2. Insertion Sort";
    cout<<"\n3. Bubble Sort";
    cout<<"\n4. Merge Sort";
    cout<<"\n5. Quick Sort";
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            selectionSort(arr,n);
            break;

        case 2:
            insertionSort(arr,n);
            break;

        case 3:
            bubbleSort(arr,n);
            break;

        case 4:
            mergeSort(arr,0,n-1);
            break;

        case 5:
            quickSort(arr,0,n-1);
            break;

        default:
            cout<<"Invalid Choice";
            return 0;
    }

    cout<<"\nSorted Array: ";
    display(arr,n);

    return 0;
}
