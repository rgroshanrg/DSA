void push_back(int *arr, int ele, int size, int tail) {
    if((tail + 1) == size) {
        cout << "\nError: Array is Full - Cannot Push More";
    } else {
        ++tail;
        arr[tail] = ele;
    }
}