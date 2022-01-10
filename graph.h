#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "limits.h"

#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    int weight;
    int use;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

pnode create_node(int id);
pnode find_node(pnode head, int id);
void create_edge(pnode src, pnode dest, int w);
void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head,pnode n);
void delete_all_edges( pedge edge );
void delete_node_cmd(pnode *head, int ind);
void delete_out_edges(pnode head, int ind);
void delete_edge(pedge *head, int ind);
void printGraph_cmd(pnode head); 
void deleteGraph_cmd(pnode* head);
void infinity(pnode head, int src);
void shortsPath_cmd(pnode head, pnode src);
void shortsPath_cmd_helper(pnode src);
void TSP_cmd(pnode head);
void short_path(pnode head, int *path_nodes, int count);

#endif