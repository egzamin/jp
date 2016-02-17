sources = wprawki00.c wprawki17.c

programs = $(basename $(sources))
objects = $(addsuffix .o, $(programs))

CFLAGS = -Wall -std=c11 -I /opt/X11/include
LDFLAGS = -L /opt/X11/lib
LDLIBS = -lGL -lGLU -lglut -lm

.PHONY : clean
clean :
	-$(RM) $(objects) $(programs) *~

all : $(programs)
