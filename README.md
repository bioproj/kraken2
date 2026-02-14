/opt/workspace/kraken2/install/kraken2-build  --download-taxonomy --db small_db
/opt/workspace/kraken2/install/kraken2-build --add-to-library COVID_19.fa --db small_db
/opt/workspace/kraken2/install/kraken2-build --build --db small_db
/opt/workspace/kraken2/install/kraken2 --db /opt/workspace/kraken2/kraken2/data/small_db  COVID_19.fa 

/opt/workspace/kraken2/install/classify \
    -H /opt/workspace/kraken2/kraken2/data/small_db/hash.k2d \
    -t /opt/workspace/kraken2/kraken2/data/small_db/taxo.k2d \
    -o /opt/workspace/kraken2/kraken2/data/small_db/opts.k2d \
    -p 1 -T 0 -Q 0 -g 2 COVID_19.fa


/opt/workspace/kraken2/install/build_db \
    -k 35 \
    -l 31 \
    -S 1111111111111111101010101010101            \
    -H hash.k2d.tmp \
    -t taxo.k2d.tmp \
    -o opts.k2d.tmp \
    -n taxonomy/ \
    -m seqid2taxid.map          \
    -c 24137 \
    -p 1  \
    -B 16384 \
    -b 16384           \
    -r 0 


cat /opt/workspace/kraken2/kraken2/data/small_db/library/added/O_jVnIIAMS.fna |  /opt/workspace/kraken2/install/build_db \
    -k 35 \
    -l 31 \
    -S 1111111111111111101010101010101 \
    -H hash.k2d.tmp \
    -t taxo.k2d.tmp \
    -o opts.k2d.tmp \
    -n taxonomy/ \
    -m seqid2taxid.map \
    -c 24137 \
    -p 16 \
    -B 16384 \
    -b 16384 \
    -r 0


59G     k2_pluspf_20240112.tar.gz
pigz -dc k2_pluspf_20240112.tar.gz | tar -t
3.9M    database100mers.kmer_distrib
3.6M    database150mers.kmer_distrib
3.3M    database200mers.kmer_distrib
3.0M    database250mers.kmer_distrib
2.8M    database300mers.kmer_distrib
4.5M    database50mers.kmer_distrib
4.2M    database75mers.kmer_distrib
77G     hash.k2d
3.2M    inspect.txt
2.4M    ktaxonomy.tsv
44M     library_report.tsv
4.0K    opts.k2d
6.8M    seqid2taxid.map
3.7M    taxo.k2d
8.0K    unmapped_accessions.txt

