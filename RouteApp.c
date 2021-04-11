#include <stdio.h>


int global;
int route();

int main(){
	int x,y;
	
	printf("Olusturmak istediginiz matrisin boyutlarini giriniz: \n");
	printf("Satir: ");
	scanf("%d",&x);
	printf("Sutun: ");
	scanf("%d",&y);
	
	global=y;
	int matris[x][y];
	int satir,sutun;
	
	printf("\nMatrisi Giriniz: \n");
	for(satir=0;satir<x;satir++){
		for(sutun=0;sutun<y;sutun++){
			printf("%d. satir %d. sutundaki sayiyi giriniz: ",satir+1,sutun+1);
			scanf("%d",&matris[satir][sutun]);
		}
	}
	
	printf("\nMatrisiniz:\n");
	for(satir=0;satir<x;satir++){
		for(sutun=0;sutun<y;sutun++){
			printf("%d ",matris[satir][sutun]);
			
		}
		printf("\n");
	}

	route(matris,x,y);

	return 0;
}


int route(int mat[][global],int x,int y){
	int satir=0,sutun=0;
	
	int yol[6];
	
	int m=0;
	int bayrak=mat[0][0];
	
	while(m!=6){
		if(sutun!=y && satir!=x){
			if(bayrak==mat[satir][sutun+1]){
			yol[m]=1;
			m+=1;
			sutun+=1;
			}
			else if(bayrak==mat[satir+1][sutun]){
				yol[m]=2;
				m+=1;
				satir+=1;
			}
		}			
	}
	
	printf("\nRoute: ");
	for(m=0;m<6;m++){
		if(m<5){
			printf("%d-",yol[m]);
		}else{
			printf("%d",yol[m]);
		}
		
	}
	
}
		
	

