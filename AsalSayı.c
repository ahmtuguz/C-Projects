#include <stdio.h>

int asalSayi(sayi);

int main(){
	int say;
	printf("Sayi Giriniz: ");
	scanf("%d",&say);
	int x=asalSayi(say);
	printf("%s",x);
	return 0;
}

int asalSayi(int sayi){
	int sayac=0,i;
	for(i=2;i<sayi;i++){
		if(sayi%i==0){
			sayac=1;
			break;
		}
	}
	if(sayac==0){
		return "asal";
	}else{
		return "asal degil";
	}
}
