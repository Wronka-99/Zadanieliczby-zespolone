#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
LZespolona utworz(double a, double b){

    LZespolona liczba;

    liczba.re=a;
    liczba.im=b;

    return liczba;
}

void Wyswietl(WyrazenieZesp Wyr2){

  cout<<'('<<Wyr2.re<<", i"<<Wyr2.im<<')'<<"\n";


}

