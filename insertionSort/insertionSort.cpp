#include<iostream>
using namespace std;

// prototypes
void display(int [],int);
void insertionSort(int[],int);
void swap(int*,int*);

//main()
int main(){
    int numbers[]={7,5,3,2,1};     //worst case
    int numbers2[]={1,2,3,5,7};    //best case

    int size=sizeof(numbers)/sizeof(numbers[0]);
    display(numbers,size);
    insertionSort(numbers,size);

    return 0;
}

//functions
void insertionSort(int array[],int size){

    int outer_for_loop_counter=0, inner_for_loop_counter=0, temp,j;
    for(int i=1;i<size;i++){
        
        outer_for_loop_counter++;
        temp=array[i];
        for(j=i-1;j>=0 && array[j]>temp;j--){
            
            inner_for_loop_counter++;
            array[j+1]=array[j];
        }
        array[j+1]=temp;
    }

    cout<<"outer_for_loop_counter :"<<outer_for_loop_counter<<"\n";
    cout<<"inner_for_loop_counter :"<<inner_for_loop_counter<<"\n";

    cout<<"After sorting \n";
    display(array,size);
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
