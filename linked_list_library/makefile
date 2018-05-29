LDFLAG = -o
CFLAG = -c
CC = gcc
.PHONY: clean
exe: linkedList.o test.o
	$(CC) $^ $(LDFLAG) $@
test.o : test.c linkedList.h
	$(CC) $(CFLAG) $<
linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAG) $<

clean: 
	rm *.o *.exe