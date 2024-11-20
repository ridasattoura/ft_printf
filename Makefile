SRC =  ft_puthex.c ft_putstr.c ft_putchar.c  ft_putnbr.c \
		ft_putunbr.c ft_printf.c ft_putnbr_base.c
CC = cc 
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
OBSRC = ${SRC:.c=.o}
NAME = libftprintf.a
AR = ar rcs


${NAME}: ${OBSRC} 

all: ${NAME} 


%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $<
	$(AR) $(NAME) $@

clean :
	rm -f ${OBSRC}

fclean : clean
	rm -f ${NAME}
re : fclean all 