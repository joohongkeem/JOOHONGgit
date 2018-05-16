CC=gcc
OBJECTS=upper.o\
		useupper.o
#SRCS = $(OBJECTS:.0=.c)
TARGET = upper useupper
all : $(TARGET)

upper: upper.c
	$(CC) -o $@ $<
useupper: useupper.c
	$(CC) -o $@ $<
clean :
	$(RM) $(OBJECTS) $(TARGET)
