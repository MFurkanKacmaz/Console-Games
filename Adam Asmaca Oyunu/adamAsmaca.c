#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL,"Turkish");
	
	int uz=0,s,f=0;//Kelimenin uzunluğunu tutacak ve random sayıyı tutacak değişken tanımlandı.
	srand(time(NULL));//10 dan küçük sayı rastgele seçilir.
	s=rand()%10;
	
	char *k[]={"harita","kabak","sandalye","kolay","matematik","kapasite","basamak","ezik","banka","destek"},*ptr=k[s];//Kelimeler tanımlandı.*/
	char a;//Random sayının seçtiği kelimeyi tutacak pointer atandı.
	
	for(;k[s][uz]!='\0';uz++){}//Kelimenin uzunluğunu bulan döngü.
    
    printf("Adam Asmaca Oyunu baslamistir.\nSorulan kelimenin harf sayisi kadar tahmin hakkiniz vardir.\nListenin %d. kelimesi soruldu.\nKelime %d harflidir.\n",s+1,uz);//Yarışma hakkında açıklama yapıldı.
	
	char bos[uz-1];//Kelimenin harf sayısı kadar boşluk karakteri ekrana bastıracak dizi tanımlandı.
	
	for(int n=0;n<=uz;n++){//Random sayının seçtiği kelimenin harf sayısı kadar boşluk karakteri ekrana bastırır.
		bos[n]='_';}
    bos[uz+1]='\0';
    
	for(int i=0;i<=uz;i++){//Kullanıcıya kelimenin harf sayısı kadar tahmin etme hakkı tanıyan döngü.	
		
		printf("Lutfen harf giriniz:\n");
	   
	    for(int x=0;x<uz;x++){//Boşluk dizisinin son durumunu her tahminden sonra ekrana bastıran döngü.
		    printf("%c ",bos[x]);}
       
        scanf("\n\n%c",&a);//Kullanıcı harf girer.
		
		for(int j=0;j<uz;j++){//Girilen harfin sorulan kelimede olup olmadığına bakan döngü.
		
		    if(a==ptr[j]){//Eğer girilen harf kelimedeki herhangi bir harfse 
				bos[j]=a;//Boşluk dizisinde boşluk yerine girilen harf atandı ve her tahminden sonra ekrana bastırılan boşluk dizisi harfle birlikte bastırılır.Kullanıcı doğru harf tahmininde bulunduğunu bilir. 
				f++;
				}
			}
		
		if(f==uz){
			printf("\nTebrikler.KAZANDINIZ!!!");
			break;
			}
		}
		
	if(f!=uz){
		printf("\nKAYBETTTİNİZ.");
		}
	
	
	printf("\n---------------------\nKelime:%s\n---------------------",k[s]);//En sonda kelimenin tamamı ekrana bastırılır.


	
	return 0;
}
