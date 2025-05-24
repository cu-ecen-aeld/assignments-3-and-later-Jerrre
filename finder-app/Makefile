COMPILE=$(CROSS_COMPILE)gcc
all: writer
writer: writer.o
	$(CC) $(LDFLAGS) -o writer writer.o
writer.o : writer.c
	$(CC) $(CCFLAGS) -c writer.c

clean : 
	rm -f writer writer.o