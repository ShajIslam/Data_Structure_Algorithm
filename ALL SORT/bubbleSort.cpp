#include <iostream>
using namespace std;


int main(){
    int a[]={20, 30, 8, 10, 14,7};
    int n = 6;

    for(int i= 0; i<n;i++){
        for(int j=0; j<n-1-i; j++){
            if(a[j]> a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

}