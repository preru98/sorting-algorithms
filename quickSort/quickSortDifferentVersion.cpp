#include<iostream>
using namespace std;

void quick_sort(int, int, int[]);
int  partition(int, int, int[]);
void display(int [],int);
void swap(int*,int*);

int main(){
    int array[]={6,3,0,9,3,8,2};
    int size=sizeof(array)/sizeof(array[0]);
    display(array,size);
    quick_sort(0,size-1,array);
    cout<<endl;
    display(array,size);
    return 0;
}

void quick_sort(int lb,int ub,int array[]){
    if(lb<ub){
        int loc=partition(lb,ub,array);
        quick_sort(lb,loc-1,array);
        quick_sort(loc+1,ub,array);
    }
}

void display(int array[],int size){
    for(int i=0;i<size;i++){    
        cout<<array[i]<<" | ";  
    }
}

void swap(int* a,int* b){
    int c=*a;
    *a=*b;
    *b=c;
}

int partition(int lb,int ub,int array[]){
    int pivot=array[lb];
    int smaller_area=lb;
    for(int i=lb+1;i<=ub;i++){
        if(array[i]<=pivot){
            smaller_area++;
            swap(&array[i],&array[smaller_area]);
        }
    }
    swap(&array[lb],&array[smaller_area]);
    return smaller_area;
}