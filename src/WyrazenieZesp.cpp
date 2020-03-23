#include "WyrazenieZesp.hh"
#include <iostream>


using namespace std;

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


void Wyswietlwyrazenie(WyrazenieZesp WyrZ)
{
  Wyswietl(WyrZ.Arg1);
  switch (WyrZ.Op)
  {
  case Op_Dodaj:
    cout << "+";
    break;
  case Op_Odejmij:
    cout << "-";
    break;
  case Op_Mnoz:
    cout << "*";
    break;
  case Op_Dziel:
    cout << "/";
    break;
  }
  Wyswietl(WyrZ.Arg2);
}


LZespolona Oblicz(WyrazenieZesp WyrZ){

  LZespolona Wynik;

  switch(WyrZ.Op){

      case Op_Dodaj:
      Wynik=WyrZ.Arg1+WyrZ.Arg2;
      break;

      case Op_Odejmij:
      Wynik=WyrZ.Arg1-WyrZ.Arg2;
      break;

      case Op_Mnoz:
      Wynik=WyrZ.Arg1*WyrZ.Arg2;
      break;

      case Op_Dziel:
      Wynik=WyrZ.Arg1/WyrZ.Arg2;
      break;

      
  }

return Wynik;
}

ostream &operator<<(ostream &StrmWy, WyrazenieZesp WyrZ)
{
  StrmWy << WyrZ.Arg1 << " ";
  switch (WyrZ.Op)
  {
  case Op_Dodaj:
    StrmWy << "+";
    break;
  case Op_Odejmij:
    StrmWy << "-";
    break;
  case Op_Mnoz:
    StrmWy << "*";
    break;
  case Op_Dziel:
    StrmWy << "/";
    break;
  }
  StrmWy << " ";
  StrmWy << WyrZ.Arg2;
  return StrmWy;
}

