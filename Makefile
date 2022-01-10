all: graph

graph: main.o nodes.o edges.o algo.o 
	gcc -g -Wall main.o nodes.o edges.o algo.o -o graph

clean:
	rm *.o graph

.c.o:
	gcc -c -Wall $<
