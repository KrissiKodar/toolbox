CXX = gcc
CXXFLAGS = -Wall #-Werror

# List all .c source files in the directory
SRCS = $(wildcard *.c)

# Derive the object file names from the source file names
OBJS = $(SRCS:.c=.o)

# Name of the main file (replace with your main file name)
MAIN = main.c

# Name of the output executable
TARGET = myprogram

# Automatic library detection
LDLIBS = -lm

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDLIBS)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
