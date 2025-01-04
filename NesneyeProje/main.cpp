#include "Karakter.h"
#include <cstdlib>
#include <ctime>

// SavaşOyunu sınıfı, oyunun kendisini temsil eder
class SavasOyunu {
private:
    Kullanici* kullanici;   // Oyuncuyu işaret eder
    Dusman* dusman;     // Düşmanı işaret eder

public:

    // Kurucu, oyuncu ve düşmanı ayarlar ve rastgele sayı üretimini başlatır
    SavasOyunu(const string& kullaniciIsim)
        : kullanici(new Kullanici(kullaniciIsim)), dusman(new Dusman("Dusman")) {
        srand(static_cast<unsigned>(time(0)));      // Rastgele sayı üreteci için başlangıç ayarı
    }

    // Yıkıcı, dinamik olarak ayrılan belleği serbest bırakır
    ~SavasOyunu() {
        delete kullanici;
        delete dusman;
    }

    // Oyunu başlatan fonksiyon
    void oyunuBaslat() {
        cout << "=== Savas Basliyor! ===" << endl;
        while (kullanici->hayattaMi() && dusman->hayattaMi()) {
            cout << "\n";
            durumGoster();  // Oyuncu ve düşmanın durumunu göster

            int secim = 0;
            while (true) {
                  // Oyuncuya seçenekleri sunar
                cout << "1. Saldir\n2. Savun\n3. Ozel Yetenek\nSeciminiz: ";
                cin >> secim;

                if (secim == 1 || secim == 2 || secim == 3) {
                    break;  // Geçerli seçim yapıldığında döngüyü kır
                } else {
                    cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
                }
            }

             // Oyuncunun seçtiği işlemi uygular
            if (secim == 1) {
                kullanici->saldir(dusman);
            } else if (secim == 2) {
                kullanici->savun();
            } else if (secim == 3) {
                kullanici->ozelYetenek();
            }

            dusman->sifirlaSavunma();   // Düşmanın savunmasını sıfırla

            // Eğer düşman hayattaysa, düşman hamlesini yapar
            if (dusman->hayattaMi()) {
                int dusmanSecim = rand() % 3 + 1;       // Düşmanın rastgele bir seçimi
                if (dusmanSecim == 1) {
                    dusman->saldir(kullanici);
                } else if (dusmanSecim == 2) {
                    dusman->savun();
                } else {
                    dusman->ozelYetenek();
                }
            }

                    kullanici->sifirlaSavunma();        // Oyuncunun savunmasını sıfırla
        }

        sonucuGoster();     // Oyunun sonucunu göster
    }


    // Oyuncu ve düşmanın durumunu gösteren fonksiyon
    void durumGoster() {
        cout << kullanici->getIsim() << " Can: " << kullanici->getCan() << " Savunma: " << kullanici->getSavunma() << endl;
        cout << dusman->getIsim() << " Can: " << dusman->getCan() << " Savunma: " << dusman->getSavunma() << endl;
    }

    // Oyunun sonucunu gösteren fonksiyon
     void sonucuGoster() {
        if (kullanici->hayattaMi()) {
            cout << "Tebrikler! Kazandiniz." << endl;
        } else {
            cout << "Maalesef kaybettiniz." << endl;
        }
    }
};


int main() {
    string kullaniciIsim;
        // Oyuncunun adını iste
    cout << "Oyuncu ismini girin: ";
    cin >> kullaniciIsim;
    
    // Oyunu oluştur ve başlat
    SavasOyunu oyun(kullaniciIsim);
    oyun.oyunuBaslat();

    return 0;
}