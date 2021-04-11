#include<stdio.h>
#include<string.h>
int main(){
	char string1[100],string2[100];
	int len1,len2;
	printf("String ifade giriniz: ");
	gets(string1);
	printf("String ifade giriniz: ");
	gets(string2);
	
	len1=strlen(string1);
	len2=strlen(string2);
	if(len1>len2){
		printf("Ilk string ifade daha buyuk");
	}
	else if(len2>len1){
		printf("Ikinci string ifade daha buyuk");
	}else{
		printf("Uzunluklari esit");
	}
	
	return 0;
	
}
