# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 12:37:13 by mabril            #+#    #+#              #
#    Updated: 2024/08/30 18:31:47 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

#--- LIBRARIES AND HEADERS ---#

HEADER_FILES	=	push_swap.h
HEADERS			=	$(addprefix $(INCDIR)/, $(HEADER_FILES))

LIBFT_DIR		=	${LIBDIR}/libft
BUILDLIB		=	make -C ${LIBFT_DIR}
CLEANLIB		=	make fclean -C ${LIBFT_DIR}

#--- COMMAND VARIABLES ---#

CC		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror -g
MK		=	mkdir -p
RM		=	rm -rf

#--- SOURCE, INCLUDE, LIBRARY AND BINARIES DIRECTORIES ---#

INCDIR	=	inc
LIBDIR	=	lib
SRCDIR	=	src
BINDIR	=	bin

#--- SOURCES ---#

SRCS	=	main.c utils.c 
SRC		=	$(addprefix $(SRCDIR)/, $(SRCS))
BIN     =	$(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRC))

#--- RULES ---#

$(BINDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	@$(MK) $(@D)
	@echo "${DARKGRAY}Compiling : $(@F) ... ${DEFAULT}"
	@$(CC) $(CFLAGS) -c $< -o $@


all			: ${NAME} 

${NAME}		: ${BIN}
	@${BUILDLIB}
	@$(CC) ${CFLAGS} ${BIN} -o ${NAME} -L${LIBFT_DIR} -lft
	@echo "${GREEN}${NAME} successfully created. 🌐${DEFAULT}"

clean		:
	@${RM} ${BINDIR}
	@echo "${YELLOW}Binary files successfully removed 🗑${DEFAULT}"

fclean		: clean
	@${CLEANLIB}
	@${RM} ${NAME} ${LIBFT_NAME}
	@echo "${RED}Executables successfully removed 🗑${DEFAULT}"

re	 		: fclean all

#--- PHONY ---#

.PHONY	 	: all clean fclean re

# NAME = push_swap

# SRCS = main.c ft_split.c ft_calloc.c utils.c ft_putstr_fd.c ft_bzero.c ft_substr.c ft_strdup.c ft_strlen.c\

# OBJS = $(SRCS:.c=.o)

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# RM = rm -f

# all :	$(NAME)

# $(NAME) : $(OBJS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
	
# clean :
# 	$(RM) $(OBJS)

# fclean : clean 
# 	$(RM) $(NAME)

# re : fclean all


