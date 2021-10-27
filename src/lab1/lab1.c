#include <stdio.h>

float sumFormular(int n){
	float sum=0;
	for(float i=1;i<=n;i++){
		sum+=1/i;
	}
	return sum;
}


int main (int argc, char *argv[]){
	int n;
	float s=0;
	fflush(stdin);
	printf("insert a number: ");
	scanf("%d",&n);
	printf("n = %d",n);
	printf("\ntong biet thuc la : S = %.3f\n",sumFormular(n));
	return 0;
}