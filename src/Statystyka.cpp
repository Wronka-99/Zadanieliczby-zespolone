#include <iostream>
#include "Statystyka.hh"


void inicjuj(dane &st) // ta funkcja daje nam gwarancje ze dobre i zle odpowiedzi sa wyzerowane
{

    st.poprawne=0;
    st.niepoprawne=0;

}

void dodaj_poprawna(dane &st)//funkcja dodajaca poprawna odpowiedz
{
    st.poprawne++;
}


void dodaj_niepoprawna(dane &st)//funkcja dodajaca niepoprawna odpowiedz
{
    st.niepoprawne++;
}

double liczba_poprawnych(dane &st)//funkcja zwracajaca liczbe poprawnych odpowiedzi
{   
    double poprawne;

    poprawne=st.poprawne;

    return poprawne;
}


double liczba_niepoprawnych(dane &st)//funkcja zwracajaca liczbe niepoprawnych odpowiedzi
{   
    double niepoprawne;

    niepoprawne=st.niepoprawne;

    return niepoprawne;
}


void wyswietl_dane (dane &st)// funkcja obliczajaca i wyswietlajaca dane statystyczne
{

    double procent_dobrych=0; // uzycie zmiennych typu double powoduje ze wynik procentowy
    double wszystkie=0;// podawany jest z dokladnoscia do czesci ulamkowych

    wszystkie=st.poprawne+st.niepoprawne;

    if(wszystkie)// zabezpieczenie przed dzieleniem przez 0
        {
            procent_dobrych=st.poprawne/wszystkie*100;  
        }
    else
        {
            procent_dobrych=0;
        }


    std::cout<<std::endl<<"Statystyka:"<<std::endl; // wyswietlanie podsumowania
    std::cout<<"Liczba poprawnych: "<<st.poprawne<<std::endl;
    std::cout<<"Liczba niepoprawnych: "<<st.niepoprawne<<std::endl;
    std::cout<<"Procent dobrych odpowiedzi: "<<procent_dobrych<<"%"<<std::endl;

    
}


