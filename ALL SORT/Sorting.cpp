
#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

void selectionSort(int arr[], int size) {
    int min;
    for(int i = 0; i < size - 1; i++) {
        min = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[min] > arr[j]) min = j;
        }
        std::swap(arr[i], arr[min]);
    }
}

void insertionSort(int arr[], int size) {
    int j, key;
    for(int i = 1; i < size; i++) {
        j = i - 1;
        key = arr[i];
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int size) {
    bool flag = false;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

int q_sort(const void *a, const void *b) {
    const int *x = static_cast<const int*>(a);
    const int *y = static_cast<const int*>(b);
    return *x >= *y;
}

void merge(int *arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *a = new int[n1];
    int *b = new int[n2];
    for(int i = 0; i < n1; i++) a[i] = arr[low + i];
    for(int j = 0; j < n2; j++) b[j] = arr[mid + j + 1];
    int i, j, k;
    i = j = 0;
    k = low;
    while(i < n1 && j < n2) {
        if(a[i] <= b[j]){
            arr[k] = a[i];
            k = k+1;
            i=i+1;
        } 
        else arr[k++] = b[j++];
    }
    while(i < n1) arr[k++] = a[i++];
    while(j < n2) arr[k++] = b[j++];
    delete[] a;
    delete[] b;
}

void mergeSort(int *arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int partition(int arr[], int low, int high) {
    int i = low - 1, pivot = arr[high];
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int count(int arr[], int low, int high) {
    if(low == high) return arr[low];
    return arr[high] + count(arr, 0, high-1);
}

void heapSort(int arr[], int size) {
    function<void(int[], int, int)> heapify;
    heapify = [&](int arr[], int size, int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int parent = (i - 1) / 2;
        int largest = i;
        if(left < size && arr[left] > arr[largest]) largest = left;
        if(right < size && arr[right] > arr[largest]) largest = right;
        if(i != largest) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, size, largest);
        }
    };
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for(int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand((unsigned int)std::chrono::system_clock::now().time_since_epoch().count());
    int *arr = new int[10];
    int size = 10;

    auto fillrand = [] (int *arr, int size) {
        for(int i = 0; i < size; i++) arr[i] = 1 + rand() % 100;
    };
    auto print = [](int *arr, int size) {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    };

    fillrand(arr, size);
    uint init = count(arr, 0, size - 1);
    print(arr, size);
    mergeSort(arr, 0, 9);
    merge(arr, 0, 4, 9)
    //qsort(arr, size, sizeof(arr[0]), q_sort);
    print(arr, size);
    cout << "Array Matches: " << (init == count(arr, 0, size - 1)) << endl;
}

