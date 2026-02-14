
CXXFLAGS = -Wall -std=c++11 -g -O0 -fPIC -DLINEAR_PROBING -fopenmp

clean:
	rm -f *.o $(PROGS)
	rm -rf ../src/*.o


build_db: build_db.o ../src/mmap_file.o ../src/compact_hash.o ../src/taxonomy.o ../src/seqreader.o ../src/mmscanner.o ../src/omp_hack.o ../src/utilities.o
	g++ -Wall -std=c++11 -g -O0 -fPIC -DLINEAR_PROBING -o build_db $^

build_db.o: build_db.cc
	g++ -Wall -std=c++11 -g -O0 -fPIC -DLINEAR_PROBING -c -o build_db.o build_db.cc


../src/%.o: ../src/%.cc
	g++ -Wall -std=c++11 -g -O0 -fPIC -DLINEAR_PROBING -c -o $@ $<