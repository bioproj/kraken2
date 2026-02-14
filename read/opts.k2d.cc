#include <fstream>
#include <iostream>
#include "../src/kraken2_data.h"   
using kraken2::IndexOptions; 

int main() {
    IndexOptions opts;

    std::ifstream ifs("/opt/workspace/kraken2/kraken2/data/small_db/opts.k2d", std::ios::binary);
    if (!ifs) {
        std::cerr << "Failed to open opts.k2d.tmp" << std::endl;
        return 1;
    }

    ifs.read(reinterpret_cast<char*>(&opts), sizeof(opts));
    if (!ifs) {
        std::cerr << "Failed to read IndexOptions from file" << std::endl;
        return 1;
    }

    std::cout << "k = " << opts.k << "\n";
    std::cout << "l = " << opts.l << "\n";
    std::cout << "spaced_seed_mask = " << opts.spaced_seed_mask << "\n";
    std::cout << "toggle_mask = " << opts.toggle_mask << "\n";
    std::cout << "dna_db = " << opts.dna_db << "\n";

    return 0;
}
// g++ -std=c++11 -I../src -O2 opts.k2d.cc -o opts.k2d