#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"


using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  dane statystyka;
  LZespolona wpisana; 
  LZespolona poprawna;
  bool dzialanie=0; // powolanie zmiennej odpowiedzialnej za sprawdzanie formatu wprowadzanej liczby
  float wartosc_bezwzgledna_re, wartosc_bezwzgledna_im;

  inicjuj(statystyka);// wyzerowanie struktury statystyka
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout <<endl<<endl<< " Podaj wynik ponizszego dzialania arytmetycznego."<<endl;
    cout << WyrZ_PytanieTestowe << endl;

    cout<<"Wpisz odpowiedz:"<<endl;
    cin.clear();
    cin>>wpisana;
    dzialanie=cin.good();

    while(dzialanie==0) // sprawdzanie czy wprowadzona liczba ma poprawny format
    {   

        cin.clear();
        cin.ignore(10000, '\n');
        cout<< "Blad podczas wpisywania liczby zespolonej. Ponow probe. "<<endl;
        cout<< "Poprawna forma to (czesc_rzeczywista+czesc_urojona_i) "<<endl;
        cin >> wpisana;
        dzialanie=cin.good();

    }
    
    poprawna=Oblicz(WyrZ_PytanieTestowe);//tutaj wykonywana jest operacja matematyczna przez komputer
    
    cout<<"Poprawna odpowiedz to:"<<poprawna<<endl;

    wartosc_bezwzgledna_re=abs(poprawna.re-wpisana.re);//obliczanie wartosci bezwzglednej
    wartosc_bezwzgledna_im=abs(poprawna.im-wpisana.im);


    if((wartosc_bezwzgledna_re<0.01)&&(wartosc_bezwzgledna_im<0.01))//jesli odpowiedz pokrywa sie do 
    //dwoch miejsc po przecinku liczba jest uznawana za poprawna
    {

      dodaj_poprawna(statystyka);//funkcja zwiekszajaca liczbe poprawnych odpowiedzi
    }
    else
    {
      dodaj_niepoprawna(statystyka);//funkcja zwiekszajaca liczbe niepoprawnych odpowiedzi
    }
    
  }

  wyswietl_dane(statystyka);//wyswietlenie podsumowania statystyki


  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;





  
}
