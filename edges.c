#include "graph.h"

void create_edge(pnode src, pnode dest, int w)
{
    pedge e = (pedge)malloc(sizeof(edge));
    e->weight = w;
    e->endpoint = dest;
    e->next = NULL;
    if (src->edges == NULL)
    {
        src->edges = e;
        return;
    }
    pedge tmp = src->edges;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = e;
}