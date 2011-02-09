# Automated Makefile

CC = g++

CFLAGS = -Wall -O2
LDFLAGS += -lglut -lGLU


COMPILE = $(CC) $(CFLAGS) -c

OBJFILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
 


all: stausim



stausim: $(OBJFILES)

	$(CC) -o stausim $(OBJFILES) $(LDFLAGS)



%.o: %.cpp

	$(COMPILE) -o $@ $<

