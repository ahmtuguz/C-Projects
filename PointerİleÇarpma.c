#include<stdio.h>

int main(){
	int x,y,*p1,*p2;
	printf("1.Sayiyi Giriniz: ");
	scanf("%d",&x);
	printf("2.Sayiyi Giriniz: ");
	scanf("%d",&y);
	//scanf("%d %d",&x,&y);
	
	p1=&x;
	p2=&y;
	
	*p1=(*p1)*(*p2);
	
	printf("Carpim Sonucu: %d",*p1);
    
	return 0 ;

    }
