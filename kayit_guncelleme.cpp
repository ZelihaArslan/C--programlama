#include<stdio.h>,

struct musteri{
	int no;
	char ad[40];
	double bakiye;
};
typedef struct musteri musteri;

void listele (FILE *p)
{
	int i=0;
	musteri bilgi;
	rewind(p); //once basa gelsin ondan sonra okumaya baslas�n pointer� basa cekiuyoruz
	while(!feof(p)) //feof g�stermiyorsa okuma yapar
	{
		fread(&bilgi,sizeof(musteri),1,p);
		i++;
		if(bilgi.no!=0)
		{
			printf("%d-%d\t%s\t%.2f/n",i, &bilgi.no,bilgi.ad,&bilgi.bakiye);//kayd� yazd�r�r 
		}
		
	}
	
}

void yeniKayit(FILE *p)
{
	int kayitNo;
	musteri bilgi;
	
	printf("hangi kayda ekleme yap�lacak");
	scanf("%d",&kayitNo);
	fseek(p,(kayitNo-1)*sizeof(musteri),SEEK_SET);
	fread(&bilgi,sizeof(musteri),1,p);
	if(bilgi.no!=0)
	  printf("buraya daha once veri girilmis");
	else{
			printf("Musteri no,Ad,Bakiye gir:");
			scanf("%d %s %lf", &bilgi.no,bilgi.ad,&bilgi.bakiye);
			fseek(p,(kayitNo-1)*sizeof(musteri),SEEK_SET); //
				//fseek(p,-1*sizeof(musteri),SEEK_CUR); 
			fwrite(&bilgi,sizeof(musteri),1,p); 
	
	}
}

void kayitGuncelle()
{
	int kayitNo;
	musteri bilgi;
	
	printf("hangi kayda ekleme yap�lacak");
	scanf("%d",&kayitNo);
	fseek(p,(kayitNo-1)*sizeof(musteri),SEEK_SET);
	fread(&bilgi,sizeof(musteri),1,p);
	if(bilgi.no==0)
	  printf("buraya daha once veri girilmemis. guncelleme yap�lamaz");
	else{
			printf("Musteri no,Ad,Bakiye gir:");
			scanf("%d %s %lf", &bilgi.no,bilgi.ad,&bilgi.bakiye);
			fseek(p,(kayitNo-1)*sizeof(musteri),SEEK_SET);  //silme i�ini burdan itibaren yapabliirz 
				//fseek(p,-1*sizeof(musteri),SEEK_CUR); 
		if (fwrite(&bilgi,sizeof(musteri),1,p))
			 printf("kayit eklendi");
	   else
	        printf("kayit eklenmedi");
	
	}
}




int main(void)
{
	int secim;
	FILE *ptr=fopen("musteri.txt","r+");   //musteri txt de listele fonk ile i�indekileri okudu rewind ile basa d�nd� tekrar okuma yapabilmek i�in 
	if(ptr==NULL)
	  printf("dosya hatasi");
	else{
		
	while(1) //sonsuz d�ng� i�inde menu olusturma
	{
		printf("1-Hesap ekle\n"
		       "2-hesap guncelle\n"
			   "3-hesap sil\n"
			   "4-listele\n"
			   "secim:");
		scanf("%d",&secim);

      if(secim==1)
      yeniKayit(ptr); 
      
      if(secim==2)
       kayitGuncelle(ptr);
	       
      if(secim==4)
      listele(ptr);
      
     

	}
}
}
