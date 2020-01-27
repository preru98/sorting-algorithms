#include<iostream>
using namespace std;

// prototypes
void display(int [],int);
void bubbleSort(int[],int);
void swap(int*,int*);

//main()
int main(){
    int numbers[]={7,5,3,2,1};     //worst case
    int numbers2[]={1,2,3,5,7};    //best case

    int size=sizeof(numbers)/sizeof(numbers[0]);
    display(numbers,size);
    bubbleSort(numbers,size);

    return 0;
}

//functions
void bubbleSort(int array[],int size){

    int outer_for_loop_counter=0, inner_for_loop_counter=0, no_more_passes_required=1;

    for(int i=0;i<size-1;i++){
        
        outer_for_loop_counter++;
        for(int j=0;j<size-1-i;j++){
            
            
            if(array[j]>array[j+1]){

                inner_for_loop_counter++;
                swap(&array[j], &array[j+1]);
                no_more_passes_required=0;
            }
        }
        if(no_more_passes_required){
            break;
        }
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
