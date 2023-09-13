#include<iostream>
using namespace std;
int bubbleSort(int n, int arr[]){
    bool swapped=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
    }
}
int main(){
    int n;
    cout<<"enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<endl<<"enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"original elements of the array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    bubbleSort(n,arr);
    cout<<"sorted elements: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
