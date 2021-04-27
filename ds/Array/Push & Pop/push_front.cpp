void push_front(int *arr, int ele, int size, int tail) {
    if((tail + 1) == size) {
        cout << "\nError: Array is Full - Cannot Push More";
    } else {
        ++tail;
        for(int i = tail - 1; i >= 0; --i) {
            arr[i + 1] = arr[i];
        }
        arr[0] = ele;
    }
}