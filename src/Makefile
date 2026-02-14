

clean:
	rm -f *.o $(PROGS)

taxonomy.o: taxonomy.cc taxonomy.h mmap_file.h
hyperloglogplus.o: hyperloglogplus.cc hyperloglogplus.h
mmap_file.o: mmap_file.cc mmap_file.h
compact_hash.o: compact_hash.cc compact_hash.h kv_store.h mmap_file.h kraken2_data.h
mmscanner.o: mmscanner.cc mmscanner.h
seqreader.o: seqreader.cc seqreader.h kseq.h
omp_hack.o: omp_hack.cc omp_hack.h
reports.o: reports.cc reports.h kraken2_data.h
aa_translate.o: aa_translate.cc aa_translate.h
utilities.o: utilities.cc utilities.h

classify.o: classify.cc kraken2_data.h kv_store.h taxonomy.h seqreader.h mmscanner.h compact_hash.h aa_translate.h reports.h utilities.h readcounts.h
dump_table.o: dump_table.cc compact_hash.h taxonomy.h mmscanner.h kraken2_data.h reports.h
estimate_capacity.o: estimate_capacity.cc kv_store.h mmscanner.h seqreader.h utilities.h
build_db.o: build_db.cc taxonomy.h mmscanner.h seqreader.h compact_hash.h kv_store.h kraken2_data.h utilities.h
lookup_accession_numbers.o: lookup_accession_numbers.cc mmap_file.h utilities.h
k2mask.o: k2mask.cc gzstream.h threadpool.h

blast_defline.o: blast_defline.c
blast_to_fasta.o: blast_to_fasta.c
blast_utils.o: blast_utils.c

build_db: build_db.o mmap_file.o compact_hash.o taxonomy.o seqreader.o mmscanner.o omp_hack.o utilities.o
	g++ -Wall -std=c++11 -O3 -fPIC -DLINEAR_PROBING -o $@ build_db.o mmap_file.o compact_hash.o taxonomy.o seqreader.o mmscanner.o omp_hack.o utilities.o 