CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors

OBJS = main.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Menu.o Team.o validateInt.o 

SRCS = main.cpp Character.cpp Vampire.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp Menu.cpp Team.cpp validateInt.cpp

HEADERS = Character.hpp Vampire.hpp Barbarian.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp Menu.hpp Team.hpp validateInt.hpp

lab3: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS}  -o Fantasy_Tournament

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o Fantasy_Tournament
