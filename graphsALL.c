#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void displayGraph(struct Graph* graph) {
    printf("Graph Adjacency List:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void displayAdjacencyMatrix(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            int isEdge = 0;
            struct Node* current = graph->adjList[i];
            while (current != NULL) {
                if (current->data == j) {
                    isEdge = 1;
                    break;
                }
                current = current->next;
            }
            printf("%d ", isEdge);
        }
        printf("\n");
    }
}

int visited[100];

void dfs(struct Graph* graph, int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    struct Node* current = graph->adjList[vertex];
    while (current != NULL) {
        int neighbor = current->data;
        if (!visited[neighbor]) {
            dfs(graph, neighbor);
        }
        current = current->next;
    }
}

void bfs(struct Graph* graph, int startVertex) {
    int queue[100];
    int front = 0, rear = -1;
    int visited[100] = {0};

    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* current = graph->adjList[currentVertex];
        while (current != NULL) {
            int neighbor = current->data;
            if (!visited[neighbor]) {
                queue[++rear] = neighbor;
                visited[neighbor] = 1;
            }
            current = current->next;
        }
    }
}

int main() {
    int choice, numVertices, numEdges, src, dest, startVertex;
    struct Graph* graph = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a new graph\n");
        printf("2. Add an edge\n");
        printf("3. Display the graph (Adjacency List)\n");
        printf("4. Display the adjacency matrix\n");
        printf("5. Perform BFS\n");
        printf("6. Perform DFS\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (graph != NULL) {
                    free(graph->adjList);
                    free(graph);
                }
                printf("Enter the number of vertices: ");
                scanf("%d", &numVertices);
                graph = createGraph(numVertices);
                break;
            case 2:
                if (graph == NULL) {
                    printf("Please create a graph first.\n");
                } else {
                    printf("Enter edge (source and destination): ");
                    scanf("%d %d", &src, &dest);
                    addEdge(graph, src, dest);
                }
                break;
            case 3:
                if (graph == NULL) {
                    printf("Please create a graph first.\n");
                } else {
                    displayGraph(graph);
                }
                break;
            case 4:
                if (graph == NULL) {
                    printf("Please create a graph first.\n");
                } else {
                    displayAdjacencyMatrix(graph);
                }
                break;
            case 5:
                if (graph == NULL) {
                    printf("Please create a graph first.\n");
                } else {
                    printf("Enter the starting vertex for BFS: ");
                    scanf("%d", &startVertex);
                    printf("BFS Traversal: ");
                    bfs(graph, startVertex);
                    printf("\n");
                }
                break;
            case 6:
                if (graph == NULL) {
                    printf("Please create a graph first.\n");
                } else {
                    for (int i = 0; i < graph->numVertices; i++) {
                        visited[i] = 0;
                    }
                    printf("Enter the starting vertex for DFS: ");
                    scanf("%d", &startVertex);
                    printf("DFS Traversal: ");
                    dfs(graph, startVertex);
                    printf("\n");
                }
                break;
            case 7:
                if (graph != NULL) {
                    free(graph->adjList);
                    free(graph);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}