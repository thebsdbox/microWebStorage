# Makefile for microWebStorage
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings

# STATIC
# CFLAGS  = -s -Os -Wl,--discard-all -Wl,-O1 -Wall -static 

# DYNAMIC
CFLAGS  = -s -Os -Wl,--discard-all -Wl,-O1 -Wall

# the build target executable:
TARGET = microWebStorage

all: $(TARGET)

$(TARGET): main.c
        $(CC) $(CFLAGS) -o $(TARGET) main.c mwsHTTPD.c

clean:
        $(RM) $(TARGET)
