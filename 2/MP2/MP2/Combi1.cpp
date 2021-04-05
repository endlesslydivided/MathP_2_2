#include "Combi1.h"
namespace combi1
{
    subset::subset(short n) {
        this->n = n;                 // количество элементов исходного множества < 64  
        this->sset = new short[n];   // массив индексов текущего подмножества 
        this->reset();              // сбросить генератор, начать сначала 
    };
    void  subset::reset() {
        this->sn = 0;               // количество элементов текущего  подмножества
        this->mask = 0;             // битовая маска 
    };
    short subset::getfirst() {      // сформ. массив индексов по битовой маске  
        __int64 buf = this->mask;
        this->sn = 0;
        for (short i = 0; i < n; i++) {
            if (buf & 0x1) this->sset[this->sn++] = i;
            buf >>= 1;
        }
        return this->sn;
    };
    short subset::getnext() {       // ++маска и сформировать массив индексов
        int rc = -1;
        this->sn = 0;
        if (++this->mask < this->count()) rc = getfirst();
        return rc;
    };
    short subset::ntx(short i) {
        return  this->sset[i];
    };
    unsigned __int64 subset::count() {  // вычислить общее кол-во подмножеств 
        return (unsigned __int64)(1 << this->n);
    };
};
