PROGRAM=wlSyncC
LIBNETDIR=../
OBJS=main.o param.o
SRCS=$(OBJS:%.o=%.c)
CFLAGS=-Wall -g -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -I$(LIBNETDIR)/libnetMT/
LDFLAGS= -L$(LIBNETDIR)/libnetMT/ -I/usr/local/include/ -L/usr/local/lib/ -liconv 
LDLIBS= -lnet -lpthread
$(PROGRAM):$(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROGRAM) $(OBJS) $(LDLIBS)

