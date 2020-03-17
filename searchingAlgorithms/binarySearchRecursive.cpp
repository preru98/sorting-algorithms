#include<iostream>
#include<cmath>
using namespace std;
int bSearch(int lb,int ub,int key,int array[]);

int main(){
    int array[]={3,4,5,7,9,11,34,57,96,190,200,301,509,1000};
    int size=sizeof(array)/sizeof(array[0]);

    int res=bSearch(0,size-1,190,array);
    if(res!=-1){
        cout<<"Found at index: "<<res<<" | position :"<<res+1;
    }
    else{
        cout<<"Not Found :( ";
    }
    return 0;
}

int bSearch(int lb,int ub,int key,int array[]){

    if(lb<=ub){
        int mid=(lb+ub)/2; 
        if(array[mid]==key){
            return mid;
        }
        else if(key<array[mid]){
            return bSearch(lb,mid-1,key,array);
        }
        else{
            return bSearch(mid+1,ub,key,array);
        }
    }
    return -1;
}