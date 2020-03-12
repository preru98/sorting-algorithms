#include<iostream>
using namespace std;

// prototypes
void display(int [],int);
void countSort(int[],int);
int findMax(int[],int);


//main()
int main(){
    int numbers[]={10,16,3,9,2,15,9,21}; 
    int size=sizeof(numbers)/sizeof(numbers[0]);
    // display(numbers,size); 
    countSort(numbers,size);
    display(numbers,size);
    return 0;
}

//functions
void countSort(int array[],int size){

    int max=findMax(array,size);
    int *temp=new int[max+1];
    for(int x=0;x<max+1;x++){  //Initialising temp array with 0
        temp[x]=0;
    }
    for(int i=0;i<size;i++){   //Saving the occurence of array elements in temp array
        temp[array[i]]++;
    }
    for(int i=0,j=0;i<max+1;i++){  //copying back the elements in sorted order in array from temp array 
        if(temp[i]>0){
            while(temp[i]){
                array[j]=i;
                j++;
                temp[i]--;
            }
        }
    }
    
}


void display(int array[],int size){
    for(int i=0;i<size;i++){    
        cout<<array[i]<<" | ";  
    }
}


int findMax(int array[], int size){
    int max=INT32_MIN;        //Macro for smallest int value
    for(int x=0;x<size;x++){
        if(max<array[x]){
            max=array[x];
        }
    }
    return max;
}
 
