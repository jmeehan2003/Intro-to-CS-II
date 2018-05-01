CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o game.o zoo.o tiger.o penguin.o turtle.o

SRCS = main.cpp game.cpp zoo.cpp tiger.cpp penguin.cpp turtle.cpp 

HEADERS = animal.hpp game.hpp zoo.hpp tiger.hpp penguin.hpp turtle.hpp 

ants: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Zoo

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY: clean
clean:
	rm -f ${OBJS} Zoo
