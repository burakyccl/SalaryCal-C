#include <stdio.h>
#include <stdlib.h>

int main(void)

{   // Tüm Tanimlamalarimiz Basta.
    float Calisan_Net_Ucret[45] , Gelir_Kesintisi[45] , Aylik_Brut[45] , Aylik_Brut_Toplam[45] , Calisan_Es_Odenek = 0 ,
          Cocuk_Odenek = 0 , Toplam_Net_Ucret = 0, Toplam_Aktarilan_Vergi = 0 , Toplam_Brut = 0 , Enbuyuk_Brut = 0 , Enbuyuk_Net = 0 ,Toplam_Cocuk = 0 ;
    // Sayac tanimlari, para türü tanimlari vb. (Sayac = Isçi sayisi)
    unsigned int i , Sayac = 0 , Cocuk_Sayisi_Sayac , Calismayan_Es_Sayac = 0 , Calisan_Evli_Sayac = 0 , Calisan_Engelli_Sayac = 0 , Calisan_Engel_Oran ,
                 Calisan_EngelliDerece[45] , Banknot_Ucret , Sayac_2000 = 0,
                 Vergi0_Sayac = 0 , Vergi15_Sayac = 0 , Vergi20_Sayac = 0 , Vergi27_Sayac = 0 , Vergi35_Sayac = 0 , Enb_Brut = 0 , Enb_Net = 0,
                  CocukSahibiCalisan_Sayac = 0 , UcCokCocukSahibiCalisan_Sayac = 0 , Cocuk_Sayisi[Cocuk_Sayisi_Sayac],
                 Banknot_200 , Banknot_100 , Banknot_50 , Banknot_20 , Banknot_10 , Banknot_5,
                 Madeni_1 , Madeni_05 , Madeni_025 , Madeni_010 , Madeni_005 , Madeni_001,
                 Banknot_200_Sayac = 0 ,  Banknot_100_Sayac = 0 , Banknot_50_Sayac = 0 , Banknot_20_Sayac = 0 , Banknot_10_Sayac = 0 , Banknot_5_Sayac = 0,
                 Madeni_1_Sayac = 0 , Madeni_05_Sayac = 0 , Madeni_025_Sayac = 0 , Madeni_005_Sayac=0 , Madeni_001_Sayac = 0;
    // T.C. sayisi 11 hane oldugu için long long int almak gerekiyor. Boyutunu da 45 yapmak zorunda kaldik nedeni raporda mevcut.
    unsigned long long int TC_Numara[45] ;
    // Isim için çift matris kullandik.
    char Calisan_AdSoyad[45][45] , Baska_Calisan , Calisan_Evli , Calisan_Es , Calisan_Engelli;

    do {
        printf("***************************    EMPLOYEE INFORMATION    ***************************\n\n");
        // T.C. girisi. %11llu'daki 11 sayesinde 11den fazla rakam girildiginde yoksayiyor.
        printf("* Enter the Employee ID Number [11 Digits] \n->"); scanf("%11llu", &TC_Numara[Sayac]); fflush(stdin);
        // Isim Girisi. %[^\n]s'daki [^\n] sayesinde girilen bosluklar da diziye atanabiliyor.
        printf("* Enter Employee's Name and Surname \n->"); scanf("%[^\n]s", Calisan_AdSoyad[Sayac]); fflush(stdin);
        // Aylik Brüt giris.
        printf("* Employee's Monthly Gross Fees [TL] (Minimum Wage: 1777.50 TL)\n->"); scanf(" %f", &Aylik_Brut[Sayac]);
        Aylik_Brut_Toplam[Sayac] = Aylik_Brut[Sayac]; // Eklenecek ödenekler için farkli bir brüt hesabi dizi kullandik.
        // Çalisanin evli sorgulamasi.
        printf("* Whether the Employee is Married [If Married = M / e <-> If Not = H / h] \n->"); scanf (" %c", &Calisan_Evli);
            if (Calisan_Evli == 'e' || Calisan_Evli == 'E'){
                Calisan_Evli_Sayac++;

                printf("* Whether Employee's Wife Working Or Not [Working = E / e <-> Not Working If = H / h] \n->"); scanf(" %c", &Calisan_Es);

                if (Calisan_Es != 'e' && Calisan_Es != 'E'){   // Burada çalisanlarin çalismayan eslerinin sayisini bulduk.
                    Calismayan_Es_Sayac++;
                    Calisan_Es_Odenek = 220;  // 220 TL Çalismayan es için ödenek
                    Aylik_Brut_Toplam[Sayac] += Calisan_Es_Odenek;  // Brüte eklenmesi.
                    }
            }
        // Çalisan çocuk sorgusu. Çocugu yoksa 0 girilecek.
        printf("* Number of Children who Employer Needs to Care [Enter 0 If Not] \ n->"); scanf(" %u", &Cocuk_Sayisi_Sayac);

        Toplam_Cocuk += Cocuk_Sayisi_Sayac; // Çalisanlarin çocuklari toplami.

            if (Cocuk_Sayisi_Sayac > 0 ){
                if ( Cocuk_Sayisi_Sayac > 3) UcCokCocukSahibiCalisan_Sayac++; // Üçten fazla çocuga sahip çalisanlari bulma.
                CocukSahibiCalisan_Sayac++; // Çocugu olan çalisan sayaci.
                for (i = 0 ; i < Cocuk_Sayisi_Sayac ; i++){  // Çocuklarin yasini girebilmek için döngü.
                        printf("%u. Child's Age : ", i+1); scanf(" %u", &Cocuk_Sayisi[i]); // Çocuklarin yas girisi.
                            if  (Cocuk_Sayisi[i] <= 6)  // Yaslarina göre ödenek birikimi.
                                {Cocuk_Odenek += 25;}
                            else{Cocuk_Odenek += 45;}
                    }
                Aylik_Brut_Toplam[Sayac] += Cocuk_Odenek; // Çocuk ödeneginin brüte eklenmesi.
            }  // Brüt / Toplam Brüt / Net Ücret -> Sonuçta 3 Farkli para isteniyor.
        Calisan_Net_Ucret[Sayac] = Aylik_Brut_Toplam[Sayac]; // Brütü üzerinde islem yapilacak Net ücrete esitleme.
        // Engelli Sorgusu.
        printf("* Whether Employee Has Disability [If Disabled = E / e <-> If No = H / h]\n->"); scanf(" %c", &Calisan_Engelli);
            if (Calisan_Engelli == 'e' || Calisan_Engelli == 'E'){
                Calisan_Engelli_Sayac++; // Engelli çalisan sayaç.

                printf("Employee Disability Rate [%%] \n-> "); scanf(" %u", &Calisan_Engel_Oran); // Engelli Orani Girisi.

                if (Calisan_Net_Ucret[Sayac] > 1777.50){
                    if (Calisan_Engel_Oran > 100 && Calisan_Engel_Oran < 0){
                        printf("\n\n*********   Wrong Odds Entered.   *********\n\n");
                        continue; // Yanlis Giris Uyarisi.
                    }
                    else if (Calisan_Engel_Oran <= 100 && Calisan_Engel_Oran >= 80){
                        Calisan_EngelliDerece[Sayac] = 1;  // Her çalisan için ayri engelli derecesi atamasi.
                        Calisan_Net_Ucret[Sayac] -= 900;  // Engelli oranina göre brütten çikartilmasi gereken miktarin çikartilmasi.
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
            } // Net ücretin girdigi vergi diliminin tespiti.
              if (Calisan_Net_Ucret[Sayac] >=0 && Calisan_Net_Ucret[Sayac] < 1777.50 ){
            Gelir_Kesintisi[Sayac]=0; // Asgari ücret alti Vergi dilimine girmiyor.
            Sayac_2000++; // 2000 TL altinda maas alan çalisanlari sayma.
            Vergi0_Sayac++;}  // Vergi türüne göre kaç çalisanin girdigini sayma.

            else if (Calisan_Net_Ucret[Sayac] >= 1777 && Calisan_Net_Ucret[Sayac] < 2000){
            Gelir_Kesintisi[Sayac] = (Calisan_Net_Ucret[Sayac] / 100) * 15; // Gelir kesintisini hesaplama.
            Vergi15_Sayac++;
            Sayac_2000++;
            Calisan_Net_Ucret[Sayac] -= Gelir_Kesintisi[Sayac];}  // Gelir kesintisini brütten çikarip net ücretti hesaplama.

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



        // Baska isçi girisi sorgulamadan önce bilgileri girilen çalisanin bazi bilgilerini kullaniciya sunma.
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

        Banknot_Ucret = Calisan_Net_Ucret[Sayac] * 100;// Ücret tam sayi olmayan bir sayi olabilir. Bu yüzden risk almayip bu sayiyi 100 ile çarparak
                                                        // tam sayiya çevirdik.
        //Net ücretin en az sayida banknot veya madeni para hesaplamasi.
        printf("~~ Payment of the Employee's Net Wages with Minimum Number of Banknotes and Coins \n");

    Banknot_200 = Banknot_Ucret / 20000; //Kaç adet 200 TL gerektigini bulma.
    if (Banknot_200 > 0){ // 200 TL banknot kullanilacaksa devam et.
            printf("\t\t--> %u Times 200 TL Banknote <--\n", Banknot_200); // Kullanilan Banknot sayisini yazdirma.
            Banknot_200_Sayac+=Banknot_200;} // Tüm Çalisanlar için kullanilan 200TL'lik banknotlari hesaplama.
    Banknot_Ucret = Banknot_Ucret % 20000; // Ücretin 200TL'lik banknotlar ile ödenen kismini çikarma.
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
        printf ("Enter Another Employee? [Evet=E/e <-> Hayir=H/h]:\n->");    scanf (" %c", &Baska_Calisan); // Baska çalisan sorgusu.
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

        }
    while (Baska_Calisan == 'e' || Baska_Calisan == 'E'); // Do-while döngüsü. e veya E'den baska giriste döngü sonlanir.

        for ( i = 0 ; i < Sayac ; i++ ){ // Döngü bittiginden dolayi çalisanlari çagirmak için açilan for döngüsü.
            Toplam_Net_Ucret += Calisan_Net_Ucret[i]; // Tüm çalisanlara verilen toplam Net Ücret hesaplamasi.
            Toplam_Aktarilan_Vergi += Gelir_Kesintisi[i]; // Devlete aktarilan toplam vergi hesaplamasi.
            Toplam_Brut += Aylik_Brut_Toplam[i]; //Tüm çalisanlarin toplam Brüt miktarinin hesaplamasi.
        }

            // Tüm çalisanlarin verileri kullanilarak istenen istatiksel verilerin yazdirilmasi.
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
            // printf içlerinde Yüzde hesabi yapildi.
            printf("~~ Number and Percentage of Employees Not Including the Tax Bracket: %u People %% %u \n\n", Vergi0_Sayac, (Vergi0_Sayac * 100) / Sayac);
            printf("~~ %%15 Number and Percentage of Employees Entering the Tax Bracket : %u People %% %u \n\n", Vergi15_Sayac, (Vergi15_Sayac * 100) / Sayac);
            printf("~~ %%20 Number and Percentage of Employees Entering the Tax Bracket : %u People %% %u \n\n", Vergi20_Sayac, (Vergi20_Sayac * 100) / Sayac);
            printf("~~ %%27 Number and Percentage of Employees Entering the Tax Bracket : %u People %% %u \n\n", Vergi27_Sayac, (Vergi27_Sayac * 100) / Sayac);
            printf("~~ %%35 Number and Percentage of Employees Entering the Tax Bracket : %u People %% %u \n\n\n\n", Vergi35_Sayac, (Vergi35_Sayac * 100) / Sayac);
            Enbuyuk_Brut = Aylik_Brut_Toplam[0]; // Çalisanlar arasinda en fazla Brüt ücreti alan çalisani bulmak için açilan for döngüsü.
            for ( i = 0 ; i < Sayac ; i++ ){
                if ( Aylik_Brut_Toplam[i] > Enbuyuk_Brut){
                    Enbuyuk_Brut = Aylik_Brut_Toplam[i];
                    Enb_Brut = i;}} // Bu çalisana ait baska veriler de istenildigi için isçinin özel sayac numarasini elde etme.
            printf("~~ Employee with the Highest Monthly Brut Wage :\n\n\t=> Identification number: %llu \n", TC_Numara[Enb_Brut]);
            printf("\t=> Name and Surname: %s \n", Calisan_AdSoyad[Enb_Brut]); // En fazla Brüt ücreti alan çalisanin istenen verilerini yazdirma.
            printf("\t=> Total Brut Fees: %.2f TL \n", Aylik_Brut_Toplam[Enb_Brut]);
            printf("\t=> Income Tax Deduction: %.2f TL\n", Gelir_Kesintisi[Enb_Brut]);
            printf("\t=> Net Monthly Fee: %.2f TL \n\n\n\n", Calisan_Net_Ucret[Enb_Brut]);
            Enbuyuk_Net = Calisan_Net_Ucret[0]; // Çalisanlar arasinda en fazla Net ücreti alan çalisani bulmak için açilan for döngüsü.
            for ( i = 0 ; i < Sayac ; i++ ){
                    if ( Calisan_Net_Ucret[i] > Enbuyuk_Net){
                Enbuyuk_Net = Calisan_Net_Ucret[i];
                Enb_Net = i;}} // Bu çalisana ait baska veriler de istenildigi için isçinin özel sayac numarasini elde etme.
            printf("~~ Employee with the Highest Monthly Net Wage :\n\n\t=> Identification number: %llu \n", TC_Numara[Enb_Net]);
            printf("\t=> Name and Surname: %s \n", Calisan_AdSoyad[Enb_Net]); // En fazla Net ücreti alan çalisanin istenen verilerini yazdirma.
            printf("\t=>  Total Brut Fees: %.2f TL \n", Aylik_Brut_Toplam[Enb_Net]);
            printf("\t=> Income Tax Deduction: %.2f TL\n", Gelir_Kesintisi[Enb_Net]);
            printf("\t=> Monthly Net Fee: %.2f TL \n\n\n", Calisan_Net_Ucret[Enb_Net]);
            printf("~~ Percentage of Married Among Employees = %% %d \n\n", (Calisan_Evli_Sayac * 100) / Sayac); // Yine bir yüzde hesabi
            // Evli çalisanlari bulmak için tüm isçilerden evli olanlar çikartilip yüzde hesabi yapildi.
            printf("~~ Percentage of Single Employees = %% %d \n\n", ((Sayac - Calisan_Evli_Sayac)  * 100) / Sayac);
            // Esi çalisan çalisanlari bulmak için evli çalisanlardan evli olup esi çalismayan çalisanlar çikartilip yüzde hesabi yapildi.
            printf("~~ Percentage of Married Employees Among Married Employees = %% %d \n\n", ((Calisan_Evli_Sayac - Calismayan_Es_Sayac) * 100) / Sayac );
            //yüzde hesabi
            printf("~~ Number and Percentage of Disabled Employees = %d Kisi %% %d\n\n", Calisan_Engelli_Sayac, (Calisan_Engelli_Sayac * 100) / Sayac);
            // Ortalama hesabi
            if ( Toplam_Cocuk > 0){
            printf("~~ Average Number of Children Employe needs to Care = %.1f \n\n", Toplam_Cocuk / CocukSahibiCalisan_Sayac);}
            printf("~~ Number of Employees that Has More than 3 Children = %d \n\n", UcCokCocukSahibiCalisan_Sayac);


            printf("<><><><><><><><><><><><><><><>   PROGRAM SONU   <><><><><><><><><><><><><><><>");

}







