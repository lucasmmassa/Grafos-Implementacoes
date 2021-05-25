FOO = $PATH
	
prim:
	g++ prim.cpp -o prim
	@echo "Algoritmo de Prim compilado."

kruskal:
	g++ kruskal.cpp -o kruskal 
	@echo "Algoritmo de Kruskal compilado."
	
dijkstra:
	g++ dijkstra.cpp -o dijkstra
	@echo "Algoritmo de Dijkstra compilado."

ff:
	g++ ford_fulkerson.cpp -o ford_fulkerson
	@echo "Algoritmo de Ford-Fulkerson compilado."	