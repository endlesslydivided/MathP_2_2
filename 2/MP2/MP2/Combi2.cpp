#include "Combi2.h"
namespace combi2 //сочетания
{
    xcombination::xcombination(short n, short m) {
        this->n = n;                         // количество элементов исходного множества  
        this->m = m;                         // количество элементов в сочетаниях 
        this->sset = new short[m + 2];      // массив индексов текущего сочетания 
        this->reset();
    }
    void  xcombination::reset()     // сбросить генератор, начать сначала 
    {
        this->nc = 0;
        for (int i = 0; i < this->m; i++) this->sset[i] = i;
        this->sset[m] = this->n;
        this->sset[m + 1] = 0;
    };
    short xcombination::getfirst() {
        return (this->n >= this->m) ? this->m : -1;
    };
    short xcombination::getnext()   // сформировать следующий массив индексов  
    {
        short rc = getfirst();
        if (rc > 0)
        {
            short j;
            for (j = 0; this->sset[j] + 1 == this->sset[j + 1]; ++j)
                this->sset[j] = j;
            if (j >= this->m) 
                rc = -1;
            else 
            {
                this->sset[j]++;
                this->nc++;
            };
        }
        return rc;
    };
    short xcombination::ntx(short i) { return this->sset[i]; };              // получить i-й элемент массива индексов
    unsigned __int64 fact(unsigned __int64 x) { return(x == 0) ? 1 : (x * fact(x - 1)); };
    unsigned __int64 xcombination::count() const
    {
        return (this->n >= this->m) ?
            fact(this->n) / (fact(this->n - this->m) * fact(this->m)) : 0;
    };
};
