# https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CPPFLAGS  = -std=c++11 -Wall -Werror -g -O0

# Set up additional flags for explicitly setting mode
# https://stackoverflow.com/questions/9262456/how-do-i-disable-gcc-optimization-when-using-makefiles
# debug:	CPPFLAGS += -g -O0
ifeq ($(STATIC),1)
CPPFLAGS += -static
endif

ifeq ($(PIE),1)
CPPFLAGS += -pie -fPIE
endif

# The build target 
# TARGET = myprogram

# all: $(TARGET)
confused-target: $(CONFUSED_TARGET).o animal.o shape.o
	$(CC) $(CPPFLAGS) -o $(CONFUSED_TARGET) $(CONFUSED_TARGET).o animal.o shape.o

$(CONFUSED_TARGET).o: $(CONFUSED_TARGET).cc animal.hpp shape.hpp
	$(CC) $(CPPFLAGS) -c $(CONFUSED_TARGET).cc

animal.o: animal.hpp

shape.o: shape.hpp

node: node.cc
	$(CC) $(CPPFLAGS) -o node node.cc

target: $(TARGET).o node.o
	$(CC) $(CPPFLAGS) -o $(TARGET) $(TARGET).o node.o

$(TARGET).o: $(TARGET).cc node.h 
	$(CC) $(CPPFLAGS) -c $(TARGET).cc

node.o: node.h

clean:
	$(RM) $(TARGET)