#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr [left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low;i<=high;i++) {
        arr[i] = temp[i - low];
    }

}

void mS(vector<int> &arr,int low, int high){
    if(low==high) return;
    int mid = (low+high)/2;
    mS (arr, low, mid);
    mS(arr, mid+1, high);
    merge (arr, low, mid, high);


}

void mergeSort(vector<int> &arr,int n){
    mS(arr,0,n-1);
}

int main(){
    int n = 7;
    vector<int> v = {64, 34, 25, 12, 22, 11, 90};

    

    mergeSort(v,n);
    for(auto p:v){
        cout<<p<<" ";
    }

 
return 0;
}