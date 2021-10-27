#include <stdio.h>

char *doiXung(int arr[], int length){
  for(int i=0;i<length;i++){
    if(arr[i]!=arr[length-1-i]){
      return "false"; 
    }
  }
  return "true";
}

int main (int argc, char *argv[]){
  int n;
  int arr[100];
  printf("nhap so phan tu mang: n = ");
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    printf("A[%d] = ",i);
    scanf("%d",&arr[i]);
  }
  printf("chuoi la doi xung? : %s\n",doiXung(arr,n));
}