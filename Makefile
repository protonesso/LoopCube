# TODO CLEAN THIS UP
FLAGS=-Wall -Wextra -lSDL2 -lSDL2_image
CXX=g++

Debug: main.o game.o texture.o gameobj.o camera.o block.o chunk.o chunkgroup.o texturehandler.o perlin.o player.o
	$(CXX) $(FLAGS) -o bin/Debug/LoopCube main.o game.o texture.o gameobj.o camera.o block.o chunk.o chunkgroup.o texturehandler.o perlin.o player.o
	mv *.o obj/Debug/src/

main.o: src/main.cpp
	$(CXX) $(FLAGS) -c src/main.cpp

game.o: src/game/game.cpp
	$(CXX) $(FLAGS) -c src/game/game.cpp

gameobj.o: src/gameobject/gameobj.cpp
	$(CXX) $(FLAGS) -c src/gameobject/gameobj.cpp

texture.o: src/texture/texture.cpp
	$(CXX) $(FLAGS) -c src/texture/texture.cpp

camera.o: src/camera/camera.cpp
	$(CXX) $(FLAGS) -c src/camera/camera.cpp

block.o: src/gameobject/block.cpp
	$(CXX) $(FLAGS) -c src/gameobject/block.cpp

chunk.o: src/chunk/chunk.cpp
	$(CXX) $(FLAGS) -c src/chunk/chunk.cpp

chunkgroup.o: src/chunk/chunkgroup.cpp
	$(CXX) $(FLAGS) -c src/chunk/chunkgroup.cpp

texturehandler.o: src/texture/texturehandler.cpp
	$(CXX) $(FLAGS) -c src/texture/texturehandler.cpp

perlin.o: src/math/perlin.cpp
	$(CXX) $(FLAGS) -c src/math/perlin.cpp

player.o: src/gameobject/player.cpp
	$(CXX) $(FLAGS) -c src/gameobject/player.cpp

cleanDebug:
	rm -rf bin/Debug/LoopCube
