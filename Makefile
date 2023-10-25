NAME = MSTR
INSTALL_PATH = /home/mohamed/Dev/C/Libs/MSTR
OBJS = mstr.o 
SYSTEM = LINUX
COMPILER = gcc

ifeq (${SYSTEM}, WINDOWS)
	INSTALL_PATH = C:/	
endif

build-dev:
	${COMPILER} mstr.c -o ${NAME}

build-rel:
	${COMPILER} mstr.c -o ${OBJS} 

run:
	./${NAME}

intall:
	ar rcs ${INSTALL_PATH}/lib${NAME}.a ${OBJS}
