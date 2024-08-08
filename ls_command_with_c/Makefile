TARGET = my_ls
OBJ = my_ls.o 
SRC = my_ls.c 
DEPS = headers.h 
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -fno-omit-frame-pointer

all : $(TARGET)

$(TARGET) : $(OBJ) $(DEPS)
	gcc $(CFLAGS) -o $(TARGET) $(OBJ) 

$(OBJ) : $(SRC) $(DEPS)
	gcc $(CFLAGS) -c $(SRC)

#run : $(TARGET)
#	./$(TARGET)
clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all