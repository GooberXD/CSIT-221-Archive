// Implement the Graph ADT using Adjacency Matrix. 
// The vertices are represented as characters and the edges are represented as integers.

// •insertVertex(x): Creates a new Vertex storing element x.

// •insertEdge(u, v, x): Creates a new Edge from vertex u to vertex v, storing element x; 
// print "Not Null" if there already exists an edge from u to v.

// •int numVertices( ): Returns the number of vertices of the graph.

// •char* vertices( ): Returns a character array (via character pointer) to 
// all the vertices of the graph (arranged in the order of how they are added).

// •int numEdges( ): Returns the number of edges of the graph.

// •int* edges( ): Returns an integer array (via integer pointer) of all
// the edges of the graph (arranged in the order of how they are added).

// •int getEdge(u, v): Returns the edge from vertex u to vertex v, if one exists; 
// otherwise return 0.

// •char* endVertices(e): Returns a character array (via character pointer) containing the 
// two endpoint vertices of edge e. Since the graph is directed, 
// the first vertex is the origin and the second is the destination. 
// If edge does not exist, return "-" as both origin and destination.

// •char opposite(v, e): For edge e incident to vertex v, 
// returns the other vertex of the edge; returns "-" if e is not incident to v.

// •int outDegree(v): Returns the number of outgoing edges from vertex v.

// •int inDegree(v): Returns the number of incoming edges to vertex v. 
// For an undirected graph, this returns the same value as does outDegree(v).

// •int* outgoingEdges(v): Returns an integer array (via integer pointer) of all 
// outgoing edges from vertex v. This will be arranged in such a way that outgoing 
// edges towards vertices that were added first will be listed first as well.

// •int* incomingEdges(v): Returns an integer array (via integer pointer) of 
// all incoming edges to vertex v. This will be arranged in such a way that 
// incoming edges from vertices that were added first will be listed first as well.

// •int removeVertex(v): Removes vertex v and all its incident edges from the graph. 
// This will return the number of edges that were also removed in the process.

// •bool removeEdge(e): Removes edge e from the graph. Returns true when able to remove e.

#include <iostream>
#include "graphmatrix.hpp"
using namespace std;

int main(void) {
    char op, v, x;
    char orig, dest;
    int e;

    int num, i;
    char* verts;
    int* edges;
    Graph* graph = new GraphMatrix();
    do {
        cout << "Operation: ";
        cin >> op;
        switch (op) {
            case 'v':
                cin >> v;
                graph->insertVertex(v);
                break;
            case 'e':
                cin >> orig;
                cin >> dest;
                cin >> e;
                graph->insertEdge(orig, dest, e);
                break;
            case 'q':
                cout << graph->numVertices() << endl;
                break;
            case 'w':
                cout << graph->numEdges() << endl;
                break;
            case 'V':
                verts = graph->vertices();
                num = graph->numVertices();
                cout << "List of Vertices: ";
                for (int i = 0; i < num; i++) {
                    cout << verts[i];
                    if (i < num-1) {
                        cout << ", ";
                    }
                }
                cout << endl;
                break;
            case 'E':
                edges = graph->edges();
                num = graph->numEdges();
                cout << "List of Edges: ";
                for (i = 0; i < num; i++) {
                    cout << edges[i];
                    if (i < num-1) {
                        cout << ", ";
                    }
                }
                cout << endl;
                break;
            case 'g':
                cin >> orig;
                cin >> dest;
                cout << graph->getEdge(orig, dest) << endl;
                break;
            case 'n':
                cin >> e;
                verts = graph->endVertices(e);
                cout << "Origin: " << verts[0] << " | Destination: " << verts[1] << endl;
                break;
            case 'l':
                cin >> v;
                cin >> e;
                cout << graph->opposite(v, e) << endl;
                break;
            case 'o':
                cin >> orig;
                cout << graph->outDegree(orig) << endl;
                break;
            case 'i':
                cin >> dest;
                cout << graph->inDegree(dest) << endl;
                break;
            case 'O':
                cin >> orig;
                edges = graph->outgoingEdges(orig);
                num = graph->outDegree(orig);
                cout << "List of Outgoing Edges from " << orig << ": ";
                for (i = 0; i < num; i++) {
                    cout << edges[i];
                    if (i < num-1) {
                        cout << ", ";
                    }
                }
                cout << endl;
                break;
            case 'I':
                cin >> dest;
                edges = graph->incomingEdges(dest);
                num = graph->inDegree(dest);
                cout << "List of Incoming Edges to " << dest << ": ";
                for (i = 0; i < num; i++) {
                    cout << edges[i];
                    if (i < num-1) {
                        cout << ", ";
                    }
                }
                cout << endl;
                break;
            case 'r':
                cin >> e;
                cout << graph->removeEdge(e) << endl;
                break;
            case 'R':
                cin >> v;
                cout << graph->removeVertex(v) << endl;
                break;
            case 'p':
                graph->print();
                break;
            case 'x':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid operation";
        }
    } while (op != 'x');

    return 0;
}