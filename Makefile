SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

EXEC = task1 task2 task3 task4 task5
all: $(EXEC)

$(EXEC): %: %.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

move:
	mv $(EXEC) *.c *.o finsh/
