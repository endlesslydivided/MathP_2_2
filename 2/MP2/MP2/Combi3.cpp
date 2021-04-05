#include "Combi3.h"
#include <algorithm>
#define NINF  ((short)0x8000)
namespace combi3 //перестановки
{
    permutation::permutation(short n) {
        this->n = n;                    // количество элементов исходного множества 
        this->sset = new short[n];      // массив индексов текущей перестановки
        this->dart = new bool[n];       // массив  стрелок (левых-L и правых-R)
        this->reset();
    };
    void  permutation::reset() { this->getfirst(); };
    __int64  permutation::getfirst() {        // сформировать первый массив индексов
        this->np = 0;                           // номер перествновки 0,... count()-1 
        for (int i = 0; i < this->n; i++) { this->sset[i] = i; this->dart[i] = L; };
        return  (this->n > 0) ? this->np : -1;
    };
    __int64  permutation::getnext() {   // сформировать случайный массив индексов  
        __int64 rc = -1;
        short maxm = NINF, idx = -1;
        for (int i = 0; i < this->n; i++) {
            if (i > 0 &&
                this->dart[i] == L &&
                this->sset[i] > this->sset[i - 1] &&
                maxm < this->sset[i])  maxm = this->sset[idx = i];
            if (i < (this->n - 1) &&
                this->dart[i] == R &&
                this->sset[i] > this->sset[i + 1] &&
                maxm < this->sset[i])  maxm = this->sset[idx = i];
        };
        if (idx >= 0) {
            std::swap(this->sset[idx], this->sset[idx + (this->dart[idx] == L ? -1 : 1)]);
            std::swap(this->dart[idx], this->dart[idx + (this->dart[idx] == L ? -1 : 1)]);
            for (int i = 0; i < this->n; i++)
                if (this->sset[i] > maxm) this->dart[i] = !this->dart[i];
            rc = ++this->np;
        }
        return rc;
    };
    short permutation::ntx(short i) { return  this->sset[i]; };     // получить i-й элемент масива индексов 
    unsigned __int64 fact(unsigned __int64 x) { return (x == 0) ? 1 : (x * fact(x - 1)); };
    unsigned __int64 permutation::count() const { return fact(this->n); };      // вычислить общее кол. перестановок
};
