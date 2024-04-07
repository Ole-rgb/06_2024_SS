# 17ws

- [x] Aufgabe 1 camelcase

  - strings mit xmalloc kopieren über string laufen und alle lowercases in string direkt übergeben, leerzeichen auch, uppercases je nach position übergeben oder zu "\_x" transformieren. die zusätzliche größenveränderung beim allocieren natürlich vorher beachten
  - Originalstring nicht verändern
  - Rückgabestring dynmanisch allokieren
  - Hilfsfunktionen
    - is_letter()....
    - is_upper()....
    - is_lower()....
    - to_upper()...
    - to_lower()...
  - Uppercase zu Lowercase
  - nur wenn Uppercase \_ untermische und und die innere Buchstabe zu lowercase
  - Beispiele
    - abcd --> abcd
    - Abcd --> Abcd
    - ABCD --> A_b_c_d
    - ABCDEF --> A_b_c_d_e_f
    - ABCD EF --> A_b_c_d E_f

- [x] Aufgabe 2 removeletters

  - nur mit hilfsfunktionen strings in exakt größen allokierten copy string übertragen, alles was letters sind ignorieren.
  - Zahlen aus String rausschreiben
  - Originalstring nicht verändern
  - Rückgabestring dynmanisch allokieren
  - nur Hilfsfunktionen verwenden und xmalloc
    - is_letter
    - s_length
  - Beispiele
    - " " --> " "
    - "abc " --> " "
    - "1abc" --> "1"
    - "x11" --> "11"
    - "1a2b3c4d" --> "1234"

- [ ] Aufgabe 3 donkeys
  - Gewichte gleichmäßig auf Eselrücken verteilen
    - Tasche rechts, links
