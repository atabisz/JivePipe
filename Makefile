VERSION = 1.0.0
CC      = gcc
CFLAGS  = -O2 -Wall -Wextra -std=c99
TARGET  = jivepipe
SRCS    = src/main.c src/translator.c
HEADERS = src/translator.h src/dictionary.h

$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)
	strip $(TARGET)

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: install clean
