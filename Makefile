# Automated Makefile

CC = g++

CFLAGS = -Wall -O3

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
LDFLAGS += -lglut -lGLU -lGL
endif

ifeq ($(UNAME), Darwin)
LDFLAGS += -framework OpenGL -framework GLUT
endif



COMPILE = $(CC) $(CFLAGS) -c

OBJFILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
 


all: stausim



stausim: $(OBJFILES)

	$(CC) -o stausim $(OBJFILES) $(LDFLAGS)



%.o: %.cpp

	$(COMPILE) -o $@ $<

clean:
	
	rm *.o
