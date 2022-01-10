#include "graph.h"

int *path_nodes;
char s[3000];

int main()
{
    char *token;
    pnode head = NULL;
    fgets(s, 3000, stdin);
   // printf("The input is: %s\n", s);
    char *rest = s;
    pnode src, dest, tmp;
    int ind;
    
    //token = strtok_r(rest," ",&rest);
    token = strtok( rest, " ");
   // fprintf(stderr, "token=%s\n", token);
  //  char c = getchar();
  while (token != NULL)
  {
    if(*token=='A')
    {
        while (head != NULL)
            delete_node_cmd(&head, head->node_num);
        // printf("Complete graph\n");
        // printGraph_cmd(head);
        token = strtok(NULL, " ");
        ind = atoi(token);//int)s[k++]-'0';
        for(int i = 0; i < ind; i++)
        {
            tmp = create_node(i);
            insert_node_cmd(&head, tmp);
        }
        token = strtok(NULL, " ");
        while(token  != NULL && *token == 'n')
        { 
            token = strtok(NULL, " ");
            ind = atoi(token);
            src =find_node(head, ind);
            token = strtok(NULL, " ");
            while(token  != NULL && *token <= '9' && *token >= '0') //&& strlen(token) == strlen(itoa(atoi(token))))
            {
                ind = atoi(token);
                dest =find_node(head, ind);
                token = strtok(NULL, " ");
                ind = atoi(token);
                create_edge(src, dest, ind);
                token = strtok(NULL, " ");
            }
        }
    }
    // printf("Complete graph\n");
    // printGraph_cmd(head);
    if(token != NULL && *token=='D')
    {
        token = strtok(NULL, " ");
        ind = atoi(token);
        delete_node_cmd(&head, ind);
        token = strtok(NULL, " ");
    }
 //   printf("Delete node id = %d\n", ind);
 //   printGraph_cmd(head);
 //   token = strtok(NULL, " ");
    if(token != NULL && *token=='B')
    {
        token = strtok(NULL, " ");
        ind = atoi(token);
        src = create_node(ind);
        if(find_node(head, ind))
            delete_node_cmd(&head, ind);
        insert_node_cmd(&head, src);
        token = strtok(NULL, " ");
        while(token  != NULL && *token <= '9' && *token >= '0')
        {
            ind = atoi(token);
            dest = find_node(head, ind);
            token = strtok(NULL, " ");
            ind = atoi(token);
            create_edge(src, dest, ind);
            token = strtok(NULL, " ");
        }
    //    printf("After inserting node id = %d\n",ind);
    }
    
 //   printGraph_cmd(head);
    if(token != NULL && *token=='S')
    {
        token = strtok(NULL, " ");
        ind = atoi(token);
        src = find_node(head, ind);
        infinity(head, ind);
        shortsPath_cmd(head, src);
        token = strtok(NULL, " ");
        ind = atoi(token);
        dest = find_node(head, ind);
        printf("Dijsktra shortest path: %d \n", dest->weight);
        token = strtok(NULL, " ");
    }
    if(token != NULL && *token=='T')
    {
        token = strtok(NULL, " ");
        ind = atoi(token);
        path_nodes = (int *)malloc( ind * sizeof(int));
        for( int i =0; i < ind; i++)
            path_nodes[i] = atoi(strtok(NULL, " "));
        short_path(head, path_nodes, ind);
        token = strtok(NULL, " ");
        free(path_nodes);
    }
    
  }

  while (head != NULL)
        delete_node_cmd(&head, head->node_num); 
}