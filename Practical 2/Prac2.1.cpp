#include <iostream>
using namespace std;
int iterative(string arr[], int n, string target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
int recursive(string arr[], int n, string target, int index)
{
    if (index == n)
        return -1;

    if (arr[index] == target)
        return index;

    return recursive(arr, n, target, index + 1);
}
int main()
{
    int n, choice;
    cout << "Enter number of license plates: ";
    cin >> n;
    string arr[n];
    cout << "Enter license plates:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string target;
    cout << "Enter target plate: ";
    cin >> target;
    cout << "\n1. Iterative Search";
    cout << "\n2. Recursive Search";
    cout << "\nEnter choice: ";
    cin >> choice;
    int pos;
    if (choice == 1)
        pos = iterative(arr, n, target);
    else if (choice == 2)
        pos = recursive(arr, n, target, 0);
    else
    {
        cout << "Invalid Choice";
        return 0;
    }
    if (pos != -1)
        cout << "Plate found at position: " << pos + 1;
    else{
        cout << "Plate not found.";
    }
    return 0;
} 