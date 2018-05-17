CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = QueueMain.o Queue.o 

SRCS = QueueMain.cpp Queue.cpp 

HEADERS = Queue.hpp 

ants: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o queue

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY: clean
clean:
	rm -f ${OBJS} queue
