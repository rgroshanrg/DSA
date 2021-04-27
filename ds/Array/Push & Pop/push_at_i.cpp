void push_ati(int *arr, int ele, int pos, int size, int tail) {
    if((tail + 1) == size) {
        cout << "\nError: Array is Full - Cannot Push More";
    } else {
        ++tail;
        for(int i = tail - 1; i >= pos; --i) {
            arr[i + 1] = arr[i];
        }
        arr[pos] = ele;
    }

}