#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct node{
	int *sayi;
	int sayac=0;
}sayilar; // typedeften pointer �retti�im zaman tire kullan�r�m
 int main()
 {
 	sayilar node;
 	node.sayi=(int*)malloc(sizeof(int)); // say�lar kadar sayilar pointer tipinde yer ay�r�r.
 	printf("sayi giriniz:");
 	scanf("%d",&node.sayi);
 	while(node.sayi>=0){
 	 node.sayac++;
 		realloc(node.sayi,(node.sayac+1)*sizeof(int));// bellek b�y�kl���n� de�i�tirmek istersek ,geriye deger d�nmez
 		printf("sayi giriniz:");
 	     scanf("%d",&node.sayi[node.sayac]);
	 }
	 getch();
	 return 0;
 }
 
