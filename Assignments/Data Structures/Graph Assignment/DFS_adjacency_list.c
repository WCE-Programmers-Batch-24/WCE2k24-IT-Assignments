#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct QNode
{

    void *data;

    struct QNode *next;

} QNode;

typedef struct
{

    QNode *front;

    QNode *rear;

} Queue;

void enqueue(Queue *q, void *data)

{

    QNode *temp = (QNode *)malloc(sizeof(QNode));

    if (!temp)
    {

        printf("Queue is Full\n");

        return;
    }

    temp->data = data;

    temp->next = NULL;

    if (!q->front)
    {

        // Empty Q

        q->front = q->rear = temp;
    }
    else
    {

        q->rear->next = temp;

        q->rear = temp;
    }
}

void *dequeue(Queue *q)

{

    void *data = NULL;

    QNode *temp = NULL;

    if (q->front)
    {

        temp = q->front;

        q->front = q->front->next;

        data = temp->data;

        free(temp);

        temp = NULL;
    }
    else
    {

        printf("Queue is Empty\n");
    }

    return data;
}

int isEmpty(Queue *q)

{

    if (!q->front)
        return 1;

    else
        return 0;
}

/* Graph Data structure */

typedef struct Vertex
{

    int vertex;

    int weight;

    struct Vertex *next;

} Vertex;

typedef struct
{

    int no_of_nodes;

    Vertex **List;

} Graph;

int search_graph[][6] = {

    {0, 1, 1, 0, 0, 0},

    {1, 0, 0, 1, 0, 0},

    {1, 0, 0, 1, 0, 0},

    {0, 1, 1, 0, 1, 1},

    {0, 0, 0, 1, 0, 0},

    {0, 0, 0, 1, 0, 0}

};

Graph *createGraph(int nodes)

{

    int i = 0;

    int edges;

    Vertex *v = NULL;

    Vertex *lastv = NULL;

    Graph *G = (Graph *)malloc(sizeof(Graph));

    if (G && nodes > 0)

    {

        G->no_of_nodes = 0;

        G->List = (Vertex **)malloc(sizeof(Vertex *) * nodes);

        if (G->List)
        {

            for (i = 0; i < nodes; i++)
            {

                G->List[i] = NULL;

                ++G->no_of_nodes;

                for (edges = 0; edges < nodes; edges++)
                {

                    if (!search_graph[i][edges])
                        continue;

                    v = (Vertex *)malloc(sizeof(Vertex));

                    if (!v)
                        return NULL;

                    v->vertex = edges;
                    v->weight = 0;
                    v->next = NULL;

                    if (!G->List[i])
                        G->List[i] = v;

                    else
                        lastv->next = v;

                    lastv = v;
                }
            }
        }
    }

    return G;
}

void displayGraph(Graph *G)

{

    int node;

    Vertex *v = NULL;

    if (!G || G->no_of_nodes <= 0)
        return;

    for (node = 0; node < G->no_of_nodes; ++node)
    {

        printf("\n Node(%d) \n", node);

        if (G->List[node])
        {

            v = G->List[node];

            while (v)
            {

                printf("Vertex = %d (%d)", v->vertex, v->weight);

                v = v->next;

                if (v)
                    printf(" -> ");
            }

            v = NULL;
        }
    }
}

void DFS(Graph *G, int node)

{

    Vertex *v = NULL;

    //static int visited[6] = {0};

    static int *visited = NULL;

    if (!visited)
    {

        visited = (int *)malloc(sizeof(int) * G->no_of_nodes);

        memset(visited, 0, sizeof(int) * G->no_of_nodes);
    }

    if (!G || !G->List)
        return;

    printf(" %d ", node);

    ++visited[node];

    v = G->List[node];

    while (v)
    {

        if (!visited[v->vertex])

            DFS(G, v->vertex);

        v = v->next;
    }
}



int main()

{

    Graph *G = NULL;

    int nodes = 6;

    if (nodes > 0)
    {

        G = createGraph(nodes);

        // displayGraph(G);

        printf("\nTransversal: ");
        DFS(G, 3);

    
    }

    return 0;
}