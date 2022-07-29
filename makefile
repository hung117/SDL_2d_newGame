CC=g++

SDIR=./Src/include
CFLAGS=-I$(SDIR)

LDIR=-L ./Src/lib
LIBS= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

HDIR = ./Src/include
_HEADER= renderWindow.h Entity.h
# _HEADER= *.h
HEADER=$(patsubst %,$(HDIR)/%,$(_HEADER))

SrcDIR = ./Src/
# _SRC=main.cpp
_SRC=*.cpp
SRC=$(patsubst %,$(SrcDIR)/%,$(_SRC))

all:
# $(CC) $(CFLAGS) $(LDIR) -o ./exe/game.exe ./Src/main.cpp $(LIBS)
# $(CC) $(CFLAGS) $(LDIR) -o ./exe/game.exe $(SRC) $(HEADER) $(LIBS)
	$(CC) $(CFLAGS) $(LDIR) -o ./exe/game.exe $(SRC) $(LIBS)

.PHONY: clean
clean:
	@echo "clean project"
	del -f *.o 
	@echo "clean completed"
cleanall:
	@echo "clean exe"
	del -f *.o *exe 
	@echo "clean completed"*.exe
