#include <stdio.h>

void printCandidateReport ();

void inMang(int *arr, int length){
  printf("[");
  if(length>=1)printf("%d",arr[0]);
  for(int i=1;i<length;i++){
      printf(",%d",arr[i]);
  }
  printf("]\n");
}

int trongMang(int arr[], int length, int num){
  for(int i=0;i<length;i++){
    if(arr[i]==num) return i;
  }
  return -1;
}

void xuatHienNhieuNhat(int arr[], int length){
  int buffer[length];
  int size[length];
  int result[length];
  int buffLength=0;
  for(int i=0;i<length;i++){
    int check = trongMang(buffer,buffLength,arr[i]);
    if(check==-1){
      buffer[buffLength]=arr[i];
      size[buffLength]=1;
      buffLength++;
    }else{
      size[check]++;
    }
  }
  int max=0;
  for(int i=0;i<buffLength;i++){
    if(size[i]>max)max=size[i];
  }
  int resultLength=0;
  for(int i=0;i<buffLength;i++){
    if(size[i]==max){
      result[resultLength]=buffer[i];
      resultLength++;
    }
  }
  inMang(result, resultLength);
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
  printf("phan tu xuat hien nhieu nhat : ");
  xuatHienNhieuNhat(arr,n);
}
