#include <cstdlib>
#include <iostream>
using namespace std;

class Edge {
    private:
    int name;
    char origin;
    char destination;

    public:
    // ADD more methods as necessary
    Edge(int n, char o, char d){
        name = n;
        origin = o;
        destination = d;
    }
    
    //pluh ahh gets
    
    int getName(){
        return name;
    }
    
    char getOrigin(){
        return origin;
    }
    
    char getBigD(){
        return destination;
    }
    
    
    void toString() {
        cout << name << " | (" << origin << " -> " << destination << ")";
    }
};