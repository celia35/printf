NAME = libftprintf.a

SRC = ft_printf.c ft_putstr.c ft_putnbr.c
OBJS = $(SRC:%.c=%.o)

#LIBFT_PATH		=	./libft
#LIBFT			=	$(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wextra -Werror -Wall

RM	= rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rsc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

