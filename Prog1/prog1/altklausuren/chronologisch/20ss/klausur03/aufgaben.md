1. stringToKeyValueList

   Aus String apple:3,stuff:2;...,.. key value Liste erzeugen, also erster Eintrag in der Liste wäre (apple,3) usw. strchr(), xmalloc(), strlen() usw nutzbar.
2. decimalList

   gegebene nicht negative Zahl zerlegen und in Liste speichern, also 1234 -> 1-2-3-4
3. stringTree

   Baum mit Buchstaben gegeben, daraus String erzeugen mit s_cat() mit folgendem Format: left->value + ' ' + node->value + ' ' + right->value. Mit allokieren 
4. camelcaseToUnderscore

   String in camelCase gegeben, umwandeln zu underscore Schreibweise --> helloWorld --> hello_*world, ABC DE --> A_b_c D_e, return String neu allokieren usw, exakte Stringlänge allokieren*