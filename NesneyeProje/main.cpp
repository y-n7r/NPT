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