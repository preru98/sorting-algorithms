#include<iostream>
using namespace std;

// prototypes
void display(int [],int);
void simpleSort(int[],int);
void swap(int*,int*);

//main()
int main(){
    int numbers[]={7,5,3,2,1};     //worst case
    int numbers2[]={1,2,3,5,7};    //best case

    int size=sizeof(numbers)/sizeof(numbers[0]);
    display(numbers,size);
    simpleSort(numbers,size);

    return 0;
}

//functions
void simpleSort(int array[],int size){
    int outer_for_loop_counter=0, inner_for_loop_counter=0;
    for(int i=0;i<size;i++){
        
        outer_for_loop_counter++;
        for(int j=0;j<size;j++){
            
            inner_for_loop_counter++;
            if(array[i]<array[j]){
                
                swap(&array[i], &array[j]);
            
            }
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
        
        /*
          for-each loop cannot be used here since array[]
          in the definition of function will be converted 
          as int* array and for-each loop can't work with pointers.
                                                                 */
    }
}


void swap(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
