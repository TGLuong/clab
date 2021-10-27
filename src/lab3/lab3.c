#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void reverseArr(char arr[],int length){
  for(int i=0;i<length/2;i++){
    arr[i]=arr[i]+arr[length-1-i];
    arr[length-1-i]=arr[i]-arr[length-1-i];
    arr[i]=arr[i]-arr[length-1-i];
  }
}


int main(int argc, char *argv[]){
  int n;
  char *s;
  printf("insert n: ");
  scanf("%d",&n);
  sprintf(s,"%d",n);
  reverseArr(s,strlen(s));
  n = atoi(s);
  printf("\ndao nguoc cua n : %d\n",n);
  return 0;
}