COMPILE=$(CROSS_COMPILE)gcc
writer: writer.o
	$(COMPILE) -o writer writer.o
writer.o : writer.c
	$(COMPILE) -c writer.c

clean : 
	rm -f writer writer.o