include	Makefile.config

PROJECT=flux-arena
SRCC=flux-arena.c \
	 fx-ai.c \
	 fx-display.c \
	 fx-physics.c \
	 fx-state.c \
	 fx-settings.c \
	 fx-credits.c \
	 fx-menu.c \
	 fx-title.c \
	 fx-arena-1.c

SRCS=
SRCH=
STRUCT_S=$(wildcard struct/*.s)
GFX_S=$(wildcard gfx/data/*.s)
OBJS=$(SRCC:.c=.o) $(SRCS:.s=.o)
OBJS=$(SRCC:.c=.o) $(SRCS:.s=.o) $(GFX_S:.s=.o) $(STRUCT_S:.s=.o)
OTHEROBJS=
RMVLIBS=display.o interrupt.o sound.o fb2d.o rmvlib.a

DISTFILES=Makefile Makefile.config Makefile.example README $(SRCC) $(SRCH) $(SRCS) $(OTHEROBJS)

TARFILE=$(PROJECT).tar.gz

all: .depend $(PROJECT).cof $(PROJECT).bin

.PHONY: all dist alpine bjl debug skunk reset

$(PROJECT).cof: $(SRCH) $(OBJS) Makefile $(OTHEROBJS)
	$(ALN) $(ALNFLAGS) -e -o $(PROJECT).cof crt0.o $(OBJS) $(OTHEROBJS) $(RMVLIBS) jlibc.a libgcc.a 

$(PROJECT).bin: $(SRCH) $(OBJS) Makefile $(OTHEROBJS)
	$(ALN) $(ALNFLAGS) -n -o $(PROJECT).bin crt0.o $(OBJS) $(OTHEROBJS) $(RMVLIBS) jlibc.a libgcc.a 

%.o: %.s
	$(MADMAC) $(MACFLAGS) $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

dist: $(PROJECT).cof $(PROJECT).bin
	mkdir -p $(PROJECT)
	cp -a $(DISTFILES) $(PROJECT).cof $(PROJECT).bin $(PROJECT)
	tar cfvzh $(TARFILE) $(PROJECT)
	rm -rf $(PROJECT)

alpine: $(PROJECT).cof
	$(RDB) $(PROJECT).cof

bjl: $(PROJECT).bin
	$(LO) -8 $(PROJECT).bin

debug: $(PROJECT).cof
	$(WDB) $(PROJECT).cof

skunk: $(PROJECT).cof
	$(JCP) $(PROJECT).cof

reset:
	$(JCP) -r

clean:
	rm -f *~ $(OBJS) $(PROJECT).cof $(PROJECT).bin

.depend: $(SRCC)
	$(CC) -MM $(SRCC) > .depend

-include .depend
