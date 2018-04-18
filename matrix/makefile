CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o readMatrix.o determinant.o

SRCS = main.cpp readMatrix.cpp determinant.cpp

HEADERS = readMatrix.hpp determinant.hpp

matrix: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o matrix

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY: clean
clean:
	rm -f ${OBJS} matrix
