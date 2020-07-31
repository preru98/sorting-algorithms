#include<iostream>
using namespace std;

void quick_sort_randomize(int, int, int[]);
int  partition(int, int, int[]);
void display(int [],int);
int* input_array(int);
void swap(int*,int*);

int main(){
    int size;
    cin>>size;
    int* numbers=input_array(size);
    quick_sort_randomize(0,size-1,numbers);
    display(numbers,size);
    return 0;
}

void quick_sort_randomize(int lb,int ub,int array[]){
    if(lb<ub){
        int random_index=lb + rand() % (ub - lb + 1);
        swap(&array[random_index],&array[lb]);
        int loc=partition(lb,ub,array);
        quick_sort_randomize(lb,loc-1,array);
        quick_sort_randomize(loc+1,ub,array);
    }
}

void display(int array[],int size){
    for(int i=0;i<size;i++){    
        cout<<array[i]<<" ";  
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

int* input_array(int size){
    int* array=new int[size];
    for(int x=0;x<size;x++){
        cin>>array[x];
    }
    return array;
}