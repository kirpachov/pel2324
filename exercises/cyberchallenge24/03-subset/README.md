# Subset

La descrizione del problema è disponibile nel file [2024-subset.pdf](./2024-subset.pdf).

La soluzione iniziale ( [subset-slow0.cpp](subset-slow0.cpp) ) nonostante corretta era
troppo poco efficace e per questo non aveva modo di
completare nel tempo limite nel caso di input importanti.

Nemmeno dopo svariate ottimizzazioni è stato possibile compltare
l'esecuzione in tempi ragionevoli.

Nella soluzione proposta, invece, anche in ruby il file di
input più importante impiega meno di un secondo per il completamento.

La soluzione finale impiega 3 secondi per eseguire e verificare
<b>tutti</b> gli input-output presenti nelle cartelle /input e /output.

## Spiegazione soluzione
La soluzione si basa su alcuni principi.
- Il vettore <b>deve</b> necessariamente essere ordinato. 
Questa è l'ottimizzazione più importante.
- In un vettore ordinato, i subset validi
(valido significa che prendendo due elementi qualsiasi
dello stesso subset la loro differenza in valore
assoluto è sempre <= treshold fornita dall'utente)
possono essere creati solo in due modi: andando da sinistra
verso destra e creando dei subset validi a partire da un certo
elemento fino a quanto più possibile, quindi
fino a quando si resta all'interno del treshold.
Stessa cosa al contrario, dalla fine verso l'inizio.
In questo modo abbiamo creato una mappatura dei possibili set.

Soddisfatti questi principi si possono trovare
i possibili set (inizio => fine) e (fine <= inizio)
e trovare quel punto in cui:
- A sinistra avremo il subset (inizio => fine)
- E a destra di quel punto avremo il subset (fine <= inizio)

Una spiegazione più coincisa è disponibile nel file [2024-programmig.pdf](../2024-programming.pdf)

La soluzione proposta dal sito ufficiale è disponibile nel file [solution.cpp](./solution.cpp)