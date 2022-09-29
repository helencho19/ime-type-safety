# https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CPPFLAGS  = -std=c++11 -Wall -Werror

# Set up additional flags for explicitly setting mode
# https://stackoverflow.com/questions/9262456/how-do-i-disable-gcc-optimization-when-using-makefiles
debug:	CPPFLAGS += -g -O0

# The build target 
# TARGET = myprogram

# all: $(TARGET)

# $(TARGET): $(TARGET).c
#             $(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
debug: $(TARGET).cc 
	$(CC) $(CPPFLAGS) -o $(TARGET) $(TARGET).cc
# node: node.cc 
# 	$(CC) $(CPPFLAGS) -o node node.cc 

clean:
	$(RM) $(TARGET)