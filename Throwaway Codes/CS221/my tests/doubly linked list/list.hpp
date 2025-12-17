//List ADT
class List {
public:
    virtual void addHead(int) = 0;
    virtual void addTail(int) = 0;
    virtual int get(int pos) = 0;
    virtual int remove(int num) = 0;
    virtual void print() = 0;
    virtual void addAt(int, int) = 0;
};

