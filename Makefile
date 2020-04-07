FLAGS=-g -Wall -Wextra -lSDL2 -lSDL2_image
CXX=g++

Debug: main.o game.o texture.o gameobj.o camera.o block.o chunk.o chunkgroup.o texturehandler.o perlin.o
	$(CXX) $(FLAGS) -o bin/Debug/LoopCube main.o game.o texture.o gameobj.o camera.o block.o chunk.o chunkgroup.o texturehandler.o perlin.o
	mv *.o obj/Debug/src/

main.o: src/main.cpp
	$(CXX) $(FLAGS) -c src/main.cpp

game.o: src/game.cpp
	$(CXX) $(FLAGS) -c src/game.cpp

gameobj.o: src/gameobj.cpp
	$(CXX) $(FLAGS) -c src/gameobj.cpp

texture.o: src/texture.cpp
	$(CXX) $(FLAGS) -c src/texture.cpp

camera.o: src/camera.cpp
	$(CXX) $(FLAGS) -c src/camera.cpp

block.o: src/block.cpp
	$(CXX) $(FLAGS) -c src/block.cpp

chunk.o: src/chunk.cpp
	$(CXX) $(FLAGS) -c src/chunk.cpp

chunkgroup.o: src/chunkgroup.cpp
	$(CXX) $(FLAGS) -c src/chunkgroup.cpp

texturehandler.o: src/texturehandler.cpp
	$(CC) $(FLAGS) -c src/texturehandler.cpp

perlin.o: src/math/perlin.cpp
	$(CC) $(FLAGS) -c src/math/perlin.cpp

cleanDebug:
	rm -rf bin/Debug/LoopCube
