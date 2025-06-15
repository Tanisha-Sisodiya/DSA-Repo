#include <iostream>
using namespace std;

int main() {
    int arr[20], n, pos, value;

    // Input initial array
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nInsert Operation:\n";
    cout << "Enter position to insert (0-based index): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\nDelete Operation:\n";
    cout << "Enter position to delete (0-based index): ";
    cin >> pos;

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
