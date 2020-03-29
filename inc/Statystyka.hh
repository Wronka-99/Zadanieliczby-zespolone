#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH


struct dane{    //struktura danych do statystyki

    double poprawne;
    double niepoprawne;

};

void inicjuj(dane & st);// zeruje wartosci dobrych i zlych
void dodaj_poprawna(dane &st);// dodaje poprawna odpowiedz do struktury
void dodaj_niepoprawna(dane &st);// dodaje niepoprawna odpowiedz do struktury
void wyswietl_dane(dane &st);

double liczba_poprawnch(dane &st);// zwraca  liczbe poprawnych odpowiedzize struktury
double liczba_wszystkich(dane &st);// zwraca sume poprawnych i niepoprawnych odpowiedzi ze struktury
double procent_poprawnych(dane &st);// zwraca procentowy stosunek odpowiedzi poprawnych do wszystkich


#endif