#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int sorubas(FILE *s,int j,int p);//Fonksiyon prototipleri
void yarismaciekle(FILE *f);
void parabas(FILE *f,int j,int g);
void baslat();
void dogru();
void yanlis();
void paratablosu();
void kurallar();
void odul(int j);
int posta();

int sorubas(FILE *s, int j, int p){
	
	int r,h;
	char c;
	srand(time(NULL));//Soru sayısı random sayısı ile seçilir.
	r=rand()%36;
	h=6*r+1;
	
	char t[120],kcevap,bcevap,cevap;
	int i=0;
	while(fgets(t,120,s)!=NULL){//Burada her dönmede 's' dosyasından bir satırı 't' dizisine kopyaladık.
	i++;
		
	if((i>=h)&&(i<=h+5)){//Dosyadaki soru ve şıkların aralığı
		
		if(i==h)//Eğer soru 't' dizisine kopyalandıysa 
			sleep(1.5);//1.5 saniye bekle
		
		if(i==h+1)//Eğer A şıkkı 't' dizisine kopyalandıysa 
			sleep(1);
		
		if(i==h+2)//Eğer B şıkkı 't' dizisine kopyalandıysa 
			sleep(1);
		
		if(i==h+3)//Eğer C şıkkı 't' dizisine kopyalandıysa 
			sleep(1);
		
		if(i==h+4)//Eğer D şıkkı 't' dizisine kopyalandıysa 
			sleep(1);
			
		if(i==h+5){//Eğer cevap 't' dizisine kopyalandıysa 
			cevap=t[0];//'t' dizisinin ilk elemanını 'cevap' değişkenine ata.
			if(cevap<=90&&cevap>=65){
				bcevap=cevap;
				kcevap=bcevap+32;}
		
			if(cevap<=122&&cevap>=97){
				kcevap=cevap;
				bcevap=kcevap-32;}}

	
	if((i>=h)&&(i<h+5))//Eğer bu aralıktaysa(soru ve şıkların bulunduğu aralıktaysa)
		printf("   %.500s", t);//Ekrana bas.
	}}
	
	sleep(1);
	printf("\n   Cevabınız nedir?\n   ");
	scanf("   %c",&c);//Cevap alınır.
	printf("   Cevabınız alınmıştır\n\n");
	sleep(5);		
	
	if(c=='5'&&p==0){
		
		if(kcevap=='a'){
			printf("\n   C ve D şıkları yanlıştır.\n");
			}
		if(kcevap=='b'){
			printf("\n   A ve D şıkları yanlıştır.\n");
			}
		if(kcevap=='c'){
			printf("\n   A ve B şıkları yanlıştır.\n");
			}
		if(kcevap=='d'){
			printf("\n   C ve B şıkları yanlıştır.\n");
			}
		sleep(1);
		printf("\n   Cevabınız nedir?\n   ");
		scanf("   %c",&c);//Cevap alınır.
		printf("   Cevabınız alınmıştır\n\n");
		sleep(5);
		p=1;					
		}
	
	if(c==kcevap||c==bcevap){//Yarismacinin girdiği cevap, cevabın küçük veya büyük harfiyse 
		dogru();}
		
	else{
		yanlis();
		sleep(1);
		printf("\n   Cevap : %c\n",bcevap);
		return 1;
		}
	
	return 0;
}	
	
	

struct kaydet{
	char no[11], isim[50], soyisim[50], *odul, posta[50];
}yarismaci;




void yarismaciekle(FILE *f){
	
	printf("\n   Yarışmaya başlamak için lütfen aşağıdaki bilgileri doldurunuz\n\n");
	sleep(1);
	
    printf("   İsim : ");
    //scanf("%50s",yarismaci.isim);
    gets(yarismaci.isim); 
        
    printf("   Soyisim : ");
    scanf("%50s",yarismaci.soyisim);
        
    printf("   T.C Kimlik No : ");
    scanf("%11s",yarismaci.no);
    
    posta();
    
    }
    

void odul(int j){
	j-=1;
	if(j==0){	
		yarismaci.odul="0 TL";}
	if(j==1){
		yarismaci.odul="500 TL";}
	if(j==2){
		yarismaci.odul="1000 TL";}
	if(j==3){
		yarismaci.odul="2000 TL";}
	if(j==4){
		yarismaci.odul="3000 TL";}
	if(j==5){
		yarismaci.odul="5000 TL";}
	if(j==6){
		yarismaci.odul="7.500 TL";}
	if(j==7){
		yarismaci.odul="10.000 TL";}
	if(j==8){
		yarismaci.odul="15.000 TL";}
	if(j==9){
		yarismaci.odul="30.000 TL";}
	if(j==10){
		yarismaci.odul="60.000 TL";}
	if(j==11){
		yarismaci.odul="125.000 TL";}
	if(j==12){
		yarismaci.odul="250.000 TL";}
	if(j==13){
		yarismaci.odul="1.000.000 TL";}
 
}
        
        
        
void parabas(FILE *f,int j,int g){//Yarışmacının çözdüğü soru sayısına göre kazandığı para miktarları ekrana basılır.

	if(g==1){//G nin 1 olması yarışmacının soruyu yanlış yaptığını gösterir.
		sleep(1);
		
		j-=1;//'j' değişkenini 1 azalt.(azaltılmayadabilirdi, 1 azaltılarak yarışmacının kaç soru bildiği ölçülür.)
		
		if(j==0){//Eğer yarışmacı hiç soru bilmediyse 
			printf("\n   ÖDÜLÜNÜZ : 0 TL\n");}//Ekrana bas.
		if(j==1){
			printf("\n   ÖDÜLÜNÜZ : 500 TL\n");}
		if(j==2){
			printf("\n   ÖDÜLÜNÜZ : 1000 TL\n");}
		if(j==3){
			printf("\n   ÖDÜLÜNÜZ : 2000 TL\n");}
		if(j==4){
			printf("\n   ÖDÜLÜNÜZ : 3000 TL\n");}
		if(j==5){
			printf("\n   ÖDÜLÜNÜZ : 5000 TL\n");;}
		if(j==6){
			printf("\n   ÖDÜLÜNÜZ : 7.500 TL\n");}
		if(j==7){
			printf("\n   ÖDÜLÜNÜZ : 10.000 TL\n");}
		if(j==8){
			printf("\n   ÖDÜLÜNÜZ : 15.000 TL\n");}
		if(j==9){
			printf("\n   ÖDÜLÜNÜZ : 30.000 TL\n");}
		if(j==10){
			printf("\n   ÖDÜLÜNÜZ : 60.000 TL\n");}
		if(j==11){
			printf("\n   ÖDÜLÜNÜZ : 125.000 TL\n");}
		if(j==12){
			printf("\n   ÖDÜLÜNÜZ : 250.000 TL\n");}
		if(j==13){
			printf("\n   ÖDÜLÜNÜZ : 1.000.000 TL\n");}
		}
	else{	
		sleep(1);
		if(j==1){
			printf("   500 TL KAZANDINIZ\n");}
		if(j==2){
			printf("   1000 TL KAZANDINIZ\n");}
		if(j==3){
			printf("   2000 TL KAZANDINIZ\n");}
		if(j==4){
			printf("   3000 TL KAZANDINIZ\n");}
		if(j==5){
			printf("   5000 TL KAZANDINIZ\n");}
		if(j==6){
			printf("   7.500 TL KAZANDINIZ\n");}
		if(j==7){
			printf("   10.000 TL KAZANDINIZ\n");}
		if(j==8){
			printf("   15.000 TL KAZANDINIZ\n");}
		if(j==9){
			printf("   30.000 TL KAZANDINIZ\n");}
		if(j==10){
			printf("   60.000 TL KAZANDINIZ\n");}
		if(j==11){
			printf("   125.000 TL KAZANDINIZ\n");}
		if(j==12){
			printf("   250.000 TL KAZANDINIZ\n");}
		if(j==13){
			printf("   1.000.000 TL KAZANDINIZ\n");}
}}
        
void baslat(){
	printf("\n   BAŞLA\n\n\n");
}

void dogru(){
	printf("\n   CEVABINIZ DOĞRU\n");
	printf("   TEBRİKLER!!\n\n");
}

void yanlis(){
	 printf("\n   CEVABINIZ YANLIŞ!!!\n");
	 sleep(1.5);
	 printf("   ELENDİNİZ\n");
}
	
void paratablosu(){
	sleep(1.5);
	printf("\n    _ _ _ _ _ _ _\n   |PARA TABLOSU |\n   |_ _ _ _ _ _ _|\n");
	printf("   |500 TL       |\n   |1000 TL      |\n   |2000 TL      |\n   |3000 TL      |\n   |5000 TL      |\n   |7.500 TL     |\n   |10.000 TL    |\n");
	printf("   |15.000 TL    |\n   |30.000 TL    |\n   |60.000 TL    |\n   |125.000 TL   |\n   |250.000 TL   |\n   |1.000.000 TL |\n   |_ _ _ _ _ _ _|");
}
	    
void kurallar(){
	sleep(2);
	printf("\n\n\n   #OYUN KURALLARI#\n");
	sleep(1);
	printf("   =>Joker hakkınız bulunmamaktadır\n");
	sleep(1);
	printf("   =>Baraj yoktur\n");
	sleep(1);
	printf("   =>Her soruda kazandığınız para, toplam para ödülü olacaktır\n");
	sleep(1);
	printf("   =>A, B, C ve D şıkları dışında bir işaretleme yaparsanız elenirsiniz\n");
}

int posta(){
	
	int k,b=0;
	
	printf("   E-posta : ");
    scanf("%s", yarismaci.posta);
    k=strlen( yarismaci.posta );
    
     for(int i=0;i<k-7;i++){
		 if(yarismaci.posta[i]=='@')
	           b++;
		}
    
    while(yarismaci.posta[k-1]!='m'&&yarismaci.posta[k-2]!='o'&&yarismaci.posta[k-3]!='c'&&yarismaci.posta[k-4]!='.'&&b==0){
    
			printf("\nGeçersiz e-posta adresi girdiniz\nLütfen tekrar e-posta adresi giriniz\n\n");
			printf("   E-posta : ");
			scanf("%s", yarismaci.posta);
			k=strlen( yarismaci.posta );	
		}
	
	return 0;
	}


int main()
{    
	int j=1,g,t=0;//g1;
	
	setlocale(LC_ALL,"Turkish");
	
	printf("\n   KİM MİLYONER OLMAK İSTER\n\n");
	sleep(1);
	
	//printf("   Yarışmaya kaydolmak için 1'i\n   Yarışmaya kayıtlıysanız, yarışmaya başlamak için 2'yi\n   ");
	//scanf("%d",&g1);
   
    FILE *f = fopen("yarismaci.txt", "a+");//Yarışmacı kaydetme dosyası açıldı.
   
   // sleep(2);
   	//system("cls");
   
   	//if(g1==1)
		yarismaciekle(f);//Yarışmacı bilgilerini girer.
	
	paratablosu();
	kurallar();
    //sleep(3);
    printf("   ");
    system("pause");
    system("cls");//cmd ekranını temizler.
    sleep(1);
	baslat();
	sleep(1.5);
	
	for(;j<14;j++){//Yarışmada yarışan kişiye sorulacak soru sayısını belirleyen döngü(Bu döngü soru sayısı kadar döner.)
		sleep(1);
		
		if(j>1){//İlk soru daha hızlı basılır. Onun dışındakiler biraz daha yavaş basılır.
		sleep(2.5);
		printf("\n");}
		
		printf("   SORU %d\n\n",j);//Yarışmacının kaçıncı soruda olduğunu ekrana basar.
		sleep(1);

	FILE *s=fopen("sorular.txt","r");//Soru dosyası açılır.

	g=sorubas(s,j,t);//return 1 olarak dönerse yarışmacı soruyu yanlış işaretlemiştir.
	parabas(f,j,g);//Yarışmacının toplam ne kadar kazandığını her soruda basan fonksiyon
	if(g!=1){
		sleep(2);
		printf("\n   =>");
		sleep(1);
		system("cls");}//Cmd ekranını temizler.
	odul(j);
	if(g==1){//Eğer cevap yanlışsa bi sonraki soruyu basmaması için ve döngüden çıkması için döngü parametresine soru sayısından daha büyük sayı atandı.
		if(j<13)
			fprintf(f,"%s\t%s\t%s\t%s\t%s\n---------------------------------------------------------------\n", yarismaci.no, yarismaci.isim, yarismaci.soyisim, yarismaci.posta, yarismaci.odul);
			
			fclose(f);//Yarışmacı kaydetme dosyası kapandı.
			j=100;}// 'g' değişkeni sorunun doğru olup olmadığını kontrol etmek için kullanıldı.
	
	else{
		if(j==13){//Yarışmacı son soruyu da doğru yaptıysa 
			printf("\n   Tebrikler!!!\n   Milyoner Oldunuz");
			fprintf(f,"%s\t%s\t%s\t%s\t%s\n---------------------------------------------------------------\n", yarismaci.no, yarismaci.isim, yarismaci.soyisim, yarismaci.posta, yarismaci.odul);}
		}
	fclose(s);//Soru dosyası kapatılır.
	}	
	
	sleep(1);
	printf("\n\n\n   TEŞEKKÜR EDERİZ");
	sleep(2.5);
	return 0;
}

