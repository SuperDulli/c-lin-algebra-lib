NAME = test_matrix_lib

vector	= vector.c length.c length_squared.c scalar_mult.c normalize.c add.c sub.c dot.c is_zero.c is_equal.c cross.c

SRCS	= $(addprefix vector/,$(vector)) test_vector.c
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

show:
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)/vector

.PHONY: all clean fclean re show
