#include <stdio.h>

int main(){
	int index=0;
	int sayi;
	int n;
	printf("Kac sayi gireceksiniz: ");
	scanf("%d",&n);
	int liste[n];
	int liste_x[100]={};
	int liste_y[100]={};
	
	int i;
	for (i=0;i<n;i++){
		printf("Sayi giriniz: ");
		scanf("%d",&sayi);
		if (sayi<=0){
			int m=0;
			while(m<1){
				printf("Tekrar sayi giriniz: ");
				scanf("%d",&sayi);
				if(sayi>0){
					m=1;
				}
			}
		}
		liste[i]=sayi;
	}
	printf("\nBaginti => ");
	int sayac=0;
	int j;
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((2-liste[j])%liste[i]==0){
				printf("(%d,%d)",liste[i],liste[j]);
				liste_x[index]=liste[i];
				liste_y[index]=liste[j];
				index=index+1;
				if (liste[i]==liste[j]){
					sayac=sayac+1;
				}
				
			}
		}
	}
	int bayrak=0,toplam=0;
	if(n==1){
		bayrak=bayrak+1;
	}
	for(i=0;i<index-1;i++){
		for(j=i+1;j<index;j++){
			if(liste_x[i]==liste_y[j] && liste_y[i]==liste_x[j]){
				bayrak=bayrak+1;
			}
		}
	}
	toplam=sayac+bayrak;
	for(i=0;i<n;i++){
		if(i==0){
			printf("\nListe = {");
		}
		if(i!=n-1){
		printf("%d,",liste[i]);
		}
		if(i==n-1){
			printf("%d}\n",liste[i]);
		}
	}
	for(i=0;i<index;i++){
		if(i==0){
			printf("Liste_X = {");
		}
		if(i!=index-1){
		printf("%d,",liste_x[i]);
		}
		if(i==index-1){
			printf("%d}\n",liste_x[i]);
		}
	}
	for(i=0;i<index;i++){
		if(i==0){
			printf("Liste_Y = {");
		}
		if(i!=index-1){
		printf("%d,",liste_y[i]);
		}
		if(i==index-1){
			printf("%d}\n",liste_y[i]);
		}
	}
	if (sayac>=n && bayrak>=n){
		printf("Sonuc: Bu baginti hem yansima ve hem simetri ozelligini saglamaktadir. ");
	}else if(sayac>=n){
		printf("Sonuc: Bu baginti yalnizca yansima ozelligini saglamaktadir. ");
	}else if(toplam>=n){
		printf("Sonuc: Bu baginti yalnizca simetri ozelligini saglamaktadir. ");
	}else{
		printf("Sonuc: Bu baginti yansima ve simetri ozelligini saglamamaktadir. ");
	}
	
	return 0;
}
