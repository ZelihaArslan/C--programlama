#include<stdio.h>
void kisayol(int,int);
int matris[10][6]={ {1,0,0,0,0,0},
                    {1,1,0,0,0,0},
				    {1,1,1,1,1,1},
				    {1,1,1,0,0,1},
				    {1,0,1,1,1,1},
				    {1,0,0,0,1,1},
				    {1,1,1,0,1,1},
				    {0,0,1,1,1,1},
				    {0,0,1,0,1,1},
				    {1,0,1,1,1,1}};
int yol[10][6]={0}; //gitti�i yola birdaha gitmesini engellemek i�in yoksa fonk sonsuz d�ng�ye girer

int main()
{
	int j=0,k=0;//matrisi ekrana yazd�ral�m
	while(j<10)
	{
		while(k<6)
		{
			printf(	"%d\t", matris[j][k]);
			k++;
			
		}
		k=0; //d�ng�ye tekrar girsin yeni sat�r�n s�t�nlar�n� yazabilmek i�in
		printf("\n");
		j++;
	}

	kisayol(0,0); //(0,0) yolunun parametrelerini ald�k ilk yol
	
	return 0;
}

void kisayol(int x,int y)
{   
  yol[x][y]=1; //gitti�i her yere 1 ata  
  //giri�imiz ,ba�lang�� belli olsun
  	matris[0][0]=1; //1. sat�r 1. s�tun her zaman 1 e e�it olsun
	printf("koordinatlar: %d ,%d\n",x,y);//koordinatlar� ekrana bast�r
	if(x==9 && y==5)   return;
	else{
		
	    if(x<10 && matris[x+1][y]==1 && yol[x+1][y]==0 )
    	    kisayol(x+1,y);
    	else if(y<6 && matris[x][y+1]==1 && yol[x][y+1]==0) 
		   //y k���k 6 ise s�n�r� a�mam��sa ve y bir sonraki s�tuna git
		   // yolu 1 ise ve gitti�i yola bir daha gitmemesi i�in yol dizisini ekledi
		   //bir sonraki eger 0 ise fonk buraya girmesin  
           //y<6 sa�a gidip gidemeyece�ini kontrol eder,
           //matris eger yol1 ise gitsin ��nk� 0 lar duvar
           //yol =0 ise oraya hi� gidilmemi� rahatl�kla gidebiliriz demek
		    kisayol(x,y+1); 
	}
}
