#include<stdio.h>
#include<stdlib.h>
int main(){
	int *dizi;
	int eleman_sayisi;
	int i;
	printf("eleman sayisi giriniz:");
	scanf("%d",&eleman_sayisi );
	dizi=(int*)malloc(eleman_sayisi*sizeof(int));
	for(i=0;i<eleman_sayisi;i++)
	printf("adres:%d\t deger:%d\n",&dizi[i],dizi[i]);
	
	free(dizi);
	return 0;
}
