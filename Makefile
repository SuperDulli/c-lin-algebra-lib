NAME = test_matrix_lib

SRCS	= vector.c \
			# matrix.c
HEADERS	= $(patsubst %.c,%.h,$(SRCS))
OBJDIR	= obj
OBJS	= $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

all: $(NAME)

clean:
	$(RM) -r $(NAME).dSYM
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $< -o $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: all clean fclean re
