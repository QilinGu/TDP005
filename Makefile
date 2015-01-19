CXXFLAGS=-Wall -Wextra -std=c++11 -Wno-unused-parameter -O2
SDL_FLAGS=`sdl2-config --libs --cflags` -lSDL2_image -lSDL2_mixer -lSDL2_ttf

OBJ_FILES=	main.o texturebank.o game.o Player.o gameobject.o enemy.o gamestate.o state.o Bullet.o \
			selector.o menustate.o Audio.o AudioSoundEffect.o AudioMusic.o pickupscore.o fileHandler.o \
			highScoreHandler.o shootingenemy.o
			
#CCFILES= main.cc texturebank.cc game.cc Player.cc gameobject.cc enemy.cc gamestate.cc state.cc Bullet.cc \
		 selector.cc menustate.cc Audio.cc AudioSoundEffect.cc AudioMusic.cc pickupscore.cc fileHandler.cc \
		 highScoreHandler.cc

#all: main

#main:
#	g++ $(CXXFLAGS) $(CCFILES) -o main $(SDL_FLAGS)

#clean:
#	rm -rf *.o main

all: app

app: $(OBJ_FILES)
	 g++ $(CXXFLAGS) $(OBJ_FILES) -o main $(SDL_FLAGS)


main.o : main.cc
		g++ $(CXXFLAGS) -c main.cc $(SDL_FLAGS)

texturebank.o : texturebank.cc
		g++ $(CXXFLAGS) -c texturebank.cc $(SDL_FLAGS)
		
shootingenemy.o : shootingenemy.cc
		g++ $(CXXFLAGS) -c shootingenemy.cc $(SDL_FLAGS)
		
game.o : game.cc
		g++ $(CXXFLAGS) -c game.cc $(SDL_FLAGS)
		
Player.o : Player.cc
		g++ $(CXXFLAGS) -c Player.cc $(SDL_FLAGS)
		
gameobject.o : gameobject.cc
		g++ $(CXXFLAGS) -c gameobject.cc $(SDL_FLAGS)
		
enemy.o : enemy.cc
		g++ $(CXXFLAGS) -c enemy.cc $(SDL_FLAGS)
		
gamestate.o : gamestate.cc
		g++ $(CXXFLAGS) -c gamestate.cc $(SDL_FLAGS)
		
state.o : state.cc
		g++ $(CXXFLAGS) -c state.cc $(SDL_FLAGS)
		
Bullet.o : Bullet.cc
		g++ $(CXXFLAGS) -c Bullet.cc $(SDL_FLAGS)
		
selector.o : selector.cc
		g++ $(CXXFLAGS) -c selector.cc $(SDL_FLAGS)
		
menustate.o : menustate.cc
		g++ $(CXXFLAGS) -c menustate.cc $(SDL_FLAGS)
		
Audio.o : Audio.cc
		g++ $(CXXFLAGS) -c Audio.cc $(SDL_FLAGS)
		
AudioSoundEffect.o : AudioSoundEffect.cc
		g++ $(CXXFLAGS) -c AudioSoundEffect.cc $(SDL_FLAGS)
		
AudioMusic.o : AudioMusic.cc
		g++ $(CXXFLAGS) -c AudioMusic.cc $(SDL_FLAGS)
		
pickupscore.o : pickupscore.cc
		g++ $(CXXFLAGS) -c pickupscore.cc $(SDL_FLAGS)
		
fileHandler.o : fileHandler.cc
		g++ $(CXXFLAGS) -c fileHandler.cc $(SDL_FLAGS)
		
highScoreHandler.o : highScoreHandler.cc
		g++ $(CXXFLAGS) -c highScoreHandler.cc $(SDL_FLAGS)
		
		
clean:
	rm -rf *.o main