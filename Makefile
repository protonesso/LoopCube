FLAGS=-Wall -Wextra -lSDL2 -lSDL2_image
CXX=g++
TARGET=LoopCube

SRC=$(shell find src -name '*.cpp')
OBJ=$(patsubst %.cpp,obj/%.o,$(SRC))

_SRC_FILES=$(shell find src -type f -name '*.cpp' -printf '%f\n')
SRC_FILES=$(patsubst %.cpp,obj/%.o,$(_SRC_FILES))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(FLAGS) -o bin/$@ $(SRC_FILES) $(FLAGS)

obj/%.o: %.cpp
	$(CXX) -c -o obj/$(notdir $@) $< $(FLAGS)

cleanDebug:
	rm bin/$(TARGET)
	rm obj/*
