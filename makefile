CC=g++

all: rome

rome: main.o RomanConverter.o AlienConverter.o
    $(CC) main.o RomanConverter.o AlienConverter.o -o rome
    
main.o: main.cpp
    $(CC) -c main.cpp
    
RomanConverter.o: RomanConverter.cpp
    $(CC) -c RomanConverter.cpp

AlienConverter.o: AlienConverter.cpp
    $(CC) -c AlienConverter.cpp

clean:
    rm -rf *o rome
