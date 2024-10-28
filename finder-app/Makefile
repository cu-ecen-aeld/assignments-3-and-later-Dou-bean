CC := gcc
CROSS_COMPILE ?=

ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
	CC := $(CROSS_COMPILE)$(CC)
endif

SRC := writer.c
OBJ := $(SRC:.c=.o)
TARGET := writer

all: $(TARGET)

$(TARET): $(OBJ)
	$(CC) -o $@ $^


clean:
	rm -f $(OBJ) $(TARGET)
