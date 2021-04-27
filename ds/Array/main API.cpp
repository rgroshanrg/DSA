#include <iostream>
using namespace std;

int tail = -1;

void traverse(int *arr);
void push_back(int *arr, int ele, int size);
void push_front(int *arr, int ele, int size);
void push_ati(int *arr, int ele, int pos, int size);
void pop_back();
void pop_front(int *arr);
void pop_ati(int *arr, int pos);
void sort(int *arr);

void traverse(int *arr) {
    cout << "\n Indices  -> ";
    for(int i = 0; i <= tail; ++i) {
        cout << "\t" << i ;
    }
    cout << "\n\n Elements -> ";
    for(int i = 0; i <= tail; ++i) {
        cout << "\t" << arr[i] ;
    }
}
void push_back(int *arr, int ele, int size) {
    if((tail + 1) == size) {
        cout << "\nError: Array is Full - Cannot Push More";
    } else {
        ++tail;
        arr[tail] = ele;
    }
}
void push_front(int *arr, int ele, int size) {
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
void push_ati(int *arr, int ele, int pos, int size) {
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
void pop_back() {
    if(tail == -1) {
        cout << "\nError: Array is Empty - Nothing to Pop";
    } else {
        --tail;
    }
}
void pop_front(int *arr) {
    if(tail == -1) {
        cout << "\nError: Array is Empty - Nothing to Pop";
    } else {
        --tail;
        for(int i = 0; i <= tail; ++i) {
            arr[i] = arr[i + 1];
        }
    }
}
void pop_ati(int *arr, int pos) {
    if(tail == -1) {
        cout << "\nError: Array is Empty - Nothing to Pop";
    } else {
        --tail;
        for(int i = pos; i <= tail; ++i) {
            arr[i] = arr[i + 1];
        }
    }
}
void sort(int *arr) {
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
        //  swap(&arr[j], &arr[j+1]);
            swapped = true; 
        } 
    } 

        // IF no two elements were swapped by inner loop, then break 
        if (swapped == false) 
        break; 
    }
}

int main()
{
    unsigned int size;
    cout << "Please enter the max size of the Array : ";
    cin >> size;
    int arr[size];
    cout << "\n\nEnter " << size << " space Separated Integers : ";
    for(int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    tail = size - 1;
    int ch, ele, pos;
    
    while(ch != 10) {
        cout << "\n0. Traverse";    //O(n)
        cout << "\n1. Push back";   //O(1), in worst case (when array is full) O(n)
        cout << "\n2. Push front";  //O(n)
        cout << "\n3. Push at given location";  //O(n) in worst case
        cout << "\n4. Pop back";    //O(1)
        cout << "\n5. Pop front";   //O(n)
        cout << "\n6. Pop at given location";  //O(n) in worst case
        cout << "\n7. Sort";
        cout << "\n\n10. Exit";
        cout << "\n\nEnter your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 0: traverse(arr);
            break;
        case 1:
            cout << "\n Enter the Element to be Pushed : ";
            cin >> ele;
            push_back(arr, ele, size);
            break;
        case 2: 
            cout << "\n Enter the Element to be Pushed : ";
            cin >> ele;
            push_front(arr, ele, size);
            break;
        case 3:
            cout << "\n Enter the Element to be Pushed : ";
            cin >> ele;
            pos = -1;
            while(pos < 0 || pos > tail) {
                cout << "\n Enter the Position to be Pushed : ";
                cin >> pos;
                if(pos < 0 || pos > tail) {
                    cout << "\n Warning : Please Enter a Valid Position, (from 0 to " << tail << ")";
                }
            }
            push_ati(arr, ele, pos, size);
            break;
        case 4: pop_back();
            break;
        case 5: pop_front(arr);
            break;
        case 6: 
            pos = -1;
            while(pos < 0 || pos > tail) {
                cout << "\n Enter the Position to be Popped : ";
                cin >> pos;
                if(pos < 0 || pos > tail) {
                    cout << "\n Warning : Please Enter a Valid Position, (from 0 to " << tail << ")";
                }
            }
            pop_ati(arr, pos);
            break;
        case 7: sort(arr);
            break;
        case 10: exit(0);
            break;    
        default:
            cout << "\n Enter correct choice, try again...";
            break;
        }
    }
    return 0;
}