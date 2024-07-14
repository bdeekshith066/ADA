
#include<stdio.h>

int partition(int a[], int low, int high);

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);
        quickSort(a, low, mid - 1);
        quickSort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        while (a[i] <= pivot && i <= high)
            i++;
        while (a[j] > pivot && j >= low)
            j--;
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
```

## Explanation of Quick Sort

### `quickSort` Function

This function recursively sorts the array by dividing it around a pivot element.

#### Implementation

```c
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high); // Partition the array and get the pivot index
        quickSort(a, low, mid - 1); // Recursively sort the elements before the pivot
        quickSort(a, mid + 1, high); // Recursively sort the elements after the pivot
    }
}
```

### `partition` Function

This function selects a pivot element and partitions the array into two halves around the pivot.

#### Implementation

```c
int partition(int a[], int low, int high) {
    int pivot = a[low]; // Choose the pivot element (first element in this case)
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot) // Find an element greater than the pivot
            i++;
        while (j >= low && a[j] > pivot) // Find an element less than or equal to the pivot
            j--;
        if (i < j) { // Swap elements if i is less than j
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // Swap the pivot element with the element at index j
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j; // Return the pivot index
}
```

### `main` Function

This function initializes the array, reads input from the user, calls `quickSort`, and prints the sorted array.

#### Implementation

```c
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1); // Call quickSort to sort the array
    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
```

## Detailed Example Walkthrough

Consider an example array: `[38, 27, 43, 3, 9, 82, 10]`.

1. **Initial Call:** `quickSort(a, 0, 6)`

2. **First Partition:**
   - Pivot chosen: `38`
   - Partitioned array: `[10, 27, 3, 9, 38, 82, 43]`
   - Pivot index after partition: `4`

3. **First Level of Recursion:**
   - Left subarray: `quickSort(a, 0, 3)`
   - Right subarray: `quickSort(a, 5, 6)`

4. **Second Partition (Left Subarray):**
   - Pivot chosen: `10`
   - Partitioned array: `[3, 9, 10, 27]`
   - Pivot index after partition: `2`

5. **Further Recursions:**
   - Continue partitioning and sorting the subarrays recursively until each subarray has one element.

6. **Final Sorted Array:** `[3, 9, 10, 27, 38, 43, 82]`

### Explanation of `partition` Function

1. **Initialization:**
   - `pivot` is set to the first element of the array.
   - `i` starts at `low + 1`.
   - `j` starts at `high`.

2. **Partitioning:**
   - Increment `i` until an element greater than the pivot is found.
   - Decrement `j` until an element less than or equal to the pivot is found.
   - If `i` is less than `j`, swap the elements at `i` and `j`.

3. **Placing the Pivot:**
   - Swap the pivot element with the element at `j`.

4. **Return Pivot Index:**
   - Return the index `j` where the pivot element is now located.

This process ensures that elements less than the pivot are on the left, and elements greater than the pivot are on the right, facilitating recursive sorting of the subarrays.
