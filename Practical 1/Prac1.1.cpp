#include <iostream>
using namespace std;
int main() {
    int n, h;
    cout << "Enter number of items: ";
    cin >> n;
    int a[n];
    cout << "Enter the items: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter number of hours: ";
    cin >> h;

    while (h > 0) {
        int temp = a[0];

        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i + 1];
        }

        a[n - 1] = temp;

        h--;
    }
    cout << "Final order: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}