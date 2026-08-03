#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of book records: ";
    cin >> n;
    int books[n];
    cout << "Enter Book IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    cout << "Books borrowed more than once are: ";
    for (int i = 0; i < n; i++) {
        int count = 0;
        // Count how many times books[i] appears
        for (int j = 0; j < n; j++) {
            if (books[i] == books[j]) {
                count++;
            }
        }
        // Print only once
        if (count > 1) {
            bool printed = false;
            for (int k = 0; k < i; k++) {
                if (books[k] == books[i]) {
                    printed = true;
                }
            }
            if (!printed) {
                cout << books[i] << " ";
            }
        }
    }
    return 0;
}