FLAGS=-Wall -Wextra -lSDL2 -lSDL2_image -O2
CC=g++

Debug: main.o game.o texture.o gameobj.o camera.o block.o chunk.o chunkgroup.o texturehandler.o perlin.o
	$(CC) $(FLAGS) -o bin/Debug/LoopCube main.o game.o texture.o gameobj.o camera.o block.o chunk.o chunkgroup.o texturehandler.o perlin.o
	mv *.o obj/Debug/src/

main.o: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp

game.o: src/game.cpp
	$(CC) $(FLAGS) -c src/game.cpp

gameobj.o: src/gameobj.cpp
	$(CC) $(FLAGS) -c src/gameobj.cpp

texture.o: src/texture.cpp
	$(CC) $(FLAGS) -c src/texture.cpp

camera.o: src/camera.cpp
	$(CC) $(FLAGS) -c src/camera.cpp

block.o: src/block.cpp
	$(CC) $(FLAGS) -c src/block.cpp

chunk.o: src/chunk.cpp
	$(CC) $(FLAGS) -c src/chunk.cpp

chunkgroup.o: src/chunkgroup.cpp
	$(CC) $(FLAGS) -c src/chunkgroup.cpp

texturehandler.o: src/texturehandler.cpp
	$(CC) $(FLAGS) -c src/texturehandler.cpp

perlin.o: src/math/perlin.cpp
	$(CC) $(FLAGS) -c src/math/perlin.cpp

cleanDebug:
	rm -rf bin/Debug/LoopCube
