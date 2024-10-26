TARGET	= libft.a
CC 		= gcc -Wall -Wextra -Werror
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rc $@ $^

%.o: %.c
	$(CC) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re