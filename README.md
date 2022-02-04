# Project-3: Finite Context Models

This project provides a makefile, so it can be easy to compile and run all of he programs present in this repository.

# Contents of the repository



# Instructions

Compile all code:

##### `make all` or just ##### `make`

Compile specific file:

##### `make teste_fcm`
##### `make testFilter`
##### `make test_lang`
##### `make findlang`

Clean the repository(remove all executables):

##### `make clean`

# How to run the programs

##### `./test_lang.o lang_models/portuguese.txt texts/sample_texts/lusiadas.txt 3 0.1`
##### `./testFilter.o lang_models/portuguese.txt texts/portuguese_filtered.txt`
##### `./teste_fcm.o lang_models/portuguese.txt texts/sample_texts/lusiadas.txt 3 0.1`
##### `./findlang.o texts/sample_texts/lusiadas.txt 3 0.1 -f`






