PROG=test-1 test-2 test-3 test-4
SOURCES=$(wildcard *.c *.h)
ALLOBJS=$(patsubst %.c,%.o,$(wildcard *.c))
OBJS=$(filter-out $(patsubst %,%.o,$(PROG)) main-test-1.o,$(ALLOBJS))

CC=gcc
CFLAGS=-Wall -Wfatal-errors -g -Wincompatible-pointer-types -Werror

all: .depend $(PROG)
$(PROG): $(OBJS)

clean:
	@rm -f *.o
distclean: clean
	@rm -f $(PROG) *~ .depend
.depend deps: $(SOURCES)
	@rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;
include .depend

