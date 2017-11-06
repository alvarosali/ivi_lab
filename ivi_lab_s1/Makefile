DIREXE := exec/
DIRHEA := include/
DIRSRC := src/

CFLAGS := -I$(DIRHEA) -c -Wall -ansi
LDFLAGS := -framework GLUT -framework OpenGL -framework Cocoa

CC := gcc

all: dirs helloOpenGL test

dirs:
	mkdir -p $(DIREXE)

helloOpenGL: 
	$(CC) -o $(DIREXE)helloOpenGL $(DIRSRC)helloOpenGL.c $^ $(LDFLAGS)
	./$(DIREXE)helloOpenGL

test:
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

clean: 
	rm -rf *~ core $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
