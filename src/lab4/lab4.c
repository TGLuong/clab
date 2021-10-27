#include <string.h>
#include <stdio.h>

void inPhanTuAm(int *arr, int length){
  printf("[");
  if(length>=1&&arr[0]<0)printf("%d",arr[0]);
  for(int i=1;i<length;i++){
    if(arr[i]<0){
      printf(",%d",arr[i]);
    }
  }
  printf("]\n");
}


int main(int argc, char *argv[]){
  int n;
  int arr[100];
  printf("nhap so phan tu mang: n = ");
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    printf("A[%d] = ",i);
    scanf("%d",&arr[i]);
  }
  inPhanTuAm(arr, n);
  return 0;
}