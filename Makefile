######################################################################################
# DEP = all the objects that we want watched for changes, which will trigger a rebuild
# SRC = all source objects we want included in the final executable
######################################################################################

DEP=	forsort-macro.h

SRC=	forsort.c \
	main.c \
	nqsort.c \
	timsort.c \
	WikiSort.c \
	timsort_r.c \
	grail_sort.c 

INCDIR= include
SRCDIR= src
OBJDIR= obj

######################################################################################
# What we want the final executable to be called
######################################################################################

BIN=ts

######################################################################################
# COMPILE TIME OPTION FLAGS
######################################################################################

#CC= gcc
CC=clang
OPT_FLAGS= -O2 -march=native -mtune=native -falign-functions=32 -falign-loops=32
DEBUG_FLAGS= -Wall # -g -pg --profile -fprofile-arcs -ftest-coverage
LIBS=

######################################################################################
# The rules to make it all work.  Should rarely need to edit anything below this line
######################################################################################

CFLAGS= -I$(INCDIR) $(DEBUG_FLAGS) $(OPT_FLAGS)
LDFLAGS= $(DEBUG_FLAGS) $(OPT_FLAGS)

DEPS= $(patsubst %,$(INCDIR)/%,$(DEP)) Makefile

_OBJ=$(SRC:.c=.o)
OBJ= $(patsubst %,$(OBJDIR)/%,$(_OBJ))

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o gmon.out $(SRCDIR)/*~ core $(INCDIR)/*~ $(BIN) $(OBJDIR)/*.gcda $(OBJDIR)/*.gcno
	(test -d $(OBJDIR) && rmdir $(OBJDIR)) || true
