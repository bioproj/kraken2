

clean:
	rm -f *.o $(PROGS)

build_db: build_db.o ../src/mmap_file.o ../src/compact_hash.o ../src/taxonomy.o ../src/seqreader.o ../src/mmscanner.o ../src/omp_hack.o ../src/utilities.o
	g++ -Wall -std=c++11 -O3 -fPIC -DLINEAR_PROBING -o build_db  $^