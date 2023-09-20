NAME_SRV     = server

NAME_CL     = client

CC     = gcc

RM     = rm -rf

SRCS_SRV     =  server.c lib.c

SRCS_CL     =  client.c lib.c

OBJS_SRV        = ${SRCS_SRV:.c=.o}

OBJS_CL        = ${SRCS_CL:.c=.o}

CFLAGS     = -Wall -Wextra -Werror

$(NAME_CL): ${OBJS_CL} ${OBJS_SRV}
	${CC} ${CFLAGS} ${OBJS_SRV} -o ${NAME_SRV} ; ${CC} ${CFLAGS} ${OBJS_CL} -o ${NAME_CL}

all:    ${NAME_CL}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS_SRV}
	${RM} ${OBJS_CL}

fclean: clean
	${RM} ${NAME_SRV}
	${RM} ${NAME_CL}

re:    fclean all
