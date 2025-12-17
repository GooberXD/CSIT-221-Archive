#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Heap {
private:
    int* heap;
    int size, capacity;

    int parent(int i) { 
        return (i - 1) / 2; 
    }
    int leftChild(int i) { 
        return (2 * i) + 1; 
    }
    int rightChild(int i) { 
        return (2 * i) + 2; 
    }

    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[parent(index)]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int smallest = index;
            int left = leftChild(index);
            int right = rightChild(index);

            if (left < size && heap[left] < heap[smallest]) smallest = left;
            if (right < size && heap[right] < heap[smallest]) smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    Heap() {
        size = 0;
        capacity = 1;
        heap = (int*)calloc(capacity, sizeof(int));
    }

    ~Heap() {
        free(heap);
        heap = nullptr;
        size = capacity = 0;
    }

    void add(int elem) {
        if (size == capacity) {
            capacity = ceil(capacity * 1.5);
            heap = (int*)realloc(heap, capacity * sizeof(int));
        }
        heap[size++] = elem;
        heapifyUp(size - 1);
    }

    int remove() {
        if (size == 0) return -1;
        int minElem = heap[0];
        heap[0] = heap[--size];
        if (size != 0) heapifyDown(0);
        return minElem;
    }

    void print() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
