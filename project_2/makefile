# the compiler to be used
CC = gcc

# compiler flags
CFLAGS = -Wall 

# the build target executable
TARGET = project2

all: $(TARGET)
	
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)

run:
	./$(TARGET) 15 

