# the compiler: gcc for C program, define as g++ for C++
CXX = g++
RM = rm -f

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall 
LIB = -lstdc++fs

# The build target 
TARGETS = teste_fcm findlang testFilter test_lang
CLEAN = teste_fcm.o findlang.o testFilter.o test_lang.o

all: $(TARGETS)

teste_fcm: teste_fcm.cpp
			$(CXX) $(CFLAGS) teste_fcm.cpp -o teste_fcm.o

testFilter: testFilter.cpp
			$(CXX) $(CFLAGS) testFilter.cpp -o testFilter.o

findlang: findlang.cpp
			$(CXX) $(CFLAGS) findlang.cpp $(LIB) -o findlang.o 

test_lang: test_lang.cpp
			$(CXX) $(CFLAGS) test_lang.cpp -o test_lang.o 

clean:
			$(RM) $(CLEAN)