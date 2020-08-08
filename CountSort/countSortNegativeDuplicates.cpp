/*
Problem :
    Perform countsort
    Duplicates allowed
    Negative numbers allowed
    0 allowed
Solution : 
    Create hashtable of array.
    Traverse hashtable and store the index where valid element is found in serial fashion.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int find_max_element(int[],int); 
void count_sort(int[],int);
void display(int[],int);

int main(){
    int array[]={-3,0,0,1,3,-2,2,-2,3,9,-9,0,0,0};
    int size=sizeof(array)/sizeof(array[0]);
    cout<<"\nBefore Sorting :\n";
    display(array,size);
    count_sort(array,size);
    cout<<"\nAfter Sorting :\n";
    display(array,size);
    return 0;
}

int find_max_element(int array[],int size){
    int a=INT32_MIN;
    for(int i=0;i<size;i++){
        if(array[i]>a){
            a=array[i];
        }
    }
    return a;
}
int find_min_element(int array[],int size){
    int a=INT32_MAX;
    for(int i=0;i<size;i++){
        if(array[i]<a){
            a=array[i];
        }
    }
    return a;
}

void count_sort(int array[],int size){

    // int max=find_max_element(array,size);
    // int min=find_min_element(array,size);
    int min_array=*min_element(array, array+size);
    int max_array=*max_element(array, array+size);
    int size_hash=max_array-min_array+1;
    int* hash = new int[size_hash];

    for (int i = 0; i < size; i++){
        hash[array[i]-min_array]++;
    }
    for(int i=0, j=0;i<size_hash;i++){
        while(hash[i]){
            array[j]=i+min_array;
            j++;
            hash[i]--;
        }
    }
}

void display(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" | ";
    }
}