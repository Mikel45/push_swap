SRCS	=	./src/bigsort.c ./src/commands.c ./src/init_params.c ./src/lst_utils.c \
			./src/minisort.c ./src/push_swap.c ./src/push_swap_utils.c ./src/utils.c


SRCS_B	=	./bonus/checker.c ./bonus/commands1.c ./bonus/commands2.c ./bonus/lst_utils.c \
			./bonus/utils.c ./bonus/checker_utils.c

OBJ_SRC = ${SRCS:.c=.o}

OBJ_B	= ${SRCS_B:.c=.o}

CC = gcc

NAME = push_swap

BONUS = checker

REM = rm -f

HEADER = ./headers/push_swap.h ./headers/checker.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o:	%.c ${HEADER}
			${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ_SRC}
			${CC} ${FLAGS} ${OBJ_SRC} -o ${NAME}

${BONUS}: ${OBJ_B}
			${CC} ${FLAGS} ${OBJ_B} -o ${BONUS}

all: ${NAME}

bonus: ${BONUS}

clean:
	@${REM} ${OBJ_SRC} ${OBJ_B}

fclean: clean
	@${REM} ${OBJ_SRC} ${OBJ_B} ${NAME} ${BONUS}
	
re: fclean all