#include<iostream>
using namespace std;

// prototypes
void display(int [],int);
void mergeSort(int[],int,int);
void swap(int*,int*);
void merge(int[],int,int,int);

//main()
int main(){
    int numbers[]={7,5,3,2,1};     //worst case
    int numbers2[]={1,2,3,5,7};    //best case

    int size=sizeof(numbers)/sizeof(numbers[0]);
    display(numbers,size);
    mergeSort(numbers,0,size-1);
    cout<<"After sorting \n";
    display(numbers,size);

    return 0;
}

//functions
void mergeSort(int array[],int lb,int ub){

    if(lb<ub){
        int mid=(lb+ub)/2;

        mergeSort(array,lb,mid);
        mergeSort(array,mid+1,ub);

        merge(array,lb,mid,ub);
    }
}


void merge(int array[],int lb,int mid,int ub){
    int size=ub-lb+1;
    int *newArray=new int [size];
    int i=lb,
    j=mid+1,
    k=lb;

    while(i<=mid && j<=ub){
        
        if(array[i]<=array[j]){
            newArray[k]=array[i];
            i++;
        }
        else{
            newArray[k]=array[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            newArray[k]=array[j];
            j++;
            k++;
        }
    }
    if(j>ub){
        while(i<=mid){
            newArray[k]=array[i];
            i++;
            k++;
        }
    }
    for(int i=lb;i<=ub;i++){            //Transferring contents after merging to original array
        array[i]=newArray[i];
    }
}


void display(int array[],int size){
    for(int i=0;i<size;i++){    
        cout<<array[i]<<" | ";  
    }
}
