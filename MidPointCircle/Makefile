CC = g++
CFLAGS = -fdiagnostics-color=always -g -O
LDFLAGS = -lGL -lGLU -lglut
TARGET = main

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -f $(OBJS) $(TARGET)
