# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 12:40:14 by dabeloos          #+#    #+#              #
#    Updated: 2019/01/14 13:39:04 by dabeloos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

C_FILES		= apply_ornament.c \
			  bases.c \
			  char_conversion.c \
			  decode_format.c \
			  float_bits_conversion.c \
			  float_bits_conversion_support.c \
			  float_extraction.c \
			  float_extraction_support.c \
			  handle_c.c \
			  handle_d.c \
			  handle_f.c \
			  handle_i.c \
			  handle_o.c \
			  handle_p.c \
			  handle_pctg.c \
			  handle_s.c \
			  handle_u.c \
			  handle_x.c \
			  handle_xmaj.c \
			  init_clean.c \
			  inspect_flags.c \
			  inspect_flags_support.c \
			  printf.c \
			  signed_conversion.c \
			  str_conversion.c \
			  unsigned_conversion.c

O_FILES		= $(C_FILES:.c=.o)

FLAGS		= -c -Wall -Wextra -Werror

$(NAME):
			gcc $(FLAGS) $(C_FILES) -I includes
			ar -rcs $(NAME) $(O_FILES)

all:		$(NAME)

clean:
			rm -f $(O_FILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: clean fclean all re
