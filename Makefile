CC = gcc
LD = ld
AS = as

INCLUDE = /usr/include/gtk-3.0/gtk
EXECUTABLE = test_1.bin
SRC = test_1.c
CFLAGS = -Wno-format -o $(EXECUTABLE) $(SRC) -I$(INCLUDE) -export-dynamic -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0` `pkg-config --cflags --libs MagickWand`

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

debug:
	gdb --symbols=$(EXECUTABLE) -ex 'target remote localhost:1234'

clean:
	rm -rf *.o $(EXECUTABLE)

