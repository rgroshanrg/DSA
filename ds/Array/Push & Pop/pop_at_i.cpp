void pop_ati(int *arr, int pos, int tail) {
    if(tail == -1) {
        cout << "\nError: Array is Empty - Nothing to Pop";
    } else {
        --tail;
        for(int i = pos; i <= tail; ++i) {
            arr[i] = arr[i + 1];
        }
    }
}