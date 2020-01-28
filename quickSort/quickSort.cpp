#include<iostream>
using namespace std;

// prototypes
void display(int [],int);
void quickSort(int[],int,int);
void swap(int*,int*);
int partition(int[],int,int);

//main()
int main(){
    int numbers[]={7,5,3,2,1};     //worst case
    int numbers2[]={1,2,3,5,7};    //best case

    int size=sizeof(numbers)/sizeof(numbers[0]);
    display(numbers,size);
    quickSort(numbers,0,size-1);
    cout<<"After sorting \n";
    display(numbers,size);

    return 0;
}

//functions
void quickSort(int array[],int lb,int ub){

    int loc;
    if(lb<ub){
        loc=partition(array,lb,ub);
        quickSort(array,lb,loc-1);
        quickSort(array,loc+1,ub);
    }
}


int partition(int array[],int lb,int ub){
    int pivot=array[lb],
    start=lb,
    end=ub;

    while(start<end){
        while(array[start]<=pivot){
            start++;
        }
        while(array[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&array[start],&array[end]);
        }
    }
    swap(&array[lb],&array[end]);
    return end;
}


void display(int array[],int size){
    for(int i=0;i<size;i++){    
        cout<<array[i]<<" | ";  
    }
}


void swap(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
