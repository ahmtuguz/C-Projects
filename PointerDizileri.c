#include <stdio.h>

char *gunismi(char *gundizisi[],int uzunluk, int hangigun){
	if (hangigun>=1 && hangigun<=7){
		return gundizisi[hangigun-1];
	}
	else{
		return NULL;
	}
}

int main(){
	char *gunler[]={"pazartesi","salý","çarþamba","perþembe","cuma","cumartesi","pazar"};
	char *p=gunismi(gunler,7,1);
	
	if (p==NULL){
		printf("NULL");
	}
	else{
		printf("%s",p);
	}
	return 0;
}
