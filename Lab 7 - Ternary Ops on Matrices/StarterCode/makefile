# Variables to hold commands that are needed. For example wherever CFLAGS is will use the -Wall and -g flags during compilation

CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=LAB7

# Wildcards to hold all files ending with .c, for compilation, in the src folder and all subdirectories of it
C_SRCS := \
	$(wildcard *.c) \
	$(wildcard src/*.c) \
	$(wildcard src/**/*.c)

# Same thing but with files ending in .h
HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h)

# Take sources to make an object file list. Replaces .c with .o in the root directory by a wildcard. Then gets list of .o files through filter command
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# Executes the echo if build is successful
all: build
	@echo "All Done"

# Attempts to build/compile the program
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# Gets root directory source files and saves to own directory using mkdir. Uses dir to get directory prefix
bin/%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Same thing but searches for src/%.c files instead of %.c
bin/%.o: src/%.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes object/bin files
clean:
	rm -f $(TARGET)
	rm -rf bin

# Runs the program assuming the build was successful
run: build
	./$(TARGET) input.txt

# Displays which files are being used
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"

