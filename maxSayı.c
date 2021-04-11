#include<stdio.h>
int max_sayi(int *a,int size){
	int max=a[0],i;
	for(i=1;i<size;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}
int main(){
	int dizi[]={1,8,24,6,24};
	int max=max_sayi(dizi,5);
	printf("%d",max);
	return 0;
}
