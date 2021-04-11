#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int sayi,a,i,j,matris[100][100];
	float b;
	int diagonalToplam=0;
	
	printf("Sayi giriniz: ");
	scanf("%d",&sayi);
	while(1){
		a=sqrt(sayi);
		b=sqrt(sayi);
		if(a==b){
			break;
		}
		printf("Hatali sonuc girdiniz tekrar giriniz: ");
		scanf("%d",&sayi);
	}
	srand(time(NULL));
	printf("\n");
	for( i = 0 ; i < a ; i++ ) {
		for(j=0;j<a;j++){
			matris[i][j]=rand() % 100;
			printf("%d\t",matris[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for( i = 0 ; i < a ; i++ ) {
		int sutunToplam=0;
    	int satirToplam = 0;
		     
		for(j=0;j<a;j++){
			satirToplam =satirToplam + matris[i][j];
            sutunToplam+=matris[j][i];
		}
		diagonalToplam+=matris[i][i];
		printf("%d. Satirin Toplami\t: %d\n%d. SutununToplami\t: %d\n",(i+1),satirToplam,(i+1),sutunToplam);
	}
	printf("DiagonalToplam\t\t: %d",diagonalToplam);
	//printf("%d\n",satir_toplam);
	//printf("%d\n",sutun_toplam);
	//printf("%d",matris[0][0]);
	return 0;	
}
