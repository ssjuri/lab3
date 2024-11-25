CC = gcc
CFLAGS = -Wall -fPIC
SRCS = add.c subtract.c multiply.c divide.c main.c
OBJS = add.o subtract.o multiply.o divide.o
TARGET_STATIC = main_static
TARGET_SHARED = main_shared
LIBDIR = ./lib

all: static shared

static: $(TARGET_STATIC)
shared: $(TARGET_SHARED)

$(TARGET_STATIC): $(OBJS)
	ar rcs $(LIBDIR)/libarith.a $(OBJS)
	$(CC) main.c -L$(LIBDIR) -larith -o $(TARGET_STATIC)

$(TARGET_SHARED): $(OBJS)
	$(CC) -shared -o $(LIBDIR)/libarith.so $(OBJS)
	$(CC) main.c -L$(LIBDIR) -larith -o $(TARGET_SHARED)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET_STATIC) $(TARGET_SHARED) $(LIBDIR)/libarith.*

