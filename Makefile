CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printchar.c ft_printnbr_base.c ft_printstr.c ft_printaddress.c

OBJ = $(SRC:.c=.o)
HEADER = ft_printf.h
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)  

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean