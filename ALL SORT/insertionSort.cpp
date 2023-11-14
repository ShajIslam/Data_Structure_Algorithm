#include <iostream>
using namespace std;


void insertion_sort(int a[], int n){
    for(int i=1; i<n; i++){
        int temp = a[i];
        int j = i-1;
        while(a[j] >=0 && a[j] > temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

int main(){
    int a[] = {32,15, 23, 48, 8};
    int n = 5;

    insertion_sort(a, n);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}