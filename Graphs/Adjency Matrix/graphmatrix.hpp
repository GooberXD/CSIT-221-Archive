#include <cstdlib>
#include <bits/stdc++.h>
#include <iostream>
#include "graph.hpp"
using namespace std;

class GraphMatrix : public Graph {
    int matrix[10][10];
    char s_vertices[10];
    int num_vert;
    int s_edges[100];
    int num_edge;

    public:
    GraphMatrix() {
        num_vert = 0;
        num_edge = 0;
    }

    int numVertices() {
        return num_vert;
    }

    char* vertices() {
        // char* g = new char[10];
        
        // for(int i = 0; i < num_vert; i++){
        //     g[i] = s_vertices[i];
        // }
        
        // return g;
        
        return s_vertices;
        
        
        
        
        // return false;
        // return arr;
    }

    int numEdges() {
        return num_edge;
    }

    int* edges() {
        return s_edges;
    }

    int getEdge(char u, char v)  {
        
        int uS;
        int vS;
        
        for(int i = 0; i < 10; i++){
            if(s_vertices[i] == u){
                uS = i;
                
            }
            
            if(s_vertices[i] == v){
                vS = i;
                
            }
        }
        
        return matrix[uS][vS];
        
        // sirs solution
        // int u_ind = 0; v_ind = 0;
        
        // for(int i = 0; i < num_vert; i++){
        //     if(u == s_vertices[i]){
        //         u_ind = i;
        //     }
            
        //     if(v = s_vertices[i]){
        //         v_ind = i;
        //     }
        // }
        
        // return matrix[u_ind][v_ind];
        
        
    }

    char* endVertices(int e)  {
        int chck = 0;
        char* g = new char[10];
        
        for(int i = 0; i < num_vert; i++){
            // g[0] = '-';
            // g[1] = '-';
            for(int j = 0; j < num_vert; j++){
                
                if(matrix[i][j] == e){
                    g[0] = s_vertices[i];
                    g[1] = s_vertices[j];
                    chck = 69;
                }
                
            }
            
            
        }
        
        if(chck == 0){
            g[0] = '-';
            g[1] = '-';
        }
        
        return g;
        
        
        //sirs version
        // char* ret = new char[2];
        // for(int i = 0; i< num_vert; i++){
        //     for(int j = 0; j < num_vert; i++){
        //         if(matrix[i][j] == e){
        //             ret[0] = s_vertices[i];
        //             ret[1] = s_vertices[j];
        //             return ret;
        //         }
        //     }
        // }
        // ret[0] = '-';
        // ret[1] = '-';
        // return ret;
        
        // return NULL;
    }

    char opposite(char v, int e)  {
        
        
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(matrix[i][j] == e){
                    if(s_vertices[j] == v){
                        return s_vertices[i];
                    }
                    
                    if(s_vertices[i] == v){
                        return s_vertices[j];
                    }
                    
                }
            }
        }
        
        return '-';
        
        
        // sirs version
        // int v_ind = 0;
        // for(int i = 0; i < num_vert; i++){
        //     if(v == s_vertices[i]){
        //         v_ind = i;
        //     }
        // }
        
        // for(int i = 0; i < num_vert; i++){
        //     if(matrix[v_ind][i] == e){
        //         return s_vertices[i];
        //     }
        //     if(matrix[i][v_ind] == e){
        //         return s_vertices[i];
        //     }
        // }
        
        // return '-';
    }

    int outDegree(char v)  {
        int uS;
        int vS;
        
        for(int i = 0; i < 10; i++){
            if(s_vertices[i] == v){
                uS = i;
                
            }
            
            if(s_vertices[i] == v){
                vS = i;
                
            }
        }
        
        int res = 0;
        
        // for(int i = uS; i = uS; i++){
        while(true){
            int i = uS;
            for(int j = 0; j < 10; j++){
                
                if(matrix[i][j] != 0){
                    res++;
                }
            }
            break;
        }
        
        return res;
        
        
        
        //sir solution
        // int* my_edge = (int*) malloc(10);
        // int ctr = 0;
        // int v_ind = 0;
        
        // for(int i = 0; i < num_vert; i++){
        //     if(v == s_vertices[i]){
        //         v_ind = i;
        //     }
        // }
        // for(int i = 0; i < num_vert; i++){
        //     if(matrix[v_ind][i] > 0){
        //         my_edge[ctr++] = matrix[v_ind][i];
        //     }
        // }
        // return ctr;
        
        
    }

    int inDegree(char v)  {
        
        int uS;
        int vS;
        
        for(int i = 0; i < 10; i++){
            if(s_vertices[i] == v){
                uS = i;
                
            }
            
            if(s_vertices[i] == v){
                vS = i;
                
            }
        }
        
        int res = 0;
        
        // for(int i = uS; i = uS; i++){
        while(true){
            int i = vS;
            for(int j = 0; j < 10; j++){
                
                if(matrix[j][i] != 0){
                    res++;
                }
            }
            break;
        }
        
        return res;
    }

    int* outgoingEdges(char v) {
        int* g = new int[10];
        
        // for(int i = 0; i < num_vert; i++){
            
        //     for(int j = 0; j < num_vert; j++){
                
        //         if(matrix[i][j] == e){
        //             g[0] = s_vertices[i];
        //             g[1] = s_vertices[j];
        //         }
                
        //     }
            
            
        // }
          
        int uS;
        int vS;
        
        for(int i = 0; i < 10; i++){
            if(s_vertices[i] == v){
                uS = i;
                
            }
            
            if(s_vertices[i] == v){
                vS = i;
                
            }
        }
        
        int ctr = 0;
        
        // for(int i = uS; i = uS; i++){
        while(true){
            int i = uS;
            for(int j = 0; j < 10; j++){
                
                if(matrix[i][j] != 0){
                    g[ctr] = matrix[i][j];
                    ctr++;
                }
            }
            break;
        }
        
        return g;
        
        
        // return NULL;
        
        // sirs solution
        // int* my_edge = (int*) malloc(10);
        // int ctr = 0;
        // int v_ind = 0;
        
        // for(int i = 0; i < num_vert; i++){
        //     if(v == s_vertices[i]){
        //         v_ind = i;
        //     }
        // }
        // for(int i = 0; i < num_vert; i++){
        //     if(matrix[v_ind][i] > 0){
        //         my_edge[ctr++] = matrix[v_ind][i];
        //     }
        // }
        // return my_edge;
        
    }

    int* incomingEdges(char v) {
        
        int* g = new int[10];
          
        int uS;
        int vS;
        
        for(int i = 0; i < 10; i++){
            if(s_vertices[i] == v){
                uS = i;
                
            }
            
            if(s_vertices[i] == v){
                vS = i;
                
            }
        }
        
        int ctr = 0;
        
        // for(int i = uS; i = uS; i++){
        while(true){
            int i = uS;
            for(int j = 0; j < 10; j++){
                
                if(matrix[j][i] != 0){
                    g[ctr] = matrix[j][i];
                    ctr++;
                }
            }
            break;
        }
        
        return g;
        
        
        // return NULL;
    }

    bool insertVertex(char x)  {
        // int bruh = 0;
        // for(int i = 0; i < 10; i++){
        //     if(s_vertices[i] == 0){
        //         s_vertices[i] = x;
        //         num_vert++;
        //         break;
                
        //     }
        // }
        
        //sirs version
        s_vertices[num_vert] = x;
        num_vert++;
        return true;
        
        return false;
    }

    bool insertEdge(char u, char v, int x)  {
        
        int uS;
        int vS;
        
        for(int i = 0; i < 10; i++){
            if(s_vertices[i] == u){
                uS = i;
                
            }
            
            if(s_vertices[i] == v){
                vS = i;
                
            }
        }
        
        
        matrix[uS][vS] = x;
        s_edges[num_edge] = x;
        num_edge++;
        
        return true;
        
        
        // sirs version of insert edges
        // int u_ind = 0;
        // int v_ind = 0;
        
        // for(int i = 0; i < num_vert; i++){
        //     if(u == s_vertices[i]){
        //         u_ind = i;
        //     }
            
        //     if(v == s_vertices[i]){
        //         v_ind = i;
        //     }
        // }
        
        // if(matrix[u_ind][v_ind] != 0){
        //     cout << "Not null" << endl;
        //     return false;
        // }
        
        // matrix[u_ind][v_ind] = x;
        // s_edges[num_edge] = x;
        // num_edge++;
        // return true;
        
        
    }

    int removeVertex(char v) {
        int ctr = 0;
        
        int v_ind = 0;
        for(int i = 0; i < num_vert; i++){
            if(v == s_vertices[i]){
                v_ind = i;
            }
        }
        
        for(int i = 0; i < num_vert; i++){
            if(matrix[v_ind][i] > 0){
                removeEdge(matrix[v_ind][i]);
                ctr++;
            }
            
            if(matrix[i][v_ind] > 0){
                removeEdge(matrix[i][v_ind]);
                ctr++;
            }
        }
        
        for(int j = 0; j < num_vert; j++){
            for(int i = v_ind; i < num_vert-1; i++){
                matrix[j][i] = matrix[j][i + 1];
            }
            matrix[j][num_vert-1] = 0;
        }
        
        for(int j = 0; j < num_vert; j++){
            for(int i = v_ind; i < num_vert-1; i++){
                matrix[i][j] = matrix[i + 1][j];
            }
            matrix[num_vert-1][j] = 0;
        }
        
        for(int i = v_ind; i < num_vert-1; i++){
                s_vertices[i] = s_vertices[i+1];
        }
        
        num_vert--;
        return ctr;
    }

    bool removeEdge(int e)  {
        int ctr = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(matrix[i][j] == e){
                    
                    matrix[i][j] = 0;
                    ctr;
                }
            }
        }
        
        // if(ctr == 0){
        //     return false;
        // }
        
        // printf("%d\n", ctr);
        num_edge--;
        return true;
        
        
        //sirs solution
        //for(int i = 0; i < num_vert; i++){
        //     for(int j = 0; j < num_vert; j++){
        //         if(matrix[i][j] == e){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
        
        // int e_ind = 0;
        // for(int i = 0; i < num_edge; i++){
        //     if(e == s_edges[i]){
        //         e_ind = i;
        //         break;
        //     }
        // }
        
        // for(int i = e_ind; i < num_edge-1; i++){
        //     s_edges[i] = s_edges[i + 1];
        // }
        // num_edge--;
        // return true;
        
        
    }

    void print() {
        cout << "\t";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
        }
        cout << endl;
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] != 0) {
                    cout << matrix[i][j];
                }
                cout << "\t";
            }
            cout << endl;
        }
    }
};




//prototyp matrix forloop
// for(int i = 0; i < num_edge; i++){
//     for(int j = 0; j < num_edge; j++){
                
//     }
// }