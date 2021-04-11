#include <stdio.h>
#include <string.h>

char *dondur(char *p,int index){
	
	int uzunluk=strlen(p);
	
	if(index>=uzunluk){
		return NULL;
	}else{
		return p+index;
	}
}

int main(){
	char yazi[]="yazilim";
	
	char *p=dondur(yazi,4);	
	
	printf("%s",p);
	
	return 0;
}
