#include<bits/stdc++.h>
using namespace std;
/*
    For Divide and Conquer Strategy
    
    Logic

    1.) Find mid of both arrays
        * we have to find element at k-1 index so here k = k-1
    2.) if mid1+mid2 < k 
            if arr1[mid1] > arr2[mid2]
                that means elements of arr2 from 0 to mid2 are of no use so neglect them
                reduce k = k-mid2-1
                update starting of arr2 to arr2+mid2+1
            else 
                means elements of arr1 from 0 to mid1 are of no use so neglect them
                reduce k = k-mid1-1
                update starting of arr1 to arr1+mid1+1
        else 
            if arr1[mid1] > arr2[mid2]
                that means elements of arr1 from mid1 to end are of no use so neglect them
                no need to update k just update end ptr to arr1+mid1
            else
                that means elements of arr2 from mid2 to end are of no use so neglect them
                no need to update k just update end ptr to arr2+mid2
*/
int findKth(int *arr1,int *arr2,int *end1,int *end2,int k){
    if(arr1 == end1){
        return arr2[k];
    }
    
    if(arr2 == end2){
        return arr1[k];
    }

    int mid1 = (end1-arr1)/2;
    int mid2 = (end2-arr2)/2;

    if(mid1+mid2 < k){
        if(arr1[mid1] > arr2[mid2]){
            return findKth(arr1,arr2+mid2+1,end1,end2,k-mid2-1);
        }else{
            return findKth(arr1+mid1+1,arr2,end1,end2,k-mid1-1);
        }
    }else{
        if(arr1[mid1] > arr2[mid2]){
            return findKth(arr1,arr2,arr1+mid1,end2,k);
        }else{
            return findKth(arr1,arr2,end1,arr2+mid2,k);
        }
    }

}
int main(){
    int arr1[] =  {2, 3, 6, 7, 9};
    int arr2[] =  {1, 4, 8, 10};
    int k = 5;
    cout<<findKth(arr1,arr2,arr1+5,arr2+4,k-1)<<endl;
}