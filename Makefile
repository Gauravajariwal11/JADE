CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

default: jade

all: main 

debug: CXXFLAGS += -g
debug: default

jade: product.o donut.o java.o store.o
	${CXX} ${CXXFLAGS} -o jade product.o donut.o java.o store.o
product.o: product.cpp *.h
	${CXX} ${CXXFLAGS} -c product.cpp
donut.o: donut.cpp *.h
	${CXX} ${CXXFLAGS} -c donut.cpp
java.o: java.cpp *.h
	${CXX} ${CXXFLAGS} -c java.cpp
store.o: store.cpp *.h
	${CXX} ${CXXFLAGS} -c store.cpp
clean:
	-rm -f *.gch *.o a.out jade
