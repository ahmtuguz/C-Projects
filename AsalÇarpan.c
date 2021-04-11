#include<stdio.h>
int main(){
	int sayi,i,j,sayac=0,asal_carpan;
	printf("Sayi Giriniz: ");
	scanf("%d",&sayi);
	for(i=sayi;i>=2;i--){
		if(sayi%i==0){
			for(j=2;j<i;j++){
				sayac=0;
				if(i%j==0){
					sayac=1;
					break;
				}
			}
			if(sayac==0){
				printf("Asal Carpan: %d",i);
				break;
			}
		}
	}
	
	
	
	return 0;
	
}
