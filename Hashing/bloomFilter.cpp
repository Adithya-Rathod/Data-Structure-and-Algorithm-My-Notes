#include <iostream>
#include <bitset>
#include <functional>

using namespace std;

class BloomFilter {
private:
    bitset<1000> bitArray;  // Bit array to store the filter
    hash<string> hashFunction1;  // First hash function
    hash<string> hashFunction2;  // Second hash function

public:
    void add(const string& item) {
        size_t index1 = hashFunction1(item) % bitArray.size();
        size_t index2 = hashFunction2(item) % bitArray.size();
        
        bitArray[index1] = 1;
        bitArray[index2] = 1;
        
    }
    bool contains(const string& item) {
        size_t index1 = hashFunction1(item) % bitArray.size();
        size_t index2 = hashFunction2(item) % bitArray.size();

        return bitArray[index1] && bitArray[index2];
    }
};

int main() {
    BloomFilter filter;

    // Add items to the filter
    filter.add("apple");
    filter.add("banana");
    filter.add("cherry");

    // Check if items are present
    cout << filter.contains("apple") << endl;   // 1 (true)
    cout << filter.contains("banana") << endl;  // 1 (true)
    cout << filter.contains("cherry") << endl;  // 1 (true)
    cout << filter.contains("grape") << endl;   // 0 (false)

    return 0;
}
