#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *outfile,*infile;
	int a=20,b=10,c,d;
	float e=15.5,f;
	outfile=fopen("textdata.txt","w");
	fprintf(outfile,"%d %d %f",a,b,e);
	fclose(outfile);
	
	infile=fopen("textdata.txt","r");
	fscanf(infile,"%d %d %f",&c,&d,&f);
	
	printf("%d %d %f",a,b,e);
	printf("\n%d %d %f",c,d,f);
	
	
	
}
