CC = gcc

CFLAGS = -O3
CFLAGS += -std=c99 -fno-builtin
CFLAGS += -pedantic -D _POSIX_C_SOURCE=200809L
CFLAGS += -Wall -Wextra -Werror -Wa,--warn
CFLAGS += -Winit-self -Wswitch-default -Wfloat-equal
CFLAGS += -Wundef -Wshadow -Wuninitialized -Wlogical-op
CFLAGS += -Wvla -Wredundant-decls
CFLAGS += -Wno-missing-profile
CFLAGS += -fno-stack-protector
CFLAGS += -Wno-unused-function
CFLAGS += -I $(INCLUDES_DIR)


INCLUDES_DIR = $(CURDIR)/include
SRC_DIR = $(CURDIR)/src
BIN_DIR = $(CURDIR)/bin

EXEC = decoder-mips-pocket

SRC = $(wildcard $(SRC_DIR)/*.c)

all: all-debug all-release

make-dirs:
	mkdir -p $(BIN_DIR)

all-release: make-dirs
	$(CC) $(CFLAGS) -D NDEBUG $(SRC) -o $(BIN_DIR)/$(EXEC)

all-debug: make-dirs
	$(CC) $(CFLAGS) $(SRC) -o $(BIN_DIR)/$(EXEC)

clean:
	@rm -f $(BIN_DIR)/$(EXEC)
