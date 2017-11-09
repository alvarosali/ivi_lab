DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/

CFLAGS := -I$(DIRHEA) -c -Wall -ansi
LDFLAGS := -framework GLUT -framework OpenGL -framework Cocoa

CC := gcc

all: dirs helloOpenGL test

dirs:
	mkdir -p $(DIROBJ) $(DIREXE)

helloOpenGL: 
	$(CC) -o $(DIREXE)helloOpenGL $(DIRSRC)helloOpenGL.c $^ $(LDFLAGS)
	./$(DIREXE)helloOpenGL

test: $(DIROBJ)test.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
