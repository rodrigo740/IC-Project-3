# Project 3: Finite Context Models

This project provides a makefile, so it can be easy to compile and run all of the programs present in this repository and a doxygen documentation.
To use this documentation one just needs to run the following command while in the base folder of the repository:

##### `firefox html/index.html`
or
##### `google-chrome html/index.html`

In the previous commands "firefox" and "google-chrome" can be swapped to the name of the preferred web browser of the user.
Alternatively the user can also open the `html` folder and open the `index.html` file with the browser of preference.

# Contents of the repository

### include folder

All of the ".h" files developed are in this folder.

### lang_models

This folder holds all of the text files that represent various languages we selected to use during this project. If the user decides to add more languages it must add the representative text of that language in this folder.

### texts

This folder holds all of the texts used to test the developed software of this project.

### CPP Files

This project has 4 cpp files:

- testFilter.cpp
- test_lang.cpp
- teste_fcm.cpp
- findlang.cpp

The `testFilter.cpp` is used to filter the input text given, this is done by removing all numbers from the text and converting all characters to their lower case version.  
The `test_lang.cpp` is used to get the number of bits necessary to compress the given text in the provided model.  
The `teste_fcm.cpp` is used to get the entropy of the model text given and number of bits necessary to compress the given text in the provided model.  
The `findlang.cpp` is used to determine in which language the given text is written in, this program will determine the amount of bits necessary to compress the given text in all of the models present in the "lang_models" folder, then it will choose the lower amount of bits and the language that matches that amount as the language the input text is written in. 

# Instructions

Compile all code:

##### `make all`

Compile specific file:

##### `make teste_fcm`
##### `make testFilter`
##### `make test_lang`
##### `make findlang`

Clean the repository (remove all executables):

##### `make clean`

# How to run the programs

##### `./test_lang.o lang_models/portuguese.txt texts/sample_texts/lusiadas.txt 3 0.1`
##### `./testFilter.o lang_models/portuguese.txt texts/portuguese_filtered.txt`
##### `./teste_fcm.o lang_models/portuguese.txt texts/sample_texts/lusiadas.txt 3 0.1`

### findlang.o

This program supports two modes of operation, filtered and not filtered and is necessary to specify which mode needs to be used while running the program by using `-f` for filtered mode and `-nf` for not filtered mode.

##### `./findlang.o texts/sample_texts/lusiadas.txt 3 0.1 -f`
or
##### `./findlang.o texts/sample_texts/lusiadas.txt 3 0.1 -nf`






