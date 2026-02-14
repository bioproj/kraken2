#include <iostream>
#include <algorithm>
#include "../src/taxonomy.h"

using kraken2::Taxonomy;
using kraken2::TaxonomyNode;

int main(int argc, char **argv) {
  const char *filename;
  if (argc > 1)
    filename = argv[1];
  else
    filename = "/opt/workspace/kraken2/kraken2/read/taxo.k2d.tmp";

  try {
    Taxonomy taxo(filename);
    size_t n = taxo.node_count();
    std::cout << "Loaded taxonomy file '" << filename << "' with " << n
              << " nodes." << std::endl;

    const TaxonomyNode *nodes = taxo.nodes();
    const char *name_data = taxo.name_data();
    const char *rank_data = taxo.rank_data();

    size_t to_show = n;// std::min((size_t)20, n);
    for (size_t i = 0; i < to_show; ++i) {
      const TaxonomyNode &node = nodes[i];
      const char *name = "";
      const char *rank = "";
      if (node.name_offset < (size_t)-1)
        name = name_data + node.name_offset;
      if (node.rank_offset < (size_t)-1)
        rank = rank_data + node.rank_offset;
      std::cout << "node[" << i << "] ext=" << node.external_id
                << " parent=" << node.parent_id
                << " children=" << node.child_count
                << " name='" << name << "' rank='" << rank << "'\n";
    }
  }
  catch (const std::exception &e) {
    std::cerr << "Error loading taxonomy: " << e.what() << std::endl;
    return 2;
  }

  return 0;
}
// g++ -I ../src -std=c++11  -g  -O0 read_taxo_k2d.cc ../src/taxonomy.cc ../src/mmap_file.cc -o read_taxo_k2d -pthread
// ./read_taxo_k2d /data/databases/kraken/pluspf/taxo.k2d