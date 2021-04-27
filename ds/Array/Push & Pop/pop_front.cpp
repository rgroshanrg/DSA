void pop_front(int *arr,int tail) {
    if(tail == -1) {
        cout << "\nError: Array is Empty - Nothing to Pop";
    } else {
        --tail;
        for(int i = 0; i <= tail; ++i) {
            arr[i] = arr[i + 1];
        }
    }
}