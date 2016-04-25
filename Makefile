all: bin/tarea01 bin/tarea02 bin/tarea03 bin/tarea04 bin/tarea05 bin/tarea06

CXXFLAGS=-std=c++11

bin/tarea01: src/tarea01.o src/bibtareas.o
	$(CXX) -o $@ $^

bin/tarea02: src/tarea02.o src/bibtareas.o
	$(CXX) -o $@ $^

bin/tarea03: src/tarea03.o src/bibtareas.o
	$(CXX) -o $@ $^

bin/tarea04: src/tarea04.o src/bibtareas.o
	$(CXX) -o $@ $^

bin/tarea05: src/tarea05.o src/bibtareas.o
	$(CXX) -o $@ $^

bin/tarea06: src/tarea06.o src/bibtareas.o
	$(CXX) -o $@ $^

src/tarea01.o: src/tarea01.cpp src/bibtareas.h bin

src/tarea02.o: src/tarea02.cpp src/bibtareas.h bin 

src/tarea03.o: src/tarea03.cpp src/bibtareas.h bin

src/tarea04.o: src/tarea04.cpp src/bibtareas.h bin

src/tarea05.o: src/tarea05.cpp src/bibtareas.h bin

src/tarea06.o: src/tarea06.cpp src/bibtareas.h bin

src/bibtareas.o: src/bibtareas.cpp src/bibtareas.h bin

bin:
	mkdir bin

clean:
	rm -f src/*.o bin/tarea* src/*.*~ src/*~
	rmdir bin
