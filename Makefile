CC = gcc
CFLAGS =  -std=c99 -O3 -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs

# GCC warnings that Clang doesn't provide:
ifeq ($(CC),gcc)
    CFLAGS += -Wjump-misses-init -Wlogical-op
endif

OBJ=main.o
TARGET=main.exe

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: all
all: $(OBJ)
	$(CC) -o $(TARGET) $^ $(CFLAGS)

.PHONY: clean
clean:
	del $(TARGET) $(OBJ)


