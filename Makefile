# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwald <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/22 13:52:40 by dwald             #+#    #+#              #
#    Updated: 2017/11/25 10:56:52 by dwald            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			dwald.filler

SRC_FILES =		algo_part_1.c \
				algo_part_2.c \
				main.c \
				parser.c
				
SRC_PATH =		.

OBJ_PATH =		objs

LIBFT_PATH =	libft

SRC =			$(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJ =			$(addprefix $(OBJ_PATH)/,$(SRC_FILES:.c=.o))

LIBFT =			$(addprefix $(LIBFT_PATH)/,$(LIBFTA))

INC =			includes

LIBFTA =		libft.a

CC =			gcc

FLAGS =			-Wextra -Werror -Wall

GREEN =			\033[0;32m
RED =			\033[0;31m
NC = 			\033[0m

all: $(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT_PATH)
			@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -I./libft/includes -o $(NAME)
			@echo "$(GREEN)player dwald.filler compiled$(NC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
			@mkdir -p $(OBJ_PATH)
			@printf "🐛  $(notdir $<)\r"
			@$(CC) $(FLAGS) -I $(INC) -I./libft/includes -o $@ -c $<

filler:
			rm -rf ./test || true
			rm -rf ./error || true
			./filler_vm -f ./maps/map01 -p1 ./$(NAME)
	
clean:
			/bin/rm -f $(OBJ)
			make fclean -C $(LIBFT_PATH)

fclean:	clean
			/bin/rm -f $(NAME)
			@echo "$(RED)---dwald.filler removed completely---$(NC)"

re:		fclean all

norme:
			norminette $(SRC)
			norminette $(INC_PATH)*.h

.PHONY: all fclean clean re norme filler
