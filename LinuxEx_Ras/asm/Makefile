# makefile [this is comment]

OBJECTS = Assignment.o


TARGET = Assignment
SRCS=$(OBJECTS:.o=.s)

$(TARGET): $(OBJECTS)
	gcc -o $@ $+

$(OBJECTS): $(SRCS)
	as -o $@ $<

clean :
	rm -vf $(TARGET) *.o
