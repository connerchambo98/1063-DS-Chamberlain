#include <iostream>
using namespace std;
void reverseArray(int Nums[],int size){
  int i,j,t;
  for(i=0,j=size-1;i<(size/2);i++,j--){
    t = Nums[i];
    Nums[i]=Nums[j];
    Nums[j]=t;
  }
}
int main() {
  int  i =0, j=0, k=0;
int Nums[15][15];
int size = 225;
int *Nums = new int[size];

for(i=0;i<15;i++){
   for(j=0;j<15;j++){
      Nums[i][j]=k;
      k++;
   }
}
reverseArray(A,size);
for(i=0;i<15;i++){
   for(j=0;j<15;j++){
      Nums[i][j]=k;
      k++;
   }
}
}
