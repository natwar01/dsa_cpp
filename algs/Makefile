# Compiler and flags
CC = g++
CFLAGS = -Wall -g

# Find all C and C++ source files in the current directory and subdirectories
SOURCES = $(shell find . -name "*.c" -or -name "*.cpp")
OBJECTS = $(SOURCES:.c=.o) $(SOURCES:.cpp=.o)
EXEC = my_program

# Default target to build the program
all: $(EXEC)

# Link object files to create the final executable
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# Rule to compile C files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile C++ files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the generated files
clean:
	rm -f $(OBJECTS) $(EXEC)
