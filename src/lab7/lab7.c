#include <stdio.h>
#include <string.h>

int soLanXuatHien(char *string, char c){
  int count=0;
  for(int i=0;i<strlen(string);i++){
    if(string[i]==c)count++;
  }
  return count;
}


int main(int argc, char *argv[]){
  char string[256];
  char c;
  printf("nhap chuoi : ");
  scanf("%s",string);
  fflush(stdin);
  printf("nhap ky tu can tim : ");
  scanf("\n%c",&c);
  printf("so lan xuat hien cua %c trong chuoi la : %d\n",c,soLanXuatHien(string, c));
}