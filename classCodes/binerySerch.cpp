#include <iostream>
using namespace std;

int binarySearch(int a[], int first, int last, int item){
    int mid;
    while(first<=last){
        mid = (first+last)/2;

        if(a[mid] == item){
            return mid;
        }
        if(item<a[mid]){
            last = mid-1;
        }
        else{
            first = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {7,11,17,25,32,33,40,66,75,87};
    int n = sizeof(arr)/sizeof(arr[0]);
    int item;

    
    cout << "Enter an item:" << endl;
    cin>>item;


    int idx = binarySearch(arr, 0,n-1, item);
    if(idx != -1){
        cout<<item << " is found at "<<idx<<endl;
    }
    else{
        cout<<item<<"is not found" <<endl;
    }
    return 0;
}