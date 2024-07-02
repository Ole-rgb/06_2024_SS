- [ ] Klausur 1

  - [x] Aufgabe 1 reverseString
    - Strings in einer Liste reversen
  - [x] Aufgabe 2 treeToList
    - Aus einem Tree eine Liste machen
  - [x] Aufgabe 3 sumWithoutLeafs
  - Summe aus Tree bilden ohne die Blätter (left and right==NULL)
  - [x] Aufgabe 4 removeChars
  - Chars aus einem String entfernen

- [ ] Klausur 2

  - [x] Aufgabe 1 innerNodeSum
    - Berechnen der Summe von inneren Tree Nodes
  - [x] Aufgabe 2 stringDifference
    - Remove String. 2 Strings gegeben.
    - Alle chars die in String 1 vorkommen, aber nicht in String 2 in einen neuen allokierten String übergeben

- [ ] Klausur 3

  - [x] Aufgabe 1 treeToList
    - Baum in zwei Listen sortieren per Pointer. Alles kleiner als Grenze=Klein. Rest=Groß
  - [x] Aufgabe 2 countedUpperLower
    - String war gegeben. Sollte abwechselnd zu Upper und Lowercase gemacht werden mit bestimmter Anzahl (Also z.B. 2 Groß, 2 Klein)
  - [x] Aufgabe 3 childParentDifference
    - Durch einen Baum gehen und zählen wie oft Kinder einen anderen Wert als Elternknoten hatten (Rekursiv)
  - [ ] Aufgabe 4 
    - Zwei Strings gegeben. Wenn der zweite im ersten vorhanden ist, Index zurückgeben. "?" ist Wildcard(Zählt also immer als entsprechender Buchstabe)

- [ ] Klausur 4

  - [x] 1. Aufgabe: countString

    - implementieren Sie die Funktion
      "int count_target_string(char *text, char *string)", die zählt, wie oft "string"
      in "text" vorkommt. Es darf nur gezählt werden, wenn "string" von Leerzeichen
      umschlossen wird bzw. wenn es am Ende / am Anfang steht. Gehen Sie davon aus,
      dass nur Kleinbuchstaben und Leerzeichen vorkommen. Sie dürfen nur selbst
      programmierte Hilfsfunktionen und strlen() und strncmp() verwenden.
      Beispiele (Testfälle waren in der .c-Datei bereits programmiert):
      count_target_string("abc of", "of") -> 1
      count_target_string("abcof", "of") -> 0
      count_target_string("ofabc", "of") -> 0
      count_target_string("of abc", "of") -> 1
      count_target_string("abc of abc of", "of") -> 2

  - [ ] 2. Aufgabe: intersperseList

    - implementieren Sie eine Funktion
      "IntList* intersperse(IntList *list, int x)", die zwischen die Listenelemente
      den übergebenen Wert x einfügt. Die Funktion soll dabei die Ursprungsliste nicht
      verändern, sondern einen Zeiger auf die veränderte Kopie zurückgeben. Diese muss
      dynamisch allokiert werden - [ ] dies konnte man mit einer node()-Funktion bspw.
      erledigen, die bereits in der .c-Datei vorhanden war.
      Beispiele (Testfälle waren wieder vorgegeben):
      intersperse([1, 2, 3], -3) = [1, -3, 2, -3, 3]
      intersperse([1, 2], -3) = [1, -3, 2]
      Wichtigster Testfall war noch:
      intersperse([ ], -3) = [ ]
      Je nach Implementation konnte vorkommen, dass ihr im letzten Testfall statt "[ ]"
      "[0]" erhaltet. Lösung: man musste für den Fall, dass die übergebene IntList
      NULL ist, NULL zurückgeben.

  - [x] 3. Aufgabe: treeLevel

    - [x] Implementieren Sie die Funktion "int levels(Tree \*tree)", die zurückgibt, wie
          hoch ein Baum ist. Dabei hat ein leerer Baum (tree == NULL) die Höhe 0, ein Baum
          ohne Nachfolger (tree->left == NULL && tree->right == NULL) die Höhe 1 usw.
          Die Implementierung sollte auch für asymmetrische Bäume gelten. Wenn ich mich
          richtig erinnere, gab es keine min/max stack/queue Hilfsfunktionen - [ ] die musste
          man ggf. selbst implementieren.
    - [x] (Nicht mehr ganz sicher, ungefähr so): implementieren Sie eine Funktion
          "void count_leaves_per_level(Tree *tree, int level, int *results)", die die
          Anzahl an Blättern einer n-ten Ebene zählt und diesen Wert dann in das n-te
          Element des übergebenen results-Arrays schreibt. Als Blatt zählen Knoten, die
          keine Nachfolger haben.
          In den Testfällen gab es symmetrische, asymmetrische und leere Bäume.

  - [x] 4. Aufgabe: polynoms
    - (Original-Formulierung war sehr kompliziert und abschreckend,
      sinngemäß war folgendes gefordert): implementieren Sie die Funktion
      "void derive*polynoms(int *polynoms, int _results)", die Ableitung der Polynome
      aus dem polynoms-Array in das results-Array schreibt.
      Hört sich erstmal schrecklich kompliziert anschauen wir uns an, was die
      eigentlich von uns wollen: ein Array { 1, 2, 3 } bspw. soll "übersetzt" bedeuten
      f(x) = 1 _ x⁰ + 2 _ x¹ + 3 _ x². Leitet man das ab, erhält man
      f'(x) = 2 \_ x⁰ + 6 \* x¹. Das results-Array soll also für results[0] die 2
      enthalten und für results[1] die 6. Angegeben waren noch weitere Testfälle, die
      allesamt aber ähnlich waren. Kann mich an keinen "komplizierten" Testfall
      erinnern. Im Endeffekt war das ein 3-Zeiler - [ ] wenn man sich von der
      zunächst kompliziert erscheinenden Aufgabenstellung nicht abschrecken ließ.
      Zusatzbemerkungen: als Editor musste kWrite eingesetzt werden. Als Desktop-
      Umgebung wurde GNOME 3 (Linux) verwendet. Die Kompilierung erfolgte mittels
      Makefiles. Die gesamte Klausur war lösbar, ohne dass man selbst irgendeine
      prog1lib-Funktion verwenden musste.

- [x] Klausur 5

  - [x] Aufgabe 1 rot3 --> siehe 7.1
    - Verschlüsselung von Buchstaben in einem String (Caesar Alg). Alle Kleinbuchstaben(!) sollten um 5 chars verschoben werden (War so ziemlich das gleiche wie in Assignment 6 glaube ich)
      Nur s_length/xmalloc/strlen
  - [x] Aufgabe 2
    - Summe in einem Tree bilden. Es dürfen nur alle Knoten gerechnet werden die mindestens einen Nachfolger haben (Wenn z.B. t->right noch mind. einen Nachfolger ungleich NULL hat -> mitrechnen
  - [x] Aufgabe 3 trimString
    - Leerzeichen am Anfang/Ende eines Strings entfernen. Es darf nur s_length/xmalloc/strlen verwendet werden aus der prog1lib (Also kein s_trim)

- [ ] Klausur 6

  - [ ] Aufgabe 1 bees
    - Population einer Bienenkollonie auszählen.
      Die Königin legt mit einer bestimmten Formel die Eier pro Tag in Abhängigkeit von der Tagestemperatur.
      Nach 21 Tagen schlüfen die Eier und nach 6 Wochen sterben die Bienen ab.
      Rein geht ein Array mit den Temperaturen, die Länge des Arrays un der Tag der Auszählung.
  - [x] Aufgabe 2 sortedInString
        at_least_four_sorted_digits (Siehe Assignment 14), wobei is_digit vorgegeben war
  - [x] Aufgabe 3 mergeLists
    - Zwei listen Mergen
  - [x] Aufgabe 4 sortTree
    - Binärbaum geordnet ausgeben. Also erst den Linken dann den Rechten Teil -->inOrderPrint.

- [ ] Klausur 7

  - [x] Aufgabe 1 rot3
    - String mit ROT 3 verschlüsseln
  - [ ] Aufgabe 2 arrayAnalyser
    - In einem 2 dimensionales char Array feststellen wie oft ein char in einer Spalte vorkommt und in ein neues 1dim array schreiben

- [x] Klausur 8

  - [x] Aufgabe 1 intToList
    - Int wird vorgeben und jede Dezimalziffer soll in eine Liste übergeben werden

- [x] Klausur 9

  - [x] Aufgabe 1 nodeDifference
    - Differenz zwischen dem minimalen und dem maximalem Element in einer Liste von INT berechnen
  - [x] Aufgabe 2 sameParentChildValue
    - Anzahl der Knoten in einem Baum die den selben Wert wie ihre Eltern haben

- [x] Klausur 10

  - [x] Aufgabe 1 removeEmptySpace
    - Entferne von einem String alle Leerzeichen am Anfang (Siehe oben)

- [x] Klausur 11

  - [x] Aufgabe 1 intToList
    - Binary List machen aus gegebenem integervalue
  - [x] Aufgabe 2 greatestPathValue
    - Aus einem Tree den Pfad mit dem größten Wert ausgeben
  - [x] Aufgabe 3 listFunctions
    - Aus einer Liste letztes Element, list Size herausfinden und Append List funktion schreiben
  - [x] Aufgabe 4 shortestOrder
    - Aus einem String die Länge der kürzesten Folge des Char c finden. Dazu noch Funktion schreiben die herausfindet ob der String mit einer Ziffer beginnt.

- [ ] Klausur 12

  - [x] Aufgabe 1 printStrings
    - Es sind 2 Strings gegeben, wenn der eine in dem anderen vorkommt, soll der String nach dem anderen String ausgegeben werden, sonst der ursprüngliche String. Mit allokieren
  - [x] Aufgabe 2 maxOneChar
    - Prüfen ob String mit : anfängt oder aufhört, maximal 1x: hat, sonst nur aus kleinen Buchstaben besteht und mindestens einen kleinen Buchstaben hat
  - [ ] Aufgabe 3 centerOrZero
    - Center or Zero (Assignment 14)

* [x] Klausur 13

  - [x] Aufgabe 1 pushPop
    - 4 Stack Funktionen wie Push/Pop implementieren
  - [x] Aufgabe 2 lowLevelLeaf
    - Das Leaf mit dem niedrigsten Level in einer Baumstruktur berechnen
  - [x] Aufgabe 3 slashRemover
    - Für _buchstabe neuen String allokieren und "_" entfernen und den ersten Buchstaben nach "\_" groß Schreiben.
