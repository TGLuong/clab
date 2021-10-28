#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replaceChar(char *string, char c, char r){
  for(int i=0;i<strlen(string);i++){
    if(string[i]==c)string[i]=r;
  }
}


int main(int argc, int *argv[]){
  char string[256];
  printf("nhap chuoi : ");
  scanf("%s",string);
  while(1){
    int choose;
    system("clear");
    printf("chuoi hien tai: %s\n",string);
    printf("nhap 1 de thoat\n");
    printf("nhap 2 de thay the ky tu\n");
    scanf("\n%d",&choose);
    if(choose==1){
      break;
    }
    printf("nhap ky tu can thay the : ");
    char c;
    scanf("\n%c",&c);
    printf("nhap ky tu thay the : ");
    char r;
    scanf("\n%c",&r);
    replaceChar(string, c, r);
  }
}