SRCS = main_list.c list.c
EXEC = list

CC = gcc
CCFLAG = -g -Wall

all:
	${CC} ${CCFLAG} ${SRCS} -o ${EXEC}

