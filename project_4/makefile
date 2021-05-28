TARGETS = ask4
flags= -Wall -Wextra -Wpedantic -g -O1

# Phony targets. 
.PHONY: all clean

# Targets to build when running `make`
all: $(TARGETS)

# Run `make clean` to delete binaries and object files.
clean:
	rm -rf $(TARGETS) *.o

# Targets to build `factorial_pipes` binary
ask4: ask4.o
	gcc ask4.o -o ask4
ask4.o: ask4.c
	gcc ask4.c -c -o ask4.o



