#include<stdio.h>
#include<string.h>
char kelime[50];
char kalin[8]={'A','I','O','U','a','�','o','u'};
char ince[8]={'E','�','�','�','e','i','�','�'};

int karsilastir(char, char);
int main()
{
	int i,c,kalinharf,inceharf;
	printf("lutfen kelime giriniz:");
	gets(kelime);
	kalinharf=karsilastir(i,kalinharf);
	inceharf=karsilastir(i,inceharf);
	if(inceharf==0 && kalinharf==0)
	printf("buyuk unlu uyumuna uymuyor.");
	else
	printf("buyuk unlu uyumuna uyuyor.");
}
int karsilastir(char a, char b){
	for(int i=0; i<= 7 ; i++){
		for(int c=0; c<=7; c++){
			if(a[i]==b[c])
			return 0;
		}
	}
}

