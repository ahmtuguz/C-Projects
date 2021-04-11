#include <stdio.h>
#include <string.h>

int benimStrlen(char *p){
	int uzunluk=0;
	int i=0;
	
	for(;p[i]!='\0';i++){
		uzunluk+=1;
	}
	
	return uzunluk;
}

int main(){
	char yazi[]="turaaaa";
	printf("%d",benimStrlen(yazi));
	//printf("%d",strlen(yazi));
	return 0;
}
