/*Q9.Write a C program to implement linked representation of a graph in memory using array
of pointers.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} node;
typedef struct list
{
    node *head;
} list;
typedef struct graph
{
    int v;
    list *array;
} graph;
node *new_node(int x)
{
    node *q = (node *)malloc(sizeof(node));
    q->info = x;
    q->next = NULL;
    return q;
}
graph *create_graph(int v)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->v = v;
    g->array = (list *)malloc(sizeof(list) * v);
    int i;
    for (i = 0; i < v; i++)
    {
        g->array[i].head = NULL;
    }
    return g;
}
void add_edge(graph *g, int s, int d)
{
    node *t = new_node(d);
    t->next = g->array[s].head;
    g->array[s].head = t;
}
void print_graph(graph *g)
{
    int i;

    for (i = 0; i < g->v; i++)
    {
        node *t = g->array[i].head;
        printf("\t%d", i);
        while (t != NULL)
        {
            printf("->%d", t->info);
            t = t->next;
        }
        printf("\n");
    }
}
int main()
{
    int v, ch, s, d;
    printf("\t\t******INPUT******\n");
    printf("\tENTER THE NO OF VERTICES : ");
    scanf("%d", &v);            // Taking no of vertex as input
    graph *g = create_graph(v); // Creating the Graph
    do
    {
        printf("\t1 - INSERT\n\t2 - DISPLAY\n\t");
        printf("ENTER THE CHOICE : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\tENTER THE SOURCE AND DESTINATION : ");
            scanf("%d%d", &s, &d);
            add_edge(g, s, d); // Adding edges to the graph
            break;
        case 2:
            printf("\t\t******OUTPUT******\n");
            printf("\tADJACENCY LIST REPRESENTATION OF GRAPH : \n");
            print_graph(g); // Printing the graph
            exit(0);
        }
    } while (1);
    return 0;
}