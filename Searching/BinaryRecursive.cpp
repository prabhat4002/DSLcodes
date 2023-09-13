//Binary Search Recursive
#include<iostream>
using namespace std;
int binaryR(int arr[],int left, int right,int target){
    if(left<=right){
        int mid=left=(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            return binaryR(arr,mid+1,right,target);
        }
        else{
            return binaryR(arr,left,right-1,target);
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5};
    int target=4;
    int n=5;
    int sol=binaryR(arr,0,n-1,target);
    if(sol!=-1){
        cout<<"elment found at: "<<sol;
    }
    else{
        cout<<"element not found";
    }
    return 0;
}
