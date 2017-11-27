DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
MKDIR_P := mkdir -p

CC := gcc
CFLAGS := -I$(DIRHEA) -c -Wall -ansi
LDLIBS := -framework OpenGL -framework Cocoa -framework GLUT

all: dirs helloOpenGL2.2 helloOpenGL2.3 tetera2.4 tetera2.5 planetario2.6 planetario2.7 planetario2.8

dirs:
	$(MKDIR_P) $(DIROBJ) $(DIREXE)

helloOpenGL2.2: $(DIROBJ)helloOpenGL2.2.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

helloOpenGL2.3: $(DIROBJ)helloOpenGL2.3.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

tetera2.4: $(DIROBJ)tetera2.4.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

tetera2.5: $(DIROBJ)tetera2.5.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

planetario2.6: $(DIROBJ)planetario2.6.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

planetario2.7: $(DIROBJ)planetario2.7.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

planetario2.8: $(DIROBJ)planetario2.8.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	$(RM) -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
