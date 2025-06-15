#include <iostream>
using namespace std;

int main() {
    int arr[20], n, mid, value;
    
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mid = n/2;
    if(n%2==0){  
    cout<<"mid elements are"<<endl;
    cout<<arr[mid-1]<<","<<arr[mid]<<endl;
    }
    else {
    cout<<"mid element is"<<endl;
    cout<<arr[mid]<<endl;
    }


    return 0;
}
