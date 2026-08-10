#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of color codes you want to enter: ";
    cin>>n;
    //USING SELECTION SORTING FOR THE TASK GIVEN
    int colorcodes[n];
    cout<<"Enter your color codes: "<<endl;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        //CHECKING WHETHER THE INPUT IS VALID OR NOT
        if(temp >=0 && temp<3){
            colorcodes[i] = temp;
        }else{
            cout<<"Invalid Input!"<<endl;
            continue;
        }
        temp = 0;
    }
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(colorcodes[j]<colorcodes[min]){
                min = j;
            }
            int temp = colorcodes [i];
            colorcodes[i] = colorcodes[min];
            colorcodes[min] = temp;
        }
    }
    cout<<endl;
    cout<<"The color codes you entered are: "<<endl;
    for(int i=0; i<n; i++){
        cout<<colorcodes[i]<<endl;
    }
    cout<<"-----THE END-----"<<endl;
}