CC = gcc

CFLAGS = -Wall -I.

OBJDIR = obj

SRCDIRS = task1 task2 task3 task4 task5 task6

SOURCES = $(wildcard task1/*.c task2/*.c task3/*.c task4/*.c task5/*.c task6/*.c)

OBJECTS = $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

HEADERS = school_h.w

all: $(OBJECTS)

$(OBJDIR)/%.o: task1/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: task2/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: task3/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: task4/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: task5/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: task6/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o

.PHONY: all clean