#include<iostream>
using namespace std;

void merge_sort(int, int, int[]);
void display(int, int[]);
void merge(int, int, int, int[]);

int main(){
    int array[]={9,3,7,3,8,3,4,5,6,7,8,9};
    int size=sizeof(array)/sizeof(array[0]);
    cout<<"Before sorting \n";
    display(size, array);
    merge_sort(0, size-1, array);
    cout<<"After sorting \n";
    display(size, array);
    return 0;
}

void merge_sort(int lb, int ub, int array[]){
    if(lb<ub){
        int mid = (lb+ub)/2;

        merge_sort(lb, mid, array);
        merge_sort(mid+1, ub, array);

        merge(lb, mid, ub, array);
    }
}

void display(int size, int array[]){
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" | ";
    }
    cout<<"\n";
}

void merge(int lb, int mid, int ub, int array[]){
    int size_new=ub-lb+1;
    int i,j,k;
    int* new_array= new int[size_new];

    for(i=lb, j=mid+1, k=0; i<=mid && j<=ub;){
        if(array[i] < array[j]){
            new_array[k++]=array[i++];
        }
        else{
            new_array[k++]=array[j++];
        }
    }

    while(i<=mid){
        new_array[k++]=array[i++];
    }
    while(j<=ub){
        new_array[k++]=array[j++];
    }

    for(int p = lb, q=0; p<=ub;){             //Transferring contents to original array
        array[p++]=new_array[q++];
    }
    
}


