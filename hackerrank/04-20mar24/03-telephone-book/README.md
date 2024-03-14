# Perché i due file

L'unica differenza che hanno i due file è il modo in cui ordinano i contatti nella rubrica.


La soluzione più semplice è quella di utilizzare una struttra dati ordinata, come `std::map`.

Ma la soluzione che ho voluto implementare consiste nell'utilizzare il bubble sort per ordinare il vettore di Contact in ordine lessicografico con l'utilizzo di una funzione accessoria, `order_swap_strings`.

Entrambe le soluzioni passano tutti i test ma preferisco la soluzione home-made dell'ordinamento bubble sort.
