##
# Makefile for FlappyBird++
##
CXX_COMPILER = g++
CXX_STANDARD = c++17 # Requires at least C++17
CXX_FLAGS = -O3 -DNDEBUG
TARGET_OUTPUT = FlappyBirdPlusPlus

# Detecting os from:
# https://stackoverflow.com/questions/714100/os-detecting-makefile
ifeq ($(OS), Windows_NT)
# Disable console on windows
CXX_FLAGS_EXTRA = -Wl,-subsystem,windows
else
CXX_FLAGS_EXTRA =
endif

# Specify location of SFML Headers here:
INCLUDE_PATH = #SFML headers location here

# Specify location of SFML Libraries here:
LIBRARY_PATH = #SFML libraries location here

all: bird.o birdanimation.o fps.o game.o main.o obstacle.o score.o
	$(CXX_COMPILER) main.o bird.o birdanimation.o fps.o game.o obstacle.o score.o $(CXX_FLAGS) $(CXX_FLAGS_EXTRA) -L$(LIBRARY_PATH) -lsfml-system -lsfml-window -lsfml-audio -lsfml-graphics -o $(TARGET_OUTPUT)

clean:
	rm *.o $(TARGET_OUTPUT)

bird.o:
	$(CXX_COMPILER) bird.cpp -std=$(CXX_STANDARD) $(CXX_FLAGS) -I$(INCLUDE_PATH) -c -o bird.o

birdanimation.o:
	$(CXX_COMPILER) birdanimation.cpp -std=$(CXX_STANDARD) $(CXX_FLAGS) -I$(INCLUDE_PATH) -c -o birdanimation.o

fps.o:
	$(CXX_COMPILER) fps.cpp -std=$(CXX_STANDARD) $(CXX_FLAGS) -I$(INCLUDE_PATH) -c -o fps.o

game.o:
	$(CXX_COMPILER) game.cpp -std=$(CXX_STANDARD) $(CXX_FLAGS) -I$(INCLUDE_PATH) -c -o game.o

main.o:
	$(CXX_COMPILER) main.cpp -std=$(CXX_STANDARD) $(CXX_FLAGS) -I$(INCLUDE_PATH) -c -o main.o

obstacle.o:
	$(CXX_COMPILER) obstacle.cpp -std=$(CXX_STANDARD) $(CXX_FLAGS) -I$(INCLUDE_PATH) -c -o obstacle.o

score.o:
	$(CXX_COMPILER) score.cpp -std=$(CXX_STANDARD) $(CXX_FLAGS) -I$(INCLUDE_PATH) -c -o score.o
