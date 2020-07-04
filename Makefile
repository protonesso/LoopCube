CXXFLAGS=-g -Wall -Wextra -pipe -pedantic -ffunction-sections
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf -O2
CXX=g++
TARGET=bin/LoopCube

SRC=$(shell find src -name '*.cpp')
OBJ=$(patsubst %.cpp,obj/%.o,$(SRC))

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

obj/%.o: %.cpp %.hpp
	@mkdir -p ${shell echo $@ | rev | cut -d '/' -f2- | rev}
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS)

clean:
	rm $(TARGET)
	rm -rf obj/*
