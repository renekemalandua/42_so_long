# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akemalan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/20 15:50:09 by akemalan          #+#    #+#              #
#    Updated: 2025/09/20 17:07:20 by akemalan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS =  init/map.c\
	init/player.c\
	check/check_map.c\
	check/check_utils.c\
	graphics/render.c\
	graphics/render_utils.c\
	events/handlers.c\
	events/moves.c\

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = mlx_linux
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = cc
CFLAGS = -Wall -Werror -Wextra -g # -MMD
MFLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft
MAP    = maps/big.ber

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = so_long
RM = rm -f

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME} draw

$(NAME): $(OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS)
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

draw:
	@clear
	@echo "$(BLUE) \
 ____   ___            _     ___  _   _  ____\n \
/ ___| / _ \\          | |   / _ \\| \\ | |/ ___|\n \
\\___ \\| | | |         | |  | | | |  \\| | |  _\n \
 ___) | |_| |         | |__| |_| | |\\  | |_| |\n \
|____/ \\___/   _____  |_____\\___/|_| \\_|\\____|\n \
              |_____|\n \
\n \
            WELCOME TO SO_LONG!\n \
$(RESET)"
	@echo "➡️  Para jogar, use: make run"
	@echo "🎉 Se divirta! 🎮"

run: $(NAME)
	@echo "🎮 Iniciando o jogo com $(MAP)... Se divirta! 🚀"
	@./$(NAME) $(MAP)

clean:
	@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
	@${RM} ${OBJS}
	@${RM} -r ${OBJ_DIR}
	@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re
