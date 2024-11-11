# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 12:37:13 by mabril            #+#    #+#              #
#    Updated: 2024/11/11 13:03:41 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

#--- LIBRARIES AND HEADERS ---#
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

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

SRCS	=	main.c utils.c error.c regles.c trie.c init.c regles_a.c regles_b.c conditions.c utils_2.c
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

# ************test visualizer**********

# git clone https://github.com/o-reo/push_swap_visualizer.git
# cd push_swap_visualizer
# mkdir build
# cd build
# cmake ..
# make
# ./bin/visualizer