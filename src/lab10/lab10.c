#include <stdio.h>

int tongMang(int arr[], int length){
  int sum=0;
  for(int i=0;i<length;i++){
    sum+=arr[i];
  }
  return sum;
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
  FILE *f;
  f = fopen("./data.data","w");
  fprintf(f,"%d",tongMang(arr,n));
  fclose(f);
}