#include <iostream>
using namespace std;

int main() {
    int arr[20], n, mid, value;
    
    cout << "Enter number of elements: ";
    cin >> n;
    mid = n/2;


    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nInsert Operation in mid:\n";
    cout << "Enter value to insert: ";
    cin >> value;

    for (int i = n; i > mid; i--) {
        arr[i] = arr[i - 1];
    }
    arr[mid] = value;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
