#include <stdio.h>

int main(){
	int Asal[1000]={};
	int x;
	int y;
	
	printf("Birinci tam sayiyi giriniz: ");
	scanf("%d",&x);
	
	printf("Ikinci tam sayiyi giriniz: ");
	scanf("%d",&y);
	
	if(x==1){
		x=x+1;
	}
	int index=0;
	int i;
	int j;
	for(i=x+1;i<y;i++){
		int sayac=0;
		for(j=2;j<i;j++){
			if (i%j==0){
				sayac=1;
				j=i-1;
			}
		}
		if (sayac==0){
			Asal[index]=i;
			index=index+1;	
		}
	}
	
	for(i=0;i<index;i++){
		printf("%d\n",Asal[i]);
	}
	if(index==0){
		printf("Asal sayi bulunamadi.");
	}
	
	return 0;
}
