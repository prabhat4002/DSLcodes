#include<iostream>
using namespace std;
int linearSearch(int n,int arr[],int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5};
    int target=7;
    int size=5;
    int sol=linearSearch(size,arr,target);
    if(sol!=-1){
        cout<<"elment found at "<<sol;
    }
    else{
        cout<<"element not found";
    }
    return 0;
}
