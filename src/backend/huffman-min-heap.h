#ifndef BACKEND_HUFFMAN_MIN_HEAP_H
#define BACKEND_HUFFMAN_MIN_HEAP_H

#include "huffman-tree.h"

using namespace std;

const int MAX_MIN_HEAP_SIZE = 25565;

class MinHeap {
private:
    HuffmanNode *elements[MAX_MIN_HEAP_SIZE];
    int size;

    static int get_parent_index(int index);

    static int get_left_child_index(int index);

    static int get_right_child_index(int index);


    void shift_up(int index);

    void shift_down(int index);

public:
    MinHeap();

    MinHeap(const MinHeap &heap);

    ~MinHeap();

    void pop();

    void push(HuffmanNode *node);

    HuffmanNode *top();

    int getSize() const;

    bool isEmpty() const;

    bool isFull() const;
};

#endif //BACKEND_HUFFMAN_MIN_HEAP_H
