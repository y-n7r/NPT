#include "Karakter.h"
#include <cstdlib>
#include <ctime>

class SavasOyunu {
private:
    Kullanici* kullanici;
    Dusman* dusman;

public:
    SavasOyunu(const string& kullaniciIsim)
        : kullanici(new Kullanici(kullaniciIsim)), dusman(new Dusman("Dusman")) {
        srand(static_cast<unsigned>(time(0)));
    }

    ~SavasOyunu() {
        delete kullanici;
        delete dusman;
    }

    void oyunuBaslat() {
        cout << "=== Savas Basliyor! ===" << endl;
        while (kullanici->hayattaMi() && dusman->hayattaMi()) {
            cout << "\n";
            durumGoster();

            int secim = 0;
            while (true) {
                cout << "1. Saldir\n2. Savun\n3. Ozel Yetenek\nSeciminiz: ";
                cin >> secim;

                if (secim == 1 || secim == 2 || secim == 3) {
                    break;
                } else {
                    cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
                }
            }

            if (secim == 1) {
                kullanici->saldir(dusman);
            } else if (secim == 2) {
                kullanici->savun();
            } else if (secim == 3) {
                kullanici->ozelYetenek();
            }

            dusman->sifirlaSavunma();

            if (dusman->hayattaMi()) {
                int dusmanSecim = rand() % 3 + 1;
                if (dusmanSecim == 1) {
                    dusman->saldir(kullanici);
                } else if (dusmanSecim == 2) {
                    dusman->savun();
                } else {
                    dusman->ozelYetenek();
                }
            }

                    kullanici->sifirlaSavunma();
        }

        sonucuGoster();
    }