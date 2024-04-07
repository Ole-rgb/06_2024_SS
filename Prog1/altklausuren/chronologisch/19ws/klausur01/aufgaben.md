1. String: String gegeben mit mehreren Wörter und Leerzeichen

   autoCorrectCases.c
   a. ersten Buchstaben eines Wortes groß den Rest klein 
   
   - Eingabe: HELLO WORLD
   - Ausgabe: Hello World

   b. int long unsigned = sizeof(xmalloc(5)), warum problematisch?

2. Linked List: <br>
   copyNElementsFromList.c
   a. Liste mit Zahlen gegeben, die ersten n Elemente in neuer Liste speichern und zurückgeben, falls n > Listengröße komplette Liste zurückgeben, falls n = 0 nichts zurückgeben

   - Eingabe: Liste (1,2,3), n = 2
   - Rückgabe (1,2)

   b. warum Node Deklaration problematisch?

   ```
   typedef struct Node
   {
   int value;
   struct Node next;
   } Node;
   ```

3. Tree:<br>
   quadSumTree.c
   a. Linkes Kinder mit Rechtem tauschen und den Value quadrieren und in einen neuen Baum speichern <br>
   b. Summe eines Baumes iterativ berechnen, groben Algorithmus aufschreiben

4. 2D-Matrix: <br>
   arrayAnalyzer.c
   a. 2D-Matrix mit Buchstaben und - gegeben, Anzahl der gegebenen chars pro Spalte in 1D-Array speichern <br>
   Eingabe 2D Array, a <br>
   a - a a --> 3 <br>
   b - - - --> 0 --> [3,0] Rückgabe Array <br>

   b. keine Ahnung mehr
