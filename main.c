#include <stdio.h>
#include <stdlib.h>

int main(void)

{   // T�m Tanimlamalarimiz Basta.
    float Calisan_Net_Ucret[45] , Gelir_Kesintisi[45] , Aylik_Brut[45] , Aylik_Brut_Toplam[45] , Calisan_Es_Odenek = 0 ,
          Cocuk_Odenek = 0 , Toplam_Net_Ucret = 0, Toplam_Aktarilan_Vergi = 0 , Toplam_Brut = 0 , Enbuyuk_Brut = 0 , Enbuyuk_Net = 0 ,Toplam_Cocuk = 0 ;
    // Sayac tanimlari, para t�r� tanimlari vb. (Sayac = Is�i sayisi)
    unsigned int i , Sayac = 0 , Cocuk_Sayisi_Sayac , Calismayan_Es_Sayac = 0 , Calisan_Evli_Sayac = 0 , Calisan_Engelli_Sayac = 0 , Calisan_Engel_Oran ,
                 Calisan_EngelliDerece[45] , Banknot_Ucret , Sayac_2000 = 0,
                 Vergi0_Sayac = 0 , Vergi15_Sayac = 0 , Vergi20_Sayac = 0 , Vergi27_Sayac = 0 , Vergi35_Sayac = 0 , Enb_Brut = 0 , Enb_Net = 0,
                  CocukSahibiCalisan_Sayac = 0 , UcCokCocukSahibiCalisan_Sayac = 0 , Cocuk_Sayisi[Cocuk_Sayisi_Sayac],
                 Banknot_200 , Banknot_100 , Banknot_50 , Banknot_20 , Banknot_10 , Banknot_5,
                 Madeni_1 , Madeni_05 , Madeni_025 , Madeni_010 , Madeni_005 , Madeni_001,
                 Banknot_200_Sayac = 0 ,  Banknot_100_Sayac = 0 , Banknot_50_Sayac = 0 , Banknot_20_Sayac = 0 , Banknot_10_Sayac = 0 , Banknot_5_Sayac = 0,
                 Madeni_1_Sayac = 0 , Madeni_05_Sayac = 0 , Madeni_025_Sayac = 0 , Madeni_005_Sayac=0 , Madeni_001_Sayac = 0;
    // T.C. sayisi 11 hane oldugu i�in long long int almak gerekiyor. Boyutunu da 45 yapmak zorunda kaldik nedeni raporda mevcut.
    unsigned long long int TC_Numara[45] ;
    // Isim i�in �ift matris kullandik.
    char Calisan_AdSoyad[45][45] , Baska_Calisan , Calisan_Evli , Calisan_Es , Calisan_Engelli;

    do {
        printf("***************************    EMPLOYEE INFORMATION    ***************************\n\n");
        // T.C. girisi. %11llu'daki 11 sayesinde 11den fazla rakam girildiginde yoksayiyor.
        printf("* Enter the Employee ID Number [11 Digits] \n->"); scanf("%11llu", &TC_Numara[Sayac]); fflush(stdin);
        // Isim Girisi. %[^\n]s'daki [^\n] sayesinde girilen bosluklar da diziye atanabiliyor.
        printf("* Enter Employee's Name and Surname \n->"); scanf("%[^\n]s", Calisan_AdSoyad[Sayac]); fflush(stdin);
        // Aylik Br�t giris.
        printf("* Employee's Monthly Gross Fees [TL] (Minimum Wage: 1777.50 TL)\n->"); scanf(" %f", &Aylik_Brut[Sayac]);
        Aylik_Brut_Toplam[Sayac] = Aylik_Brut[Sayac]; // Eklenecek �denekler i�in farkli bir br�t hesabi dizi kullandik.
        // �alisanin evli sorgulamasi.
        printf("* Whether the Employee is Married [If Married = M / e <-> If Not = H / h] \n->"); scanf (" %c", &Calisan_Evli);
            if (Calisan_Evli == 'e' || Calisan_Evli == 'E'){
                Calisan_Evli_Sayac++;

                printf("* Whether Employee's Wife Working Or Not [Working = E / e <-> Not Working If = H / h] \n->"); scanf(" %c", &Calisan_Es);

                if (Calisan_Es != 'e' && Calisan_Es != 'E'){   // Burada �alisanlarin �alismayan eslerinin sayisini bulduk.
                    Calismayan_Es_Sayac++;
                    Calisan_Es_Odenek = 220;  // 220 TL �alismayan es i�in �denek
                    Aylik_Brut_Toplam[Sayac] += Calisan_Es_Odenek;  // Br�te eklenmesi.
                    }
            }
        // �alisan �ocuk sorgusu. �ocugu yoksa 0 girilecek.
        printf("* Number of Children who Employer Needs to Care [Enter 0 If Not] \ n->"); scanf(" %u", &Cocuk_Sayisi_Sayac);

        Toplam_Cocuk += Cocuk_Sayisi_Sayac; // �alisanlarin �ocuklari toplami.

            if (Cocuk_Sayisi_Sayac > 0 ){
                if ( Cocuk_Sayisi_Sayac > 3) UcCokCocukSahibiCalisan_Sayac++; // ��ten fazla �ocuga sahip �alisanlari bulma.
                CocukSahibiCalisan_Sayac++; // �ocugu olan �alisan sayaci.
                for (i = 0 ; i < Cocuk_Sayisi_Sayac ; i++){  // �ocuklarin yasini girebilmek i�in d�ng�.
                        printf("%u. Child's Age : ", i+1); scanf(" %u", &Cocuk_Sayisi[i]); // �ocuklarin yas girisi.
                            if  (Cocuk_Sayisi[i] <= 6)  // Yaslarina g�re �denek birikimi.
                                {Cocuk_Odenek += 25;}
                            else{Cocuk_Odenek += 45;}
                    }
                Aylik_Brut_Toplam[Sayac] += Cocuk_Odenek; // �ocuk �deneginin br�te eklenmesi.
            }  // Br�t / Toplam Br�t / Net �cret -> Sonu�ta 3 Farkli para isteniyor.
        Calisan_Net_Ucret[Sayac] = Aylik_Brut_Toplam[Sayac]; // Br�t� �zerinde islem yapilacak Net �crete esitleme.
        // Engelli Sorgusu.
        printf("* Whether Employee Has Disability [If Disabled = E / e <-> If No = H / h]\n->"); scanf(" %c", &Calisan_Engelli);
            if (Calisan_Engelli == 'e' || Calisan_Engelli == 'E'){
                Calisan_Engelli_Sayac++; // Engelli �alisan saya�.

                printf("Employee Disability Rate [%%] \n-> "); scanf(" %u", &Calisan_Engel_Oran); // Engelli Orani Girisi.

                if (Calisan_Net_Ucret[Sayac] > 1777.50){
                    if (Calisan_Engel_Oran > 100 && Calisan_Engel_Oran < 0){
                        printf("\n\n*********   Wrong Odds Entered.   *********\n\n");
                        continue; // Yanlis Giris Uyarisi.
                    }
                    else if (Calisan_Engel_Oran <= 100 && Calisan_Engel_Oran >= 80){
                        Calisan_EngelliDerece[Sayac] = 1;  // Her �alisan i�in ayri engelli derecesi atamasi.
                        Calisan_Net_Ucret[Sayac] -= 900;  // Engelli oranina g�re br�tten �ikartilmasi gereken miktarin �ikartilmasi.
                    }
                    else if (Calisan_Engel_Oran < 80 && Calisan_Engel_Oran >= 60){
                        Calisan_EngelliDerece[Sayac] = 2;
                        Calisan_Net_Ucret[Sayac] -= 470;
                    }
                    else if (Calisan_Engel_Oran < 60 && Calisan_Engel_Oran >= 40){
                        Calisan_EngelliDerece[Sayac] = 3;
                        Calisan_Net_Ucret[Sayac] -= 210;
                    }
                    else if (Calisan_Engel_Oran < 40){
                        printf("/aDisability Rate Does Not Enter The Tax Bracket."); // Engellilik oraninin yetersiz oldugu uyarisi.
                    }
                }
            } // Net �cretin girdigi vergi diliminin tespiti.
              if (Calisan_Net_Ucret[Sayac] >=0 && Calisan_Net_Ucret[Sayac] < 1777.50 ){
            Gelir_Kesintisi[Sayac]=0; // Asgari �cret alti Vergi dilimine girmiyor.
            Sayac_2000++; // 2000 TL altinda maas alan �alisanlari sayma.
            Vergi0_Sayac++;}  // Vergi t�r�ne g�re ka� �alisanin girdigini sayma.

            else if (Calisan_Net_Ucret[Sayac] >= 1777 && Calisan_Net_Ucret[Sayac] < 2000){
            Gelir_Kesintisi[Sayac] = (Calisan_Net_Ucret[Sayac] / 100) * 15; // Gelir kesintisini hesaplama.
            Vergi15_Sayac++;
            Sayac_2000++;
            Calisan_Net_Ucret[Sayac] -= Gelir_Kesintisi[Sayac];}  // Gelir kesintisini br�tten �ikarip net �cretti hesaplama.

            else if (Calisan_Net_Ucret[Sayac] >= 2000 && Calisan_Net_Ucret[Sayac] < 5000){
            Gelir_Kesintisi[Sayac] = (Calisan_Net_Ucret[Sayac] / 100) * 20;
            Vergi20_Sayac++;
            Calisan_Net_Ucret[Sayac] = Calisan_Net_Ucret[Sayac] - Gelir_Kesintisi[Sayac];}

            else if (Calisan_Net_Ucret[Sayac] >= 5000 && Calisan_Net_Ucret[Sayac] < 10000){
            Gelir_Kesintisi[Sayac] = (Calisan_Net_Ucret[Sayac] / 100) * 27;
            Vergi27_Sayac++;
            Calisan_Net_Ucret[Sayac] -= Gelir_Kesintisi[Sayac];}

            else if (Calisan_Net_Ucret[Sayac] >= 10000){
            Gelir_Kesintisi[Sayac] = (Calisan_Net_Ucret[Sayac] / 100) * 35;
            Vergi35_Sayac++;
            Calisan_Net_Ucret[Sayac] -= Gelir_Kesintisi[Sayac];
            }



        // Baska is�i girisi sorgulamadan �nce bilgileri girilen �alisanin bazi bilgilerini kullaniciya sunma.
        printf("******************  INFORMATION ABOUT ENTRED EMPLOYEE  ******************\n\n");
        printf("~~ Employee ID Number And Name Surname: %llu  |  %s \n\n", TC_Numara[Sayac], Calisan_AdSoyad[Sayac]);
        printf("~~ Monthly Brut Fee [TL] : %.2f TL \n\n", Aylik_Brut[Sayac]);
        printf("~~ Fee Assistance for Spouse : %.2f TL \n\n", Calisan_Es_Odenek);
        printf("~~ Fee Assistance For Children : %.2f TL \n\n", Cocuk_Odenek);
        printf("~~ Employee's Total Monthly Gross Fees : %.2f TL \n\n", Aylik_Brut_Toplam[Sayac]);
        printf("~~ Income Tax Deduction : %.2f TL \n\n", Gelir_Kesintisi[Sayac]);
        if (Calisan_Engelli == 'e' || Calisan_Engelli == 'E') // Engelli ise engel bilgileri.
        printf("~~Disability Degree of Employee : %u. Degree Disabled \n\n", Calisan_EngelliDerece[Sayac]);
        printf("~~ Employee's Monthly Net Wage : %.2f TL \n\n", Calisan_Net_Ucret[Sayac]);

        Banknot_Ucret = Calisan_Net_Ucret[Sayac] * 100;// �cret tam sayi olmayan bir sayi olabilir. Bu y�zden risk almayip bu sayiyi 100 ile �arparak
                                                        // tam sayiya �evirdik.
        //Net �cretin en az sayida banknot veya madeni para hesaplamasi.
        printf("~~ Payment of the Employee's Net Wages with Minimum Number of Banknotes and Coins \n");

    Banknot_200 = Banknot_Ucret / 20000; //Ka� adet 200 TL gerektigini bulma.
    if (Banknot_200 > 0){ // 200 TL banknot kullanilacaksa devam et.
            printf("\t\t--> %u Times 200 TL Banknote <--\n", Banknot_200); // Kullanilan Banknot sayisini yazdirma.
            Banknot_200_Sayac+=Banknot_200;} // T�m �alisanlar i�in kullanilan 200TL'lik banknotlari hesaplama.
    Banknot_Ucret = Banknot_Ucret % 20000; // �cretin 200TL'lik banknotlar ile �denen kismini �ikarma.
        Banknot_100 = Banknot_Ucret / 10000; if (Banknot_100 > 0) {printf("\t\t--> %u Times 100 TL Banknote <--\n", Banknot_100); Banknot_100_Sayac+=Banknot_100;}
    Banknot_Ucret = Banknot_Ucret % 10000;
        Banknot_50  = Banknot_Ucret / 5000; if (Banknot_50 > 0) {printf("\t\t--> %u Times 50 TL Banknote <--\n", Banknot_50); Banknot_50_Sayac+=Banknot_50;}
    Banknot_Ucret = Banknot_Ucret % 5000;
        Banknot_20  = Banknot_Ucret / 2000; if (Banknot_20 > 0) {printf("\t\t--> %u Times 20 TL Banknote <--\n", Banknot_20); Banknot_20_Sayac+=Banknot_20;}
    Banknot_Ucret = Banknot_Ucret % 2000;
        Banknot_10  = Banknot_Ucret / 1000; if (Banknot_10 > 0) {printf("\t\t--> %u Times 10 TL Banknote <--\n", Banknot_10); Banknot_10_Sayac+=Banknot_10;}
    Banknot_Ucret = Banknot_Ucret % 1000;
        Banknot_5   = Banknot_Ucret / 500; if (Banknot_5 > 0) {printf("\t\t--> %u Times 5 TL Banknote <--\n", Banknot_5); Banknot_5_Sayac+=Banknot_5;}
    Banknot_Ucret = Banknot_Ucret % 500;
        Madeni_1    = Banknot_Ucret / 100; if (Madeni_1 > 0) {printf("\t\t--> %u Times 1 TL Coin <--\n", Madeni_1); Madeni_1_Sayac+=Madeni_1;}
    Banknot_Ucret = Banknot_Ucret % 100;
        Madeni_05   = Banknot_Ucret / 50; if (Madeni_05 > 0) {printf("\t\t--> %u Times 50 Coin <--\n", Madeni_05); Madeni_05_Sayac+=Madeni_05;}
    Banknot_Ucret = Banknot_Ucret % 50;
        Madeni_025  = Banknot_Ucret / 25; if (Madeni_025 > 0) {printf("\t\t--> %u Times 25 Coin <--\n", Madeni_025); Madeni_025_Sayac+=Madeni_025;}
    Banknot_Ucret = Banknot_Ucret % 25;
        Madeni_005  = Banknot_Ucret / 5; if (Madeni_005 > 0) {printf("\t\t--> %u Times 5 Coin <--\n", Madeni_005); Madeni_005_Sayac+=Madeni_005;}
    Banknot_Ucret = Banknot_Ucret % 5;
        Madeni_001  = Banknot_Ucret / 1; if (Madeni_001 > 0) {printf("\t\t--> %u Times 1 Coin <--\n", Madeni_001); Madeni_001_Sayac+=Madeni_001;}

        Sayac++;
        printf("\n\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf ("Enter Another Employee? [Evet=E/e <-> Hayir=H/h]:\n->");    scanf (" %c", &Baska_Calisan); // Baska �alisan sorgusu.
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

        }
    while (Baska_Calisan == 'e' || Baska_Calisan == 'E'); // Do-while d�ng�s�. e veya E'den baska giriste d�ng� sonlanir.

        for ( i = 0 ; i < Sayac ; i++ ){ // D�ng� bittiginden dolayi �alisanlari �agirmak i�in a�ilan for d�ng�s�.
            Toplam_Net_Ucret += Calisan_Net_Ucret[i]; // T�m �alisanlara verilen toplam Net �cret hesaplamasi.
            Toplam_Aktarilan_Vergi += Gelir_Kesintisi[i]; // Devlete aktarilan toplam vergi hesaplamasi.
            Toplam_Brut += Aylik_Brut_Toplam[i]; //T�m �alisanlarin toplam Br�t miktarinin hesaplamasi.
        }

            // T�m �alisanlarin verileri kullanilarak istenen istatiksel verilerin yazdirilmasi.
            printf("******************  INFORMATION ABOUT ALL EMPLOYEES  ******************\n\n");
            printf("~~ Total Monthly Net Wages Paid To All Employees In One Month : %.2f TL\n\n", Toplam_Net_Ucret);
            printf("~~ Monthly Total Income Tax Transferred to the State : %.2f TL\n\n", Toplam_Aktarilan_Vergi);
            printf("~~ Average Monthly Total Gross Wages of All Employees : %.2f TL\n\n" , Toplam_Brut / Sayac);
            printf("~~ Average Monthly Total Net Wages of All Employees: %.2f TL\n\n", Toplam_Net_Ucret / Sayac);
            printf("~~ Spending to Pay Total Net Wages of All Employees\n   Money Type and Number\n");
            printf("\t\t--> %u Times 200 TL Banknote <--\n", Banknot_200_Sayac);
            printf("\t\t--> %u Times 100 TL Banknote <--\n", Banknot_100_Sayac);
            printf("\t\t--> %u Times 50 TL Banknote <--\n", Banknot_50_Sayac);
            printf("\t\t--> %u Times 20 TL Banknote <--\n", Banknot_20_Sayac);
            printf("\t\t--> %u Times 10 TL Banknote <--\n", Banknot_10_Sayac);
            printf("\t\t--> %u Times 5 TL Banknote <--\n", Banknot_5_Sayac);
            printf("\t\t--> %u Times 1 TL Coin <--\n", Madeni_1_Sayac);
            printf("\t\t--> %u Times 50 Coin <--\n", Madeni_05_Sayac);
            printf("\t\t--> %u Times 25 Coin <--\n", Madeni_025_Sayac);
            printf("\t\t--> %u Times 5 Coin <--\n", Madeni_005_Sayac);
            printf("\t\t--> %u Times 1 Coin <--\n\n", Madeni_001_Sayac);
            printf("~~ 2000 TL < Number of Employees Under Net Monthly Wages : %u\n\n", Sayac_2000);
            // printf i�lerinde Y�zde hesabi yapildi.
            printf("~~ Number and Percentage of Employees Not Including the Tax Bracket: %u People %% %u \n\n", Vergi0_Sayac, (Vergi0_Sayac * 100) / Sayac);
            printf("~~ %%15 Number and Percentage of Employees Entering the Tax Bracket : %u People %% %u \n\n", Vergi15_Sayac, (Vergi15_Sayac * 100) / Sayac);
            printf("~~ %%20 Number and Percentage of Employees Entering the Tax Bracket : %u People %% %u \n\n", Vergi20_Sayac, (Vergi20_Sayac * 100) / Sayac);
            printf("~~ %%27 Number and Percentage of Employees Entering the Tax Bracket : %u People %% %u \n\n", Vergi27_Sayac, (Vergi27_Sayac * 100) / Sayac);
            printf("~~ %%35 Number and Percentage of Employees Entering the Tax Bracket : %u People %% %u \n\n\n\n", Vergi35_Sayac, (Vergi35_Sayac * 100) / Sayac);
            Enbuyuk_Brut = Aylik_Brut_Toplam[0]; // �alisanlar arasinda en fazla Br�t �creti alan �alisani bulmak i�in a�ilan for d�ng�s�.
            for ( i = 0 ; i < Sayac ; i++ ){
                if ( Aylik_Brut_Toplam[i] > Enbuyuk_Brut){
                    Enbuyuk_Brut = Aylik_Brut_Toplam[i];
                    Enb_Brut = i;}} // Bu �alisana ait baska veriler de istenildigi i�in is�inin �zel sayac numarasini elde etme.
            printf("~~ Employee with the Highest Monthly Brut Wage :\n\n\t=> Identification number: %llu \n", TC_Numara[Enb_Brut]);
            printf("\t=> Name and Surname: %s \n", Calisan_AdSoyad[Enb_Brut]); // En fazla Br�t �creti alan �alisanin istenen verilerini yazdirma.
            printf("\t=> Total Brut Fees: %.2f TL \n", Aylik_Brut_Toplam[Enb_Brut]);
            printf("\t=> Income Tax Deduction: %.2f TL\n", Gelir_Kesintisi[Enb_Brut]);
            printf("\t=> Net Monthly Fee: %.2f TL \n\n\n\n", Calisan_Net_Ucret[Enb_Brut]);
            Enbuyuk_Net = Calisan_Net_Ucret[0]; // �alisanlar arasinda en fazla Net �creti alan �alisani bulmak i�in a�ilan for d�ng�s�.
            for ( i = 0 ; i < Sayac ; i++ ){
                    if ( Calisan_Net_Ucret[i] > Enbuyuk_Net){
                Enbuyuk_Net = Calisan_Net_Ucret[i];
                Enb_Net = i;}} // Bu �alisana ait baska veriler de istenildigi i�in is�inin �zel sayac numarasini elde etme.
            printf("~~ Employee with the Highest Monthly Net Wage :\n\n\t=> Identification number: %llu \n", TC_Numara[Enb_Net]);
            printf("\t=> Name and Surname: %s \n", Calisan_AdSoyad[Enb_Net]); // En fazla Net �creti alan �alisanin istenen verilerini yazdirma.
            printf("\t=>  Total Brut Fees: %.2f TL \n", Aylik_Brut_Toplam[Enb_Net]);
            printf("\t=> Income Tax Deduction: %.2f TL\n", Gelir_Kesintisi[Enb_Net]);
            printf("\t=> Monthly Net Fee: %.2f TL \n\n\n", Calisan_Net_Ucret[Enb_Net]);
            printf("~~ Percentage of Married Among Employees = %% %d \n\n", (Calisan_Evli_Sayac * 100) / Sayac); // Yine bir y�zde hesabi
            // Evli �alisanlari bulmak i�in t�m is�ilerden evli olanlar �ikartilip y�zde hesabi yapildi.
            printf("~~ Percentage of Single Employees = %% %d \n\n", ((Sayac - Calisan_Evli_Sayac)  * 100) / Sayac);
            // Esi �alisan �alisanlari bulmak i�in evli �alisanlardan evli olup esi �alismayan �alisanlar �ikartilip y�zde hesabi yapildi.
            printf("~~ Percentage of Married Employees Among Married Employees = %% %d \n\n", ((Calisan_Evli_Sayac - Calismayan_Es_Sayac) * 100) / Sayac );
            //y�zde hesabi
            printf("~~ Number and Percentage of Disabled Employees = %d Kisi %% %d\n\n", Calisan_Engelli_Sayac, (Calisan_Engelli_Sayac * 100) / Sayac);
            // Ortalama hesabi
            if ( Toplam_Cocuk > 0){
            printf("~~ Average Number of Children Employe needs to Care = %.1f \n\n", Toplam_Cocuk / CocukSahibiCalisan_Sayac);}
            printf("~~ Number of Employees that Has More than 3 Children = %d \n\n", UcCokCocukSahibiCalisan_Sayac);


            printf("<><><><><><><><><><><><><><><>   PROGRAM SONU   <><><><><><><><><><><><><><><>");

}







