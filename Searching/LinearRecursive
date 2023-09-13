#include<iostream>
using namespace std;
int linearRecursive(int arr[],int start,int end,int target){
    if(start>end){
        return -1;
    }
    if(arr[start]==target){
        return start;
    }
    return linearRecursive(arr,start+1,end,target);
}
int main(){
    int arr[]={1,2,3,4,5};
    int target=4;
    int size=5;
    int sol=linearRecursive(arr,0,size-1,target);
    if(sol!=-1){
        cout<<"elment found at "<<sol;
    }
    else{
        cout<<"element not found";
    }
    return 0;
}
