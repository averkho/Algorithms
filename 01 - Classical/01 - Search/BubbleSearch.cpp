#include <iostream>

using namespace std;

// function to generate and retrun random numbers.
int * getRandom( ) {

   static int  r[10];

   // set the seed
   srand( (unsigned)time( NULL ) );
   
   for (int i = 0; i < 10; ++i) {
      r[i] = rand()%100;
      cout << r[i] << endl;
   }

   return r;
}

void swap(int *x, int *y){

    int temp=*x;
    *x=*y;
    *y=temp;
}

void PrintArray(int arr[],int n){

    

    for (int i=0; i<n-1; i++){
        cout << arr[i] << '\t';
    }
    cout << '\n';

}

void BubbleSort(int arr[], int n){

    bool swapped;

    for (int i=0; i<n-1; i++){

        swapped=false;

        for (int j=0; j<(n-i-1); j++){

            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=true;
            }
        }
        if (swapped==false){
            break;
        }
    }



}

int main () {

   // a pointer to an int.
   int *p;

   p = getRandom();
   int n=sizeof (p);

   cout << "Unsorted Array" << endl;
   PrintArray(p,n);

   BubbleSort(p,n);

   cout <<"Sorted Array" << endl;
   PrintArray(p,n);
   return 0;
}