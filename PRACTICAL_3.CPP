#include <stdio.h>
using namespace std;

void maxHeapify(int arr[], int n, int i) {

    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

 
    if (left < n && arr[left] > arr[largest])
        largest = left;
   
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

   
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
   
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
  
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}


void maxHeapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
       
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        maxHeapify(arr, i, 0);
    }
}

void minHeapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
       
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        minHeapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main() {

    int n, choice;

    while (1) {

      
        printf("\nEnter number of elements: ");
        scanf("%d", &n);
        int arr[n];
        
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("\nOriginal array: ");
        printArray(arr, n);
        printf("\n1. Max Heap Sort");
        printf("\n2. Min Heap Sort");
       
        printf("\n\nEnter your choice (1-2): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                
                maxHeapSort(arr, n);
                printf("Array after Max Heap Sort: ");
                printArray(arr, n);
                break;
            case 2:
                minHeapSort(arr, n);
                printf("Array after Min Heap Sort: ");
                printArray(arr, n);
                break;
            
                return 0;

            default:

                printf("\nEnter a Valid choice..\n");
        }
    }

    return 0;
}
