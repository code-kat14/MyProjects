TARGET = my_mastermind
OBJ = my_mastermind.o main.o
SRC = my_mastermind.c main.c
DEPS = headers.h 
CFLAGS = -Wall -Wextra -Werror

all : $(TARGET)

$(TARGET) : $(OBJ) $(DEPS)
	gcc $(CFLAGS) -o $(TARGET) $(OBJ) 

$(OBJ) : $(SRC) $(DEPS)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all