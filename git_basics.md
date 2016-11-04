## Git – podstawy

Podstawowe polecenia:

```bash
mkdir labjp
cd labjp
git init    # inicjalizujemy repo: git tworzy katalog .git/
cat > README.md
## Notatki z programowania w C

TODO
```
Teraz wciskamy `ctrl + d` kończąc w ten sposób edycję pliku _README.md_.

Teraz wykonujemy:

```bash
git add README.md # dodajemy plik do repozytorium
git commit -m "dodano plik README.md"
```

Praca z kodem w repozytorium przebiega w takiej pętli.

```bash
# edycja plików
git add . # dodajemy wszystkie zmienione pliki
git commit -m "dodano/edytowano/zmieniono pliki ..."
# edycja, add, commit
```

Kolejne kroki:

1. [Zakładamy konto na https://github.com]
  i [konfigurujemy nowe konto](https://git-scm.com/book/en/v2/GitHub-Account-Setup-and-Configuration).
1. Tworzymy na Github nowe repozytorium o nazwie _labjp_
  (klikamy w zielony przycisk **New repository**).
  - Dodajemy repozytorium z katalogu _labjp_ na swoim komputerze
    do swoich repozytoriów na Github.

Można też zajrzeć [tutaj](https://www.learnenough.com/git-tutorial#sec-sharing).

Po dodaniu repozytorium do Githuba, zmieniamy pracę z kodem.
Teraz zawsze zaczynamy od ściągnięcia najnowszej wersji repozytorium
i kończymy przesłaniem zmienionego kodu na Githuba.

```bash
git pull
# edycja
git add . # dodajemy wszystkie zmienione pliki
git commit -m "dodano/edytowano/zmieniono pliki ..."
# edycja, add, commit
git push
```
