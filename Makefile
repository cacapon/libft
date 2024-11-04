TARGET	= libft.a
CC 		= gcc -Wall -Wextra -Werror
SRCS	= 	ft_atoi.c     ft_isdigit.c  ft_memmove.c     ft_split.c     ft_strlcpy.c  ft_strtrim.c	\
			ft_bzero.c    ft_isprint.c  ft_memset.c      ft_strchr.c    ft_strlen.c   ft_substr.c	\
			ft_calloc.c   ft_itoa.c     ft_putchar_fd.c  ft_strdup.c    ft_strmapi.c  ft_tolower.c	\
			ft_isalnum.c  ft_memchr.c   ft_putendl_fd.c  ft_striteri.c  ft_strncmp.c  ft_toupper.c	\
			ft_isalpha.c  ft_memcmp.c   ft_putnbr_fd.c   ft_strjoin.c   ft_strnstr.c				\
			ft_isascii.c  ft_memcpy.c   ft_putstr_fd.c   ft_strlcat.c   ft_strrchr.c 
OBJS	= $(SRCS:.c=.o)

BONUS_S = ft_lstnew.c	ft_lstadd_front.c
BONUS_O = $(BONUS_S:.c=.o)

all: $(TARGET)

bonus: $(OBJS) $(BONUS_O)
	ar rc $(TARGET) $(OBJS) $(BONUS_O)

$(TARGET): $(OBJS)
	ar rc $@ $^

%.o: %.c
	$(CC) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all


.PHONY: all clean fclean re bonus