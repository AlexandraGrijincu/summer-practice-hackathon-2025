#include <stdio.h>
#include <stdlib.h>
/**(S2) Se da o matrice a[1 . . . n][1 . . . m] cu elemente numere intregi.
(a) Definiti o functie care afiseaza matrice a.
(b) Definiti o functie care returneaza numarul de coloane ale matricii cale contin doar elemente pare.
(c) Definiti o functie care inmulteste o matrice cu un vector.**/

/**
-functia afisare afiseaza matricea a, unde
-n reprezinta numarul de linii din matricea a, iar
-m reprezinta numarul de coloane din matricea a
-aceasta matrice este afisata linie cu linie
**/
void afisare(int a[100][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
/**
-functia returnare returneaza numarul de coloane ale matricii care contin doar elemente pare
-n reprezinta numarul de linii, iar
-m reprezinta numarul de coloane
-k creste atunci cand pe o coloana se afla un element impar
-nr creste atunci cand pe o coloana sunt doar elemente pare
-daca k ramane 0, atunci pe coloana sunt doar elemente pare, deci creste nr
**/
int returnare(int a[100][100], int n, int m)
{
    int nr = 0;
    for (int j = 0; j < m; j++)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
            if (a[i][j] % 2 != 0)
                k++;
        if (k == 0)
            nr++;
    }
    return nr;
}
/**
-functia inmultire afiseaza inmultirea matricei a cu vectorul v
-pentru a realiza aceasta inmultire avem nevoie de inca un vector, b, caruia ii punem toate elementele pe 0
-pentru ca aceasta functie sa calculeze inmultirea corect, este obligatoriu ca dimensiunea vectorului v sa fie egala cu numarul 
de linii al matricei a
-deci l este dimensiunea vectorului v, astfel ca la inceput verificam daca l este diferit de n(nr de linii din matrice), iar daca 
este diferit, afisam mesajul:"Nu se poate efectua inmultirea" si iesim din functia inmultire
**/
void inmultire(int a[100][100], int n, int m, int v[100], int l, int b[100])
{
    if (n != l)
    {
        printf("Nu se poate efectua inmultirea");
        return;
    }
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i] += a[i][j] * v[i];
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
}
/**
-in functia main citim n(nr de linii din a),m(nr de coloane din a),l(dimensiunea lui v),matricea a, 
iar mai apoi vectorul v 
-in continuare, in functia main vom apela functia afisare, vom afisa apeland functia returnare si vom apela functia inmultire
**/
int main()
{
    int a[100][100], n, m, v[100], b[100], l;
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &v[i]);
    }
    afisare(a, n, m);
    printf("%d\n", returnare(a, n, m));
    inmultire(a, n, m, v, l, b);
    return 0;
}
