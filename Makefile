# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 12:40:14 by dabeloos          #+#    #+#              #
#    Updated: 2019/01/15 15:30:11 by dabeloos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

C_FILES		= main/apply_ornament.c \
			  main/bases.c \
			  main/decode_format.c \
			  main/init_clean.c \
			  main/inspect_flags.c \
			  main/inspect_flags_support.c \
			  main/printf.c \
			  handlers/handle_c.c \
			  handlers/handle_d.c \
			  handlers/handle_f.c \
			  handlers/handle_i.c \
			  handlers/handle_o.c \
			  handlers/handle_p.c \
			  handlers/handle_pctg.c \
			  handlers/handle_s.c \
			  handlers/handle_u.c \
			  handlers/handle_x.c \
			  handlers/handle_xmaj.c \
			  floats/float_bits_extraction.c \
			  floats/float_extraction.c \
			  floats/float_extraction_support.c \
			  conversions/char_conversion.c \
			  conversions/float_bits_conversion.c \
			  conversions/signed_conversion.c \
			  conversions/str_conversion.c \
			  conversions/unsigned_conversion.c
			  
O_FILES		= $(C_FILES:.c=.o)

FLAGS		= -c -Wall -Wextra -Werror

$(NAME):
			gcc $(FLAGS) $(C_FILES) -Iincludes
			ar -rcs $(NAME) $(O_FILES)

all:		$(NAME)

clean:
			rm -f $(O_FILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: clean fclean all re
