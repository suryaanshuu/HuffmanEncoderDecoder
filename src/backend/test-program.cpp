#include <iostream>
#include "huffman-encoding.h"
#include "huffman-decoding.h"
#include "huffman-min-heap.h"

using namespace std;

int main() {
    string data = "Hello World, I am YoungZM!";
    unordered_map<char, std::string> encoding_table = getEncodingTable(data);
    string compressed_data = compressData(data, encoding_table);
    cout << "Compressed data: " << compressed_data << std::endl;
    string decompressed_data = decompressData(compressed_data, encoding_table);
    cout << "Decompressed data: " << decompressed_data << std::endl;
    return 0;
}
