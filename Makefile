CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = src/main.c
TARGET = pomodoro

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)