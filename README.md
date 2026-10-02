# Centru de meditații

Aplicație de consolă scrisă în **C++** care simulează un centru de meditații pentru **matematică, informatică și fizică**. Utilizatorii se pot autentifica ca **elev** sau ca **administrator**, iar datele sunt păstrate în fișiere text.

> Aplicația folosește `windows.h`, `conio.h` și `system("CLS")`, deci rulează **doar pe Windows**.

## Funcționalități

### Meniul principal
1. Autentificare
2. Înregistrare (creare cont nou)
3. Informații cursuri
0. Exit

### Elev
- creare cont și autentificare cu utilizator și parolă
- înscriere la unul sau mai multe cursuri: matematică, informatică, fizică
- vizualizare ore rămase până la obținerea diplomei (20 de ore pe curs) și data următoarei ședințe
- dacă a terminat orele, aplicația anunță că elevul își poate ridica diploma
- dacă nu e înscris la un curs, i se oferă posibilitatea să se înscrie direct din meniu

### Administrator
- afișare elevi, cu sortare după nume sau după utilizator
- căutare elev după nume
- ștergere elev (cere din nou parola de administrator și îl elimină și din cursurile la care e înscris)

### Informații cursuri
- coordonatori și profesori meditatori pentru fiecare materie
- prețuri: 150 lei / 2 h pe ședință, pachet complet (matematică + informatică + fizică) 400 lei

## Structura proiectului

| Fișier | Rol |
|---|---|
| `main.cpp` | codul sursă al aplicației |
| `proiect_struct.cbp` | fișierul de proiect Code::Blocks |
| `incarcare_util` | conturile utilizatorilor: nume, prenume, utilizator, parolă |
| `matematica`, `informatica`, `fizica` | elevii înscriși la fiecare curs și orele efectuate |
| `cursuri` | lista cursurilor la care e înscris fiecare elev |

## Cum se rulează

### Cu Code::Blocks
1. Descarcă proiectul (**Code → Download ZIP**) și dezarhivează-l.
2. Deschide `proiect_struct.cbp` în Code::Blocks.
3. Apasă **Build and run** (F9).

### Din terminal (MinGW)
```bash
g++ main.cpp -o program
program.exe
```

> **Important:** fișierele de date (`incarcare_util`, `matematica`, `informatica`, `fizica`, `cursuri`) trebuie să fie în același folder din care se rulează programul, altfel conturile și înscrierile nu se încarcă.

## Conturi de test

| Rol | Utilizator | Parolă |
|---|---|---|
| Elev | `andrei.ion` | `1234` |
| Administrator | `admin` | `2024admin` |

Datele din fișiere sunt exemple, create pentru testare.

## Tehnologii

- C++ (structuri, fișiere, `fstream`)
- Code::Blocks

## Autor

Raluca ([@Ralu06](https://github.com/Ralu06))
