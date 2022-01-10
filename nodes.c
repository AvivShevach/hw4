#include "graph.h"

pnode create_node(int id)
{
    pnode n = (pnode)malloc(sizeof(node));
    n->node_num = id;
    n->next = NULL;
    n->edges = NULL;
    // n->use = 0;
    // n->weight = 0;
    return n;
}
pnode find_node(pnode head, int id)
{
    if (head == NULL)
         return NULL;
    pnode tmp = head;
    while (tmp != NULL)
    {
        if(tmp->node_num == id)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
void insert_node_cmd(pnode *head, pnode n)
{
    if (*head == NULL)
    {
         *head = n;
         return;
    }
    pnode tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
        
}

void delete_all_edges( pedge edge )
{
    pedge etmp;
    while (edge)
    {
        etmp=edge;
        edge = edge->next;
        free(etmp);
    } 
}

void delete_node_cmd(pnode *head, int ind)
{
    if(!head)
        return;
    delete_out_edges(*head, ind);
    // printf("After deleting all edge toward %d\n", ind);
    // printGraph_cmd(*head);
    pnode tmp = *head;
    if ((*head)->node_num == ind)
    {
        delete_all_edges(tmp->edges);
        tmp->edges = NULL;
        // printf("After deleting all edges of node %d\n", ind);
        // printGraph_cmd(*head);
        *head = (*head)->next;
        free(tmp);
        return;
    }
    while (tmp->next && (tmp)->next->node_num != ind)
        tmp = tmp->next;
    if(!(tmp->next))
        return;
    delete_all_edges(tmp->next->edges);
    tmp->next->edges = NULL;
    // printf("After deleting all edges of node %d\n", tmp->next->node_num);
    // printGraph_cmd(*head);
    pnode tmp2 = tmp->next;
    tmp->next = tmp2->next;
    free(tmp2);  
}

void delete_out_edges(pnode head, int ind)
{
    pnode tmp = head;
    while (tmp != NULL)
    {
        delete_edge(&tmp->edges, ind);
        tmp = tmp->next;
    }
}
void delete_edge(pedge *head, int ind)
    {
        if(*head == NULL)
          return;
        pedge tmp = *head;
        if ((*head)->endpoint->node_num == ind)
        {
            *head = (*head)->next;
            free(tmp);
            return;
        }
        while ((tmp)->next && (tmp)->next->endpoint->node_num != ind)
            tmp = (tmp)->next;
        if(tmp->next==NULL)
            return;
        pedge tmp2 = (tmp)->next;
        (tmp)->next = (tmp2)->next;
        free(tmp2);
    }
void infinity(pnode head, int src)
{
    pnode tmp = head;
    while (tmp!= NULL)
    {
        tmp->use = 0;
        if (tmp->node_num != src)
            tmp->weight = -1;       
        else
            tmp->weight = 0;
        tmp = tmp->next;
    }
}