CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o queue.o character.o bluemen.o barbarian.o medusa.o hpotter.o vampire.o 

SRCS = main.cpp queue.cpp character.cpp bluemen.cpp barbarian.cpp medusa.cpp hpotter.cpp vampire.cpp 

HEADERS = queue.hpp character.hpp bluemen.hpp barbarian.hpp medusa.hpp hpotter.hpp vampire.hpp 

ants: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o battle

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY: clean
clean:
	rm -f ${OBJS} battle
