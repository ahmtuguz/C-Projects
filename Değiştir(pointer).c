#include <stdio.h>

void degistir(int *a,int*b){
	int gecici=*a;
	*a=*b;
	*b=gecici;
}

int main(){
	int x=5,y=10;
	degistir(&x,&y);
	printf("x: %d y: %d",x,y);
	return 0;
}
