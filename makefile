# https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -std=c++11 -g -Wall -Werror

# The build target 
# TARGET = myprogram

# all: $(TARGET)

# $(TARGET): $(TARGET).c
#             $(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
node: node.cc 
	$(CC) $(CFLAGS) -o node node.cc 

clean:
	$(RM) $(TARGET)