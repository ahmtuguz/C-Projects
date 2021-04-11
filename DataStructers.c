#include <stdio.h>
#include<stdlib.h>

typedef enum{
	bay,bayan
}cinsiyet;
typedef struct{
		int yas;
		char *isim;
		cinsiyet c;
	}insan;

int emeklimi(insan *birey){
	if((birey->yas)>55 && (birey->c)==bay)
		return 1;
	if((birey->yas)>50 && (birey->c)==bayan)
		return 1;	
	return 0;	
}
int main(){
	insan ali;
	insan *veli;
	veli=(insan*)malloc(sizeof(insan));
	veli->yas=60;
	veli->c=bay;
	ali.yas=30;
	ali.c=bayan;
	printf("%d",ali.yas);
	printf("\n%u\n",ali.c);
	printf("%d",veli->yas);
	printf("\n%d\n",emeklimi(&ali));
	printf("%d",emeklimi(veli));
	
	
return 0;
}
