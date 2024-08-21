#include "huffman-tree.h"
#include "huffman-min-heap.h"
#include <unordered_map>

using namespace std;

HuffmanNode *buildHuffmanTree(const unordered_map<char, int> &frequency_map) {
    MinHeap min_heap;

    for (const auto &single_map: frequency_map) {
        HuffmanNode *node = new HuffmanNode(single_map.first, single_map.second);
        min_heap.push(node);
    }

    while (min_heap.getSize() > 1) {
        HuffmanNode *leftNode = min_heap.top();
        min_heap.pop();
        HuffmanNode *rightNode = min_heap.top();
        min_heap.pop();

        HuffmanNode *newNode = new HuffmanNode('$', leftNode->frequency + rightNode->frequency);
        newNode->left = leftNode;
        newNode->right = rightNode;

        min_heap.push(newNode);
    }

    HuffmanNode *root = min_heap.top();
    return root;
}

void generatingEncodingTable(HuffmanNode *root, const string &code,
                             unordered_map<char, string> &encoding_table) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        encoding_table[root->data] = code;
    }

    generatingEncodingTable(root->left, code + "0", encoding_table);
    generatingEncodingTable(root->right, code + "1", encoding_table);
}
