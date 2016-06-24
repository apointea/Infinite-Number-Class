# --- COLOR --- #
RED=\033[31m[-]
GREEN=\033[32m[+]
YELLOW=\033[33m[!]
BLUE=\033[34m[*]
MAGENTA=\033[35m
CYAN=\033[36m[*]
CLEAR=\033[0m

# --- GENERAL --- #
CC			= g++
CFLAGS		= -Wall -Werror -Wextra

# --- PRODUCT --- #
IDENTIFIER	= INFINIT_NUMBER
NAME		= run

# --- SOURCES --- #
SRCS_DIR	= srcs/
SRCS		= main.cpp
SRCS		+= InfNum.class.cpp

OBJS_DIR	= objs/
OBJS		= $(SRCS:.cpp=.o)

# --- INCLUDES --- #
INCLUDES	= -I includes

# --- RULES --- #
all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR), $(OBJS))
	@printf "$(CYAN) $(IDENTIFIER) $(CLEAR)Link $(@)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@if [ ! -d $(OBJS_DIR) ]; then mkdir $(OBJS_DIR); fi
	@printf "$(BLUE) $(IDENTIFIER) $(CLEAR)Compiling $(<)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@printf "$(YELLOW) $(IDENTIFIER) $(CLEAR)delete $(OBJS_DIR)\n"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@printf "$(YELLOW) $(IDENTIFIER) $(CLEAR)delete $(NAME)\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
