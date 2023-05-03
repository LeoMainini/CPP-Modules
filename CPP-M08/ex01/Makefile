#COLORS	||	0; -> Reg	|	1; -> Bold	|	4; -> Underline	|	;9 -> H. Intensity	||
Color_Off	= \033[0m
Black		= \033[0;30m
Red			= \033[0;31m
Green		= \033[0;32m
Yellow		= \033[0;33m
Blue		= \033[0;34m
Purple		= \033[0;35m
Cyan		= \033[0;36m
White		= \033[0;37m
BBlack		= \033[1;30m
BRed		= \033[1;31m
BGreen		= \033[1;32m
BYellow		= \033[1;33m
BBlue		= \033[1;34m
BPurple		= \033[1;35m
BCyan		= \033[1;36m
BWhite		= \033[1;37m
UBlack		= \033[4;30m
URed		= \033[4;31m
UGreen		= \033[4;32m
UYellow		= \033[4;33m
UBlue		= \033[4;34m
UPurple		= \033[4;35m
UCyan		= \033[4;36m
UWhite		= \033[4;37m
IBlack		= \033[0;90m
IRed		= \033[0;91m
IGreen		= \033[0;92m
IYellow		= \033[0;93m
IBlue		= \033[0;94m
IPurple		= \033[0;95m
ICyan		= \033[0;96m
IWhite		= \033[0;97m

SRCS	= 	main.cpp Span.cpp

OBJS	= $(SRCS:.cpp=.o)

CC		= c++

CFLAGS	= -Wall -Werror -Werror

CSTD	= -std=c++98

DEBUG	= 1

DFLAGS = -ggdb -fsanitize=address -Wshadow

INC = -I .

NAME	= tempy

all:	$(NAME)

ifeq ($(DEBUG),0)

%.o: %.cpp
	@printf "$(Purple)Compiling $@\n$(Color_Off)"
	@$(CC) $(CFLAGS) $(CSTD) -c $< -o $@

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(CSTD) $(OBJS) -o $(NAME)
	@printf "$(BBlue)Compilation complete\n$(Color_Off)"

else

%.o: %.cpp
	@printf "$(Purple)Compiling $@ with debug flags\n$(Color_Off)"
	@$(CC) $(CFLAGS) $(CSTD) $(DFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(CSTD) $(DFLAGS) $(OBJS) -o $(NAME)
	@printf "$(BBlue)Compilation with debug flags complete\n$(Color_Off)"

endif

clean:	
		@printf "$(IRed)Removing object files\n$(Color_Off)"
		@rm -f $(OBJS)

fclean:	clean
		@printf "$(Red)Removing program files\n$(Color_Off)"
		@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean