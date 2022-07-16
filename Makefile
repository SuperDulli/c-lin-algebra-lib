NAME = lin_algebra_lib

VECTOR_N= vector_tests
VECTOR	= vector.c length.c length_squared.c scalar_mult.c normalize.c add.c sub.c dot.c is_zero.c is_equal.c cross.c
VECTOR_S= $(addprefix vector/,$(VECTOR)) test_vector.c

MATRIX_N= matrix_tests
MATRIX	= matrix.c scalar_mult.c mult.c add.c transpose.c
MATRIX_S= $(addprefix matrix/,$(MATRIX)) test_matrix.c

# SRCS	=
HEADERS	= $(patsubst %.c,%.h,$(SRCS))
OBJDIR	= obj
OBJS	= $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
LFLAGS	= -lm

# all: $(NAME)
all: $(VECTOR_N) $(MATRIX_N)

clean:
	$(RM) -r *.dSYM
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(VECTOR_N)
	$(RM) $(MATRIX_N)

re: fclean all

show:
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)

v: $(VECTOR_N)
	./$^

m: $(MATRIX_N)
	./$^

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)/VECTOR
	mkdir $(OBJDIR)/MATRIX

$(VECTOR_N): $(VECTOR_S)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(MATRIX_N): $(MATRIX_S)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

.PHONY: all clean fclean re show v m
