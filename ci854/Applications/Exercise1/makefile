CC = g++
CFLAGS = -w -g -I../Contrib/Eigen -I/usr/include
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lGL -lglut -lGLU -lGLEW -lX11 -lm

OBJ = camera.o light.o phongmaterial.o renderable.o renderer.o shaderprogram.o surface.o main.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

Exercise1: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o Exercise1

.PHONY: clean
clean:
	rm -rf $(OBJ) Exercise1
