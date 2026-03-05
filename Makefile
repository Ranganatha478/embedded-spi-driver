CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/spi.c src/spi_registers.c
TARGET = spi_demo

all:
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)