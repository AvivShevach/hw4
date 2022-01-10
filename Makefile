all: graph

graph: main.o nodes.o edges.o algo.o 
	gcc -g -Wall main.o nodes.o edges.o algo.o -o hw4

clean:
	rm *.o hw4

.c.o:
	gcc -c -Wall $<
