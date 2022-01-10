#include "graph.h"

void build_graph_cmd(pnode *head)
{

}


void printGraph_cmd(pnode head)
{
    pnode tmp = head;
    pedge tmp2;
    while (tmp != NULL)
    {
        tmp2 = tmp->edges;
        printf("node: %d ", tmp->node_num);
        while (tmp2 != NULL)
        {
            printf("edge: %d weight: %d ", tmp2->endpoint->node_num, tmp2->weight);
            tmp2 = tmp2->next; 
        }
        printf("\n");
        tmp = tmp->next;        
    }
    printf("\n");
} 
void deleteGraph_cmd(pnode* head)
{

}

void shortsPath_cmd_helper(pnode src)
   {
//     if(src == NULL)
//         return NULL;
//    // if(src->use)

    pedge etmp = src->edges;
    pnode n;// = src->edges->endpoint;
//     pnode min_weight = NULL;//etmp->endpoint;
    while(etmp!= NULL)
    {
        n = etmp->endpoint;
        if(n->use)
        {
            etmp = etmp->next;
            continue;
        }
        if(n->weight == -1)
            n->weight = etmp->weight + src->weight;
        else if ( etmp->weight +src->weight < n->weight)
            n->weight = etmp->weight + src->weight;
        etmp = etmp->next;
    }
    src->use=1;
   // return min_weight;
}


pnode find_min_node_weight( pnode node )
{
    int weight = -1;
    pnode min_node = NULL;
    while( node != NULL )
    {
        if( node->use == 0 && node->weight != -1 )
        {
            if( weight == -1 )
            {
                weight = node->weight;
                min_node = node;
            }
            else if( weight > node->weight)
            {
                weight = node->weight;
                min_node = node;
            }
        }
        node = node->next;
    }    
    return min_node;
}

void shortsPath_cmd(pnode head, pnode src)
{
    while( src != NULL )
    {
        shortsPath_cmd_helper(src);
        src = find_min_node_weight(head);
    }
}

void TSP_cmd(pnode head)
{

}
int shortsPer(pnode head, pnode* arr,int size)
{
    int weight= 0;
    for(int i = 0; i<size-1; i++)
        {
            infinity(head, arr[i]->node_num);
            shortsPath_cmd(head, arr[i]);
            if (arr[i+1]->weight == -1)
                return -1;
            weight+= arr[i+1]->weight; 
        }
        return weight;
}

int short_dist_path = -1;

void permut( int current, int max, int n, int used[], pnode head, int *path_nodes)
{
    int i;
    if( n == 0)
    {
        int ind = current;
       // printf("%03d\n", current);
        
        pnode* arr = (pnode *)malloc( max * sizeof(pnode));
        for( i = max; i > 0; i-- )
        {
            arr[max-i] = find_node(head, path_nodes[ind%10-1]);
            ind = ind / 10;
        }
        int dist = shortsPer(head, arr, max);
        if( short_dist_path == -1 || ((dist != -1) && (dist < short_dist_path)))
            short_dist_path = dist;
        free( arr );
    }
    else
    {
        for(i=1; i<=max; i++)
        {
            if(!used[i])
            {
                used[i] = 1;
                permut(current * 10 + i, max, n-1, used, head, path_nodes);
                used[i] = 0;
            }
        }
    }
}

void short_path(pnode head, int *path_nodes, int count)
{
    int used[10] = {};
    permut( 0, count, count, used, head, path_nodes );
    printf( "TSP shortest path: %d \n", short_dist_path);
    short_dist_path = -1;
}
