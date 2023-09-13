//binary iterative
#include<iostream>
using namespace std;
int binaryIterative(int arr[],int size,int target){
    int left=0;
    int right=size-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5};
    int target=4;
    int size=5;
    int sol=binaryIterative(arr,size,target);
    if(sol!=-1){
        cout<<"elment found at "<<sol;
    }
    else{
        cout<<"element not found";
    }
    return 0;
}
