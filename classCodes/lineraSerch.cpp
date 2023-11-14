#include <iostream>
using namespace std;

int linear_search(int a[], int n, int item){
    for(int i=0; i<n;i++){
        if(item ==a[i]){
            return i;
        }
    }
     return -1;
}

int main(){
    int arr[] = {2,7,4,1,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int item;

    
    cout << "Enter an item:" << endl;
    cin>>item;


    int idx = linear_search(arr, n, item);
    if(idx != -1){
        cout<<item << " is found at "<<idx<<endl;
    }
    else{
        cout<<item<<"is not found" <<endl;
    }
    return 0;
}