# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falarcon <falarcon@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 09:55:09 by falarcon          #+#    #+#              #
#    Updated: 2023/02/14 21:44:20 by falarcon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c \
			ft_printf_utils.c	

OBJS	= ${SRC:.c=.o}				#convierte los .c en .o

GCC		= gcc						#establece el compilador a utilizar

FLAGS	= -Wall -Werror -Wextra		#banderas para el compilador

RM		= rm -rf					#comando para eliminar archivos o directorios

AR		= ar rcs 					#funcion para crear libreria

all		:	${NAME}					#especifica que el objetivo principal es la creación de la librería

${NAME}	:	${OBJS}					#para crear la librería se deben utilizar los objetos especificados en OBJS
			${AR} ${NAME} ${OBJS}

c.o		:							#especifica utilizar las banderas a la hora de crear los .o a partir de los .c
			${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

clean	:							#especifica que se deben eliminar los archivos objeto
			${RM} ${OBJS}

fclean	: 	clean					#para ejecutar la regla clean y luego eliminar la librería
			${RM} ${NAME}

re		:	fclean all 				#especifica que se deben ejecutar las acciones de las reglas fclean y all

.PHONY	:	all clean fclean re		#especifica que las reglas no son archivos, sino acciones a realizar
