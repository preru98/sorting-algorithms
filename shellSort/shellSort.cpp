#include<iostream>
using namespace std;

// prototypes
void display(int [],int);
void shellSort(int[],int);
void swap(int*,int*);

//main()
int main(){
    cout<<"Hello\n";
    int numbers[]={7,5,3,2,1};     //worst case
    int numbers2[]={1,2,3,5,7};    //best case
    int size=sizeof(numbers)/sizeof(numbers[0]);
    cout<<"Before sorting \n";
    display(numbers,size);
    shellSort(numbers,size);
    return 0;
}

//functions
void shellSort(int array[],int size){

    int interval, i, j;
    for(interval=size/2; interval>0; interval=interval/2){
        for(j=interval; j<size; j++){
            for(i=j-interval;i>=0;i=i-interval){
                if(array[i+interval]>array[i]){
                    break;
                }
                else{
                    swap(&array[i+interval],&array[i]);
                }
            }
        }
    }
    
    cout<<"After sorting \n";
    display(array,size);
}


void display(int array[],int size){
    cout<<"Displaying :";
    cout<<endl;
    for(int i=0;i<size;i++){    
        cout<<array[i]<<" | ";  
    }
}


void swap(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

