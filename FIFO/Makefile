CC=gcc

SRCS1=r_fifo.c
OBJS1=$(SRCS1:.c=.o)
EXEC1=r_fifo

SRCS2=w_fifo.c
OBJS2=$(SRCS2:.c=.o)
EXEC2=w_fifo

start: $(OBJS1) $(OBJS2)
	$(CC) -o $(EXEC1) $(OBJS1)
	$(CC) -o $(EXEC2) $(OBJS2)
	@echo "-----------------------------OK-----------------------"

.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	rm -rf $(EXEC1) $(OBJS1)
	rm -rf $(EXEC2) $(OBJS2)
