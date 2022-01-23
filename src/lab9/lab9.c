#include <stdio.h>
#include <stdlib.h>

typedef struct SinhVienStruct
{
  char stt[10];
  char name[256];
  char class[256];
  int score;
} SinhVien;

void drawData(SinhVien *sinhvien, int length){
  printf("%-10s%-20s%-20s%-10s\n","stt","name","class","score");
  for(int i=0;i<length;i++){
    printf("%-10s%-20s%-20s%-10d\n",sinhvien[i].stt,sinhvien[i].name,sinhvien[i].class,sinhvien[i].score);
  }
  printf("=======================================\n");
}

void add (SinhVien *sinhVien, SinhVien node, int *length){
  sinhVien[*length]=node;
  (*length)++;
  printf("length : %d\n", *length);
  return;
};
void alter(SinhVien *sinhVien, SinhVien node, int position){
  sinhVien[position]=node;
}
void delete(SinhVien *sinhVien, int position, int *length){
  for(int i=position;i<*length-1;i++){
    sinhVien[i]=sinhVien[i+1];
    sprintf(sinhVien[i].stt,"%d",i);
  }
  (*length)--;
}

int main(int argc, char *argv[]){
  SinhVien sinhVien[100];
  SinhVien newNode;
  int svLength=0;
  int position;
  while (1)
  {
    int option;
    system("clear");
    drawData(sinhVien,svLength);
    printf("1 : them\n");
    printf("2 : sua\n");
    printf("3 : xoa\n");
    printf("4 : thoat\n");
    printf("nhap lua chon : ");
    scanf("%d",&option);
    if(option==4)break;
    switch (option)
    {
    case 1:
      printf("nhap ten : ");
      scanf("%s",newNode.name);
      printf("nhap lop : ");
      scanf("%s",newNode.class);
      printf("nhap diem : ");
      scanf("\n%d",&newNode.score);
      sprintf(newNode.stt,"%d",svLength);
      add(sinhVien,newNode,&svLength);
      break;
    case 2:
      printf("nhap id can sua: ");
      scanf("%d",&position);
      if(position>svLength)break;
      printf("nhap ten : ");
      scanf("%s",newNode.name);
      printf("nhap lop : ");
      scanf("%s",newNode.class);
      printf("nhap diem : ");
      scanf("\n%d",&newNode.score);
      sprintf(newNode.stt,"%d",position);
      alter(sinhVien, newNode, position);
      break;
    case 3:
      printf("nhap id sinh vien can xoa : ");
      scanf("%d",&position);
      if(position>svLength)break;
      delete(sinhVien,position,&svLength);
      break;
    default:
      break;
    }
  }
  
  return 0;
}
