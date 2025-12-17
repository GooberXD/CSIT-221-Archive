#ifndef LIST_HPP
#define LIST_HPP

class List {
    public:
    virtual ~List() {} 

    virtual void add(int num) = 0;
    virtual void addAt(int num, int pos) = 0;
    virtual int remove(int num) = 0;
    virtual int removeAt(int pos) = 0;
    virtual int removeAll(int num) = 0;
    virtual int get(int pos) = 0;
    virtual void print() = 0;
};

#endif