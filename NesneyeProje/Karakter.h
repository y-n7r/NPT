#ifndef KARAKTER_H
#define KARAKTER_H

#include <iostream>
#include <string>
using namespace std;

class Karakter {
protected:
    string isim;
    int can;
    int guc;
    int savunma;
    int sonHasar;

    public:
Karakter(const string& isim, int can, int guc, int savunma);
    virtual void saldir(Karakter* hedef);
    virtual void savun();
    virtual void ozelYetenek();
    void canAzalt(int miktar);
    bool hayattaMi() const;
    string getIsim() const;
    int getCan() const;
    int getSavunma() const;
    void sifirlaSavunma();
    virtual ~Karakter();
};