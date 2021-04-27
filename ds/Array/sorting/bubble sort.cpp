void sort(int *arr, int tail) { // tail -> last index of array
    int i, j; 
    bool swapped; 
    for (i = 0; i <= tail; i++) 
    { 
        swapped = false; 
        for (j = 0; j <= tail-i-1; j++) 
        { 
        if (arr[j] > arr[j+1]) 
        { 
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            swapped = true;
        } 
    } 
        if (swapped == false) 
        break; 
    }