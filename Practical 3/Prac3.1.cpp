#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of the marksheets to be entered: ";
    cin>>n;
    float marksheet[n];
    cout<<"Enter the values: ";
    for(int i=0; i<n; i++){
        cin>>marksheet[i];
    }
    float bubblesort[n];

    //BUBBLE SORTING
    cout<<endl;
    for (int i=0; i<n; i++){
        bubblesort[i] = marksheet[i];
    }
    //Here the i is not used for comparing
    //It is used for determining the pair
    //if i=0; it represents the first two numbers
    //Now when i=1; the pointer moves forward and represent the 2 and 3 digit as pair 2
    //while the j is used for comparing
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(bubblesort[j] >= bubblesort [j+1])
            {
                float temp;
                temp = bubblesort[j];
                bubblesort[j] = bubblesort[j+1];
                bubblesort[j+1] = temp;
            }
        }
    }
    cout<<"BUBBLE SORT::--"<<endl;
    for (int i=0; i<n; i++){
        cout<<bubblesort[i]<<endl;
    }


    //INSERTION SORTING
    float insertionsort[n];
    for (int i=0; i<n; i++){
        insertionsort[i] = marksheet[i];
    }
    //Here to shift the numbers the use of i and j are used
    //The index starts from one as the 0 index is already considered sorted.
    for(int i=1; i<n; i++){
        float key = insertionsort[i];
        int j;
        for(j=i-1; j>=0; j--){
            if(insertionsort[j]>key){
                insertionsort[j+1] = insertionsort[j];
            }else 
                break;
        }
        insertionsort[j+1] = key;
    }
    cout<<"INSERTION SORT::--"<<endl;
    for (int i=0; i<n; i++){
        cout<<insertionsort[i]<<endl;
    }


    //SELECTION SORTING
    float selectionsort[n];
    for(int i=0; i<n; i++){
        selectionsort[i]=marksheet[i];
    }
    //This sorting checks and sorts using the minimum number of the array
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++){
            if (selectionsort[j]<selectionsort[min]){
                min = j;
            }
            float temp = selectionsort[i];
            selectionsort[i] = selectionsort[min];
            selectionsort [min] = temp;
        }
    }
    cout<<"SELECTION SORT::--"<<endl;
    for (int i=0; i<n; i++){
        cout<<selectionsort[i]<<endl;
    }
}