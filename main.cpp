#include <iostream>
#include <fstream>

/*
https://stackoverflow.com/questions/22190048/how-to-write-the-content-of-an-array-into-a-text-file
*/

int main(void) {
    int SoruSayisi = 0;
    int i;
    int Puan = 0;
    int OgrenciSayisi = 0;
    int z = 0;
    int ToplamPuan = 0;
    int Ortalama = 0;
    int Aciklik;
    int OgrenciPuanlari[OgrenciSayisi+5];
    char x = '\0';
    char CevapAnahtari[SoruSayisi];
    char OgrenciCevap[SoruSayisi+1];
    std::fstream Dosya;
    
    Dosya.open("input.txt");
    
    std::cout << "Sınavdaki toplam soru sayısını giriniz:";
    std::cin  >> SoruSayisi;
    
    std::cout << "Cevap anahtarını giriniz:\n";
    for (i = 0; i < SoruSayisi; i++) {
        std::cin >> CevapAnahtari[i];
            if (Dosya.is_open()) {
                for(int i = 0; i < SoruSayisi; i++) {
                    Dosya << CevapAnahtari[i];
                }
            }
    }
        
    std::cout << "Öğrenci sayısını giriniz(max 100 tane öğrenci için işlem yapılabilir!):";
    std::cin >> OgrenciSayisi;
    if (OgrenciSayisi <= 100) {
        for (i = 1; i <= OgrenciSayisi; i++) {
            std::cout << "Öğrencinin numarasını girdikten sonra cevaplarını giriniz(Eğer boş ise x yazınız!):";
            
            for (i = 0; i <= SoruSayisi; i++) {
                std::cin >> OgrenciCevap[i+1];
                if (Dosya.is_open()) {
                    for(int i = 0; i < SoruSayisi+1; i++) {
                        Dosya << OgrenciCevap[i+1];
                    }
                }
                
                for (i = 0; i <= SoruSayisi; i++) {
                    if (CevapAnahtari[i] == OgrenciCevap[i+1]) {
                        Puan = Puan + 4;
                    }
                    else if (CevapAnahtari[i] != OgrenciCevap[i+1]) {
                        Puan = Puan - 1;
                    }
                    else if(OgrenciCevap[i+1] == x){
                        Puan = Puan + 0;
                    }
                    
                    OgrenciPuanlari[i] = Puan;
                    ToplamPuan = ToplamPuan + Puan;
                }
                
            }
            if (Puan < 0) {
                Puan = 0;
            }
        }
    }
    
    for (i = 0; i <= OgrenciSayisi; i++) {
        if (OgrenciPuanlari[i] > OgrenciPuanlari[i+1]) {
            OgrenciPuanlari[i] = z;
            OgrenciPuanlari[i+1] = OgrenciPuanlari[i];
            OgrenciPuanlari[i+1] = z;
        }
    }
    
    Ortalama = ToplamPuan % OgrenciSayisi;
    Aciklik = OgrenciPuanlari[OgrenciSayisi] - OgrenciPuanlari[0];
    
    OgrenciPuanlari[OgrenciSayisi+1] = OgrenciPuanlari[0]; // En düşük not.
    OgrenciPuanlari[OgrenciSayisi+2] = OgrenciPuanlari[OgrenciSayisi]; // En yüksek not.
    OgrenciPuanlari[OgrenciSayisi+3] = Ortalama;
    OgrenciPuanlari[OgrenciSayisi+4] = OgrenciPuanlari[OgrenciSayisi % 2];
    OgrenciPuanlari[OgrenciSayisi+5] = Aciklik;
    
    Dosya.close();
    
    return 0;
}
