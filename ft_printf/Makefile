NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = Srcs

DIR_O = obj

SRCF :=	HighestFunctions/assembler.c \
		HighestFunctions/char_bin_search.c \
		HighestFunctions/dynamic_buffer.c \
		HighestFunctions/ft_printf.c \
		HighestFunctions/ft_put_color.c \
		HighestFunctions/ft_put_str.c \
		HighestFunctions/ft_set_to_null.c \
		HighestFunctions/ft_strrev.c \
		HighestFunctions/num_len.c \
		HighestFunctions/Parsing/ft_parsing.c \
		HighestFunctions/Parsing/ft_str_after.c \
		HighestFunctions/Parsing/put_data.c \
		HighestFunctions/Parsing/set_flags.c \
		HighestFunctions/Parsing/set_indents.c \
		HighestFunctions/Parsing/set_modificators.c \
		HighestFunctions/Parsing/set_precision.c \
		HighestFunctions/Parsing/string_before.c \
		Char/char.c \
		String/string.c \
		Pointer/ft_itoa_pointer.c \
		Pointer/ft_put_grid_pointer.c \
		Pointer/ft_put_indents_pointer.c \
		Pointer/ft_put_precision_pointer.c \
		Pointer/pointer.c \
		OxX/fill_precision.c \
		OxX/fill_zero_ox.c \
		OxX/ft_caps.c \
		OxX/grid_o.c \
		OxX/grid_x.c \
		OxX/indents_ox.c \
		OxX/itoa_base.c \
		OxX/itoa_u.c \
		OxX/ox.c \
		DI/check_limits_integer.c \
		DI/ft_di.c \
		DI/ft_itoa_int_binary.c \
		DI/ft_itoa_integer.c \
		DI/ft_put_indents_integer.c \
		DI/ft_put_precision_integer.c \
		DI/ft_put_sign_integer.c \
		DI/ft_put_space_integer.c \
		Unsigned/check_limits_unsigned_integer.c \
		Unsigned/ft_itoa_u_bin.c \
		Unsigned/ft_itoa_unsigned.c \
		Unsigned/ft_put_indents_unsigned.c \
		Unsigned/ft_put_precision_unsigned.c \
		Unsigned/ft_unsigned.c \
		Unsigned/num_len_unsigned.c \
		Float/copy_float.c \
		Float/floats.c \
		Float/get_ipart.c \
		Float/indents_flo.c \
		Float/ipart_to_str.c \
		Float/long_arithmetic_divison.c \
		Float/long_arithmetic_operations_for_double.c \
		Float/long_arithmetic_operations_for_longdouble.c \
		Float/long_double.c \
		Float/malloc_protection_funk.c \
		Float/num_to_arr.c \
		Float/other_case_double.c \
		Float/round_ipart.c \
		Float/round_up_functions.c \
		Float/set_plus_flo.c \
		Float/set_precision_flo.c \
		Float/set_space_flo.c

SRCS = $(addprefix $(DIR_S)/,$(SRCF))

OBJF = $(addprefix $(DIR_O)/,$(SRCF:.c=.o))

INCLUDE = MainHeader

all: $(NAME)
	@true

$(NAME): $(DIR_O) $(OBJF)
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJF)
	ranlib $(NAME)

$(DIR_O):
	@mkdir -p obj
	@mkdir -p obj/HighestFunctions
	@mkdir -p obj/HighestFunctions/Parsing
	@mkdir -p obj/Char
	@mkdir -p obj/String
	@mkdir -p obj/Pointer
	@mkdir -p obj/OxX
	@mkdir -p obj/DI
	@mkdir -p obj/Unsigned
	@mkdir -p obj/Float

$(DIR_O)/%.o: $(DIR_S)/%.c
	gcc $(FLAGS) -I $(INCLUDE) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJF)
	@/bin/rm -rf $(DIR_O)
	@make clean -C libft

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft

re: fclean all
