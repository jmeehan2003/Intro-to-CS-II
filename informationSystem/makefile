CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o university.o student.o instructor.o

SRCS = main.cpp university.cpp student.cpp instructor.cpp

HEADERS = person.hpp university.hpp student.hpp instructor.hpp building.hpp

ants: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o infoSys

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY: clean
clean:
	rm -f ${OBJS} infoSys
