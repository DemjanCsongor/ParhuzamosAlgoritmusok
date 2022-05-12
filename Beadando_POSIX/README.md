Összefésülő rendezés

A program, 1 és 10000 közötti számokkal tölt fel egy 100000 hosszúságú tömböt, 
majd a tömbön összefésülő rendezést hajt végre.
A tömböt több kisebb tömbre bontja, majd miután ezeket rendezte, 
újra az ismert méretű tömböt tölti fel a számokkal, most növekvő sorrendben.

A programbeli kommentek részletes leítást nyujtanak a megvalósításról.

Mérés:

A szekvenciális program futásideje: 0.1280 sec.

A párhuzamosított program futásideje, a thread-ek novelése során:
2 szállal: 0.0120 sec.
3 szállal: 0.0100 sec.
4 szállal: 0.0090 sec.
5 szállal: 0.0080 sec.
6 szállal: 0.0080 sec.
7 szállal: 0.0070 sec.
8 szállal: 0.0080 sec.

A mérésből látható, hogy folyamatosan csökken a számítási idő, 
amíg túl sok szálat nem használunk a feladathoz.
Ha az adatokat bővítenénk, (pl: Ha a tömb méretét növelnénk.), 
ez a jelenség 8 szálnál nem még nem lenne látható, gyorsabb lenne a számítás. 
