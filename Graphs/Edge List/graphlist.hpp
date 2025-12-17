#include <cstdlib>
#include <iostream>
#include "graph.hpp"
#include "edge.hpp"
using namespace std;

class GraphList : public Graph {
    Edge** s_edges;
    int num_edge;
    char s_vertices[10];
    int num_vert;

    public:
    GraphList() {
        s_edges = (Edge**) malloc( 100 * sizeof(Edge*) );
        num_vert = 0;
        num_edge = 0;
    }

    int numVertices() {
        return num_vert;
    }

    char* vertices() {
        return s_vertices;
    }

    int numEdges() {
        return num_edge;
    }

    int* edges() {
        int* edgeArr = new int[num_edge];
        
        for(int i = 0; i < num_edge; i++){
            edgeArr[i] = s_edges[i]->getName();
        }
        return edgeArr;
    }

    int getEdge(char u, char v)  {
        
        int getEdgeInt = 0;
        
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->getOrigin() == u && s_edges[i]->getBigD() == v){
                getEdgeInt = s_edges[i]->getName();
            }
        }
        
        return getEdgeInt;
    }

    char* endVertices(int e)  {
        char* endVertArr = new char[1];
        
        int endVertChck = -1;
        
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->getName() == e){
                endVertArr[0] = s_edges[i]->getOrigin();
                endVertArr[1] = s_edges[i]->getBigD();
                endVertChck = 69;
            }
        }
        
        if(endVertChck == -1){
            endVertArr[0] = '-';
            endVertArr[1] = '-';
        }
        
        
        return endVertArr;
    }

    char opposite(char v, int e)  {
        
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->getName() == e){
                
                if(s_edges[i]->getOrigin() == v){
                    return s_edges[i]->getBigD();
                }
                
                if(s_edges[i]->getBigD() == v){
                    return s_edges[i]->getOrigin();
                }
            }
        }
        
        
        return '-';
    }

    int outDegree(char v)  {
        int outDegCtr = 0;
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->getOrigin() == v){
                outDegCtr++;
            }
        }
        
        return outDegCtr;
    }

    int inDegree(char v)  {
        int inDegCtr = 0;
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->getBigD() == v){
                inDegCtr++;
            }
        }
        
        return inDegCtr;
    }

    int* outgoingEdges(char v) {
    
        int* outGoingEdgeArr = new int[num_edge];
        int index = 0;
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->getOrigin() == v){
                outGoingEdgeArr[index++] = s_edges[i]->getName();
            }
            
        }
        return outGoingEdgeArr;
    }

    int* incomingEdges(char v) {
        int* incomingEdgeArr = new int[num_edge];
        int index = 0;
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->getBigD() == v){
                incomingEdgeArr[index++] = s_edges[i]->getName();
            }
            
        }
        return incomingEdgeArr;
    }

    bool insertVertex(char x)  {
        s_vertices[num_vert] = x;
        num_vert++;
        return true;
    }

    bool insertEdge(char u, char v, int x)  {
        Edge* e = new Edge(x, u, v);
        
        
        s_edges[num_edge] = e;
        num_edge++;
        return true;
    }

    int removeVertex(char v) {
        int exorcised = 0;
        
        for(int i = 0; i < num_edge;){
            if(s_edges[i]->getOrigin() == v || s_edges[i]->getBigD() == v){
                delete s_edges[i];
                
                for(int j = i; j < num_edge; j++){
                    s_edges[j] = s_edges[j + 1];
                }
                
                num_edge--;
                exorcised++;
                
            }
            else{
                i++;
            }
        }
        
        for(int i = 0; i < num_vert; i++){
            
            if(s_vertices[i] == v){
                for(int j = i; j < num_vert - 1; j++){
                    s_vertices[j] = s_vertices[j + 1];
                }
                num_vert--;
                break;
            
            }

        }

        return exorcised;
    }

    bool removeEdge(int e)  {
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i]->getName() == e){
                delete s_edges[i];
                
                for(int j = i; j < num_edge; j++){
                    s_edges[j] = s_edges[j + 1];
                }
                
                num_edge--;
                return true;
                
            }
            
        }
        
        return false;
    }

    // DO NOT MODIFY
    void print() {
        cout << "Vertices: ";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << " ";
        }
        cout << endl << "Edges: " << endl;
        for (int i = 0; i < num_edge; i++) {
            s_edges[i]->toString();
            cout << endl;
        }
    }
};