#include "LZespolona.hh"
#include <iostream>

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */



LZespolona sprzezenie (LZespolona Skl1){

    LZespolona wynik;

    wynik.re=Skl1.re;
    wynik.im=-Skl1.im;

    return wynik;
}


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}



LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}



LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2.re-Skl1.im*Skl2.im;
  Wynik.im = Skl1.im*Skl2.re + Skl1.re*Skl2.im;
  return Wynik;
}



LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  double modul;

  modul= Skl2.re*Skl2.re+Skl2.im*Skl2.im;

  if(modul>0)
    {
      
    Wynik.re = (Skl1.re*Skl2.re+Skl1.im*Skl2.im)/modul;
    Wynik.im = (Skl2.re*Skl1.re-Skl1.re*Skl2.im)/modul;
    
    
    }

    else
    {
      std::cout<<"Modul drugiej liczby jest ujemny, badz rowny zero."<< std::endl;
    }
    
  return Wynik;
}

void Wyswietl(LZespolona Skl1)
{
  cout << "(" << Skl1.re << showpos << Skl1.im << "i" << noshowpos << ")";
}

ostream &operator<<(ostream &StrmWy, LZespolona Lz)
{
  return StrmWy << "(" << Lz.re << showpos << Lz.im << "i)" << noshowpos;
}

istream &operator>>(istream &StrmWe, LZespolona &Lz)
{
  StrmWe>>Lz.re>>Lz.im;

  return StrmWe;

}

// cosinus

