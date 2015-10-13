SRCDIR=src
OBJDIR=obj
INCLUDEDIR=$(SRCDIR)/include

CC=gcc

STDCFLAGS=--std=c11 -march=native -pipe -I$(INCLUDEDIR)
WARNCFLAGS=-Wall -Wextra -Werror -Wshadow -Wimplicit -Werror
OPTIMIZECFLAGS=-O2
GLLIBS=-lGL -lGLEW -lglfw
CFLAGS=$(STDCFLAGS) $(WARNCFLAGS) $(OPTIMIZECFLAGS)

SUBDIRS=$(shell find $(SRCDIR) -type d | grep -v include)
INCLUDEDIRS=$(shell find $(SRCDIR) -type d | grep include)
SRCS=$(foreach sd,$(SUBDIRS),$(wildcard $(sd)/*.c))
HEADERS=$(foreach sd,$(INCLUDEDIRS),$(wildcard $(sd)/*.h))
OBJS=$(foreach source,$(SRCS),$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(patsubst %.c,%.o,$(source))))
OBJSUBDIRS=$(foreach sd,$(SUBDIRS),$(patsubst $(SRCDIR)%,$(OBJDIR)%,$(sd)))

APP=app

all: $(APP)

$(APP): $(OBJSUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(GLLIBS) $(OBJS) -o$(APP)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSUBDIRS):
	mkdir -p $(OBJSUBDIRS)

clean:
	rm -Rf $(OBJDIR) $(APP)
