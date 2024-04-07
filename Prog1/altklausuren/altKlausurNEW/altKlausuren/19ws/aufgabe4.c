// a.) #########################
// Implementieren Sie die Funktion void matrix max(int* a, int rows, int cols, int* mval, int* mrow, int* mcol).
// Diese hat als Eingabeparameter ein 2-dimensionales int-Array a mit rows Zeilen und cols Spalten.
// (C speichert zweidimensionale Arrays zeilenweise.)
// Die Funktion setzt die Ausgabeparameter mval, mrow und mcol auf den Wert und die Position eines Elements im Eingabearray mit maximalem Wert.
// Sollte a leer sein, wird keiner der Ausgabeparameter gesetzt.
// In matrix_max durfen keine Funktionen aufgerufen werden
#include "base.h"
void matrix_max(int *a, int rows, int cols, int *mval, int *mrow, int *mcol)
{
    *mval = 0;

    for (int i = 0; i < rows; i++)
    {
        int *z = a + i * cols;
        for (int j = 0; j < cols; j++)
        {
            if (*mval < *(z + j))
            {
                *mval = *(z + j);
                *mrow = i;
                *mcol = j;
            }
            printf("%d ,", *(z + j));
        }
        printf("\n");
    }
    printf("---------------\n");
}
void test(void)
{
    int m, r, c;
    int a[3][3] = {
        {1, -1, 3},
        {2, -2, 5},
        {3, -3, 4},
    };
    matrix_max((int *)a, 3, 3, &m, &r, &c);
    // m: 5, r: 1, c: 2
    printf("max value: %d, rows: %d, cols: %d\n", m, r, c);

    int b[2][3] = {
        {1, -1, 3},
        {7, -2, 5},
    };
    matrix_max((int *)b, 2, 3, &m, &r, &c);
    // m: 7, r: 1, c: 0
    printf("max value: %d, rows: %d, cols: %d\n", m, r, c);

    int b2[2][3] = {
        {1, -1, 3},
        {7, -2, 7},
    };
    matrix_max((int *)b2, 2, 3, &m, &r, &c);
    // m: 7, r: 1, c: 0
    // oder
    // m: 7, r: 1, c: 2
    printf("max value: %d, rows: %d, cols: %d\n", m, r, c);
}
int main(void)
{
    test();
    return 0;
}

// b.) #########################
// Erlautern Sie kurz, welches Problem mit der case-Anweisung in C verbunden ist.
// wenn break vergessen wird, wird das nächste case ausgeführt.