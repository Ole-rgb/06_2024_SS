Aufgabe 1: ßtoDoubleS
ss in einem String mit ß ersetzen. 
const String sz = „ß“ war gegeben. 
Anmerkung in der Aufgabe: strlen(ß) = 2. 

Aufgabe 2: nodes_equal_to_parent (Aus Assignment14)

Aufgabe 3: int_to_binary_list
Bsp:
65 -> [1, 0, 0, 0, 0, 0, 1]
0 -> [0]
10 -> [1, 0, 1, 0]

Aufgabe 4: intOption
Struktur zurückgeben die den kleinsten Wert aus dem Intervall enthält. 

In einem Intervall [from, to] den kleinsten Integer Wert finden für den i == 3 ist 
oder (je nach Angabe f oder g im Testfall) i >= 1000 und zurückgeben.
Gegeben waren in den Testfällen (P p, int from, int to), wobei p f oder b war. 
from = Untere Grenze des Intervalls, to = obere Grenze des Intervalls. 
Einmal von from bis to durchlaufen und falls p == f ist, sollte als IntOption op = {true, i) wenn f(i) == 3 ist zurückgegeben werden, falls p == f  und g(i) >= 1000 sollte IntOption op = {true, i) zurückgegeben werden. 
Falls keine Zahl gefunden werden konnte sollte {false, 0} zurückgegeben werden.

Bsp Testfall:
(f, 0, 4) liefert {true, 3}
(f, 10, 20) liefert {false, 0}
(g, 999, 10000) liefert {true, 1000}