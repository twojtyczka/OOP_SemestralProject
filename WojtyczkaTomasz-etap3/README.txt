Temat: Rejestr magazynu

Etap 1
Napisz program oferujący następujące funkcjonalności:

1. Po uruchomieniu użytkownik ma możliwość dodania towaru przechowywanego w
magazynie.
2. Towar reprezentowany jest przez obiekty klasy “Towar”. Klasa ta zawiera ID, nazwę
towaru oraz liczbę sztuk.
3. Przy dodawaniu towaru jego ID jest ustawiane na ID ostatnio dodanego towaru plus 1
(albo zero w przypadku pierwszego towaru), nazwa na taką jak poda użytkownik oraz
liczba sztuk na 0.
4. Jeśli zdefiniowany jest przynajmniej jeden towar, to użytkownik ma również możliwość
dodania i usunięcia określonej ilości towarów. Do tego służą dwie komendy: “przyjęcie” i
“odbiór”. W obu komendach użytkownik dostaje listę zdefiniowanych towarów
(wypisywane są w kolejnych listach ID, nazwy i liczby sztuk), następnie musi podać ID
towaru oraz ile sztuk jest dodawanych bądź usuwanych.
5. Jeśli użytkownik chce pobrać więcej sztuk towaru niż jest w magazynie, informowany
jest o błędzie i musi wprowadzić nową liczbę sztuk towaru.
6. Magazyn reprezentowany jest przez obiekt klasy “Magazyn”. Klasa ta zawiera std::vector
obiektów typu Towar.

Etap 2:

1. Dodajemy nowe typy towarów: towar sypki, towar ciekły. Te dwie klasy oraz klasa Towar
(na sztuki) mają dziedziczyć po klasie “Produkt” zawierającej ID. w nowych klasach,
zamiast liczby sztuk, ilość określana jest kg bądź litrami (liczba zmiennoprzecinkowa).
2. Można utworzyć więcej niż 1 magazyn. ID Towaru ma być unikalne w obrębie
wszystkich magazynów.
3. Wprowadzamy klasę Paleciak, która posiada vector wskaźników do Produktów i udźwig.
4. Magazyn posiada dodatkowo metody:
a. ‘wydaj’, która zmniejsza stan magazynowy i ładuję dany towar na Paleciaka.
b. ‘przyjmij’, która zwiększa stan magazynowy i pobiera produkty z Paleciaka do
magazynu.
5. Klasa Towar posiada metody:
a. ‘podziel’, która tworzy nowy obiekt swojego typu i wydziela ilość towaru wg
informacji od użytkownika, następnie zwraca go przez wskaźnik.
b. ‘scal’, która przyjmuje wskaźnik na towar i zwiększa swój stan o ilość z
przyjętego towaru, następnie zwalnia wskaźnik.
6. Proszę zaimplementować rozwiązanie tak, aby dodanie nowego typu towaru nie
wymagało konieczności ingerencji w klasę Magazyn lub Paleciak.

Program pozwala na uruchomienie z argumentem wiersza poleceń, którym jest ścieżka
do pliku. W takim przypadku program ma wykonać polecenia (komendy) znajdujące się w tym
pliku zamiast czytania ze standardowego wejścia. W przypadku braku argumentu wywołania
programu, program zachowuje się jak dotychczas, czyli czyta komendy ze standardowego
wejścia. W przesłanym archiwum proszę umieścić jeden lub więcej plików z komendami. Nazwa
pliku powinna się zaczynać “stdin” i kończyć na “.txt”.

Etap 3:

● W programie znajdują się instrukcje rzucające wyjątki (throw) przynajmniej 2 typów oraz
zapewniona jest ich obsługa. Obsługa sytuacji wyjątkowych znajduje się poza funkcją
rzucającą wyjątek, tak aby instrukcja throw nie znajdowała się bezpośrednio w bloku try.
● W programie powinna się znaleźć przynajmniej jeden sensowny szablon klasy lub dwa
szablony funkcji. Klasą może być np. kontener.
● Programy nie powinny wyświetlać żadnych ostrzeżeń podczas kompilacji.
● Pliki z komendami powinny prezentować nowe funkcjonalności, czyli pokazać
wykorzystanie szablonów oraz rzucanie i łapanie wyjątków