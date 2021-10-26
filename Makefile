PNAME=cserve
IDIR=include
SDIR=src
ODIR=bin

DEPS   := $(shell find $(IDIR) -name "*.h")
SFILES := $(shell find $(SDIR) -name "*.c")
OBJ=$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SFILES))

CFLAGS=-std=c11 -pedantic  -L/usr/local/lib -I$(IDIR)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) $^ -o $(PNAME) $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o
