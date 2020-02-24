TARGET = bubble_sort
CC     = g++
CFLAGS = -Wall -ansi --std=c++14 -I/usr/include/tsal/
LFLAGS = -ltsal 

all: $(TARGET)

$(TARGET): $(TARGET)
	$(CC) $(CFLAGS) $(TARGET).cpp -o $(TARGET) $(LFLAGS)

clean:
	rm -f $(TARGET) *~ *# *.o
