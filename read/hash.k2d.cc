#include "../src/compact_hash.h"
using kraken2::CompactHashTable;
using kraken2::hvalue_t;

struct CompactHashTableAccessor : public CompactHashTable {
public:
    using CompactHashTable::CompactHashTable;
    using CompactHashTable::LoadTable;
};

int main() {
//   read /opt/workspace/kraken2/kraken2/data/small_db/hash.k2d to CompactHashTable
    CompactHashTableAccessor hash(1000, 16, 16);
    hash.LoadTable("/opt/workspace/kraken2/kraken2/data/small_db/hash.k2d", true);
    
    // print all key-value pairs in the hash table
    for (size_t i = 0; i < hash.capacity(); i++) {
        hvalue_t value = hash.Get(i);
        if (value != 0) {
        printf("Key: %zu, Value: %u\n", i, value);
        }   
    }

}
