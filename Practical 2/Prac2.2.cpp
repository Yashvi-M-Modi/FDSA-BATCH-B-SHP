#include <iostream>
using namespace std;
int iterativeSearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1; 
        else
            high = mid - 1;
    }
    return -1;
}
int recursiveSearch(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return recursiveSearch(arr, mid + 1, high, target);
    else
        return recursiveSearch(arr, low, mid - 1, target);
}
int main()
{
    int n, choice;

    cout<<"Enter number of book codes you want to enter: ";
    cin>>n;

    int arr[n];

    cout<<"Enter sorted book codes: ";
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int target;
    cout<<"Enter target code: ";
    cin>>target;
    cout<<"Enter your choice from the menu: "<<endl;
    cout<<"1. Iterative Binary Search"<<endl;
    cout<<"2. Recursive Binary Search"<<endl;
    cout<<"Enter choice: "<<endl;
    cin>>choice;
    int pos;
    if (choice == 1)
        pos = iterativeSearch(arr, n, target);
    else if (choice == 2)
        pos = recursiveSearch(arr, 0, n - 1, target);
    else{
        cout<<"Invalid Choice";
    }
    if (pos != -1)
        cout<<"Book code found at position: "<<pos + 1;
    else
        cout<<"Book code not found.";

    return 0;
} 