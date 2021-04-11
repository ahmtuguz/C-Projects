#include <stdio.h>

int main(){
	
	int n;
	int i;
	int j;
	printf("Kac sayi gireceksiniz: ");
	scanf("%d",&n);
	int A[n];
	for (i=0;i<n;i++){
		printf("Sayi giriniz: ");
		scanf("%d",&A[i]);
	}
	int min=A[0];
	for (i=0;i<n;i++){
		if (min>A[i]){
			min=A[i];
		}
	}
	int max=0;
	for (i=0;i<n;i++){
		if (max<A[i]){
			max=A[i];
		}
	}
	
	int ebob=1;
	for (i=2;i<min+1;i++){
		int sayac=0;
		for (j=0;j<n;j++){
			if (A[j]%i==0){
				sayac=sayac+1;
			}	
		}
		if (sayac==n){
			ebob=i;
		}
	}
	long carpim=1;
	for(i=0;i<n;i++){
		carpim=A[i]*carpim;
	}
	
	int ekok=1;
	for (i=max;i<carpim+1;i++){
		int sayac=0;
		for (j=0;j<n;j++){
			if (i%A[j]==0){
				sayac=sayac+1;
			}	
		}
		if (i>=max){
			if (sayac==n){
				ekok=i;
				i=carpim;
			}
		}
	}
	printf("Ebob: %d",ebob);
	printf("\nEkok: %d",ekok);
	
	return 0;
}

