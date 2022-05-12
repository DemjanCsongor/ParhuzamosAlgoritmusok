A program a Lagrange féle interpolációs képlettel számol.
Az interpoláció az új adatpontok megtalálásának módszere, 
az ismert adatpontok diszkrét halmazának tartományában.
Más szavakkal, az interpoláció a matematikai függvény értékének becslésére szolgló technika, 
a független változó bármely köztes értékére.

Mérés:

A szekvenciális program számitási ideje: 21.0085 milliszekundum.

Paralelizált:

Threadek száma:  Futás ideje milliszekundumban:
2 szállal: 161, 
3 szállal: 140,
4 szállal: 124,
5 szállal: 115,
6 szállal: 112,
7 szállal: 119,
8 szállal: 127,

A mérésből jól látható, hogy a futásidő fokozatosan csökken a szálak hozzáadásával, 
majd elkezd növekedni. Ez annak tudható be, hogy amikor szálakkal dolgozunk, 
hívásukra, használatukra is időt kell szánni. Ha növeljük a szálak számát, 
az akár a teljesítmény rovására is mehet.

"LagrangeInterpolacio" nevet kapta az a mappa, amiben a párhuzamosított program szerepel.
"LagrangeInterpolacio_seq" mappában a szekvenciális program található.
