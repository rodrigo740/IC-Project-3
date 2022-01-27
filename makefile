# the compiler: gcc for C program, define as g++ for C++
CXX = g++
RM = rm -f

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGETS = teste_fcm testFilter

all: $(TARGETS)

teste_fcm: teste_fcm.cpp
			$(CXX) $(CFLAGS) teste_fcm.cpp -o teste_fcm.o

testFilter: testFilter.cpp
			$(CXX) $(CFLAGS) testFilter.cpp -o testFilter.o

clean:
			$(RM) $(TARGETS).o