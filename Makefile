# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 12:40:14 by dabeloos          #+#    #+#              #
#    Updated: 2019/02/22 15:06:11 by dabeloos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

CHEAD		= ./includes

MAIN_F		= apply_ornament.o \
			  bases.o \
			  decode_format.o \
			  init_clean.o \
			  inspect_flags.o \
			  inspect_flags_support.o \
			  printf.o

HANDLERS_F	= handle_c.o \
			  handle_d.o \
			  handle_f.o \
			  handle_i.o \
			  handle_o.o \
			  handle_p.o \
			  handle_pctg.o \
			  handle_s.o \
			  handle_u.o \
			  handle_x.o \
			  handle_xmaj.o

FLOATS_F	= float_bits_extraction.o \
			  float_extraction.o \
			  float_extraction_support.o

CONVERS_F	= char_conversion.o \
			  float_bits_conversion.o \
			  signed_conversion.o \
			  str_conversion.o \
			  unsigned_conversion.o

POLYADIC_F	= pf_boot.o \
			  pf_init_clean.o

O_F			= $(addprefix ./main/, $(MAIN_F)) \
			  $(addprefix ./handlers/, $(HANDLERS_F)) \
			  $(addprefix ./floats/, $(FLOATS_F)) \
			  $(addprefix ./conversions/, $(CONVERS_F)) \
			  $(addprefix ./polyadic_float/, $(POLYADIC_F))

END_E		= \033[00m
RED_E		= \033[01;31m
GREEN_E		= \033[01;32m
YELLOW_E	= \033[01;33m
PURPLE_E	= \033[01;35m
CYAN_E		= \033[01;36m
WHITE_E		= \033[01;37m
BOLD_E		= \033[1m
UNDERLINE_E	= \033[4m

$(NAME):	$(O_F)
			@ar -rcs $@ $^
			@echo "$(GREEN_E)end compilation$(END_E)"

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -c -o $@ $< -I$(CHEAD)

clean:		
			@rm -f $(O_F)
			@echo "$(PURPLE_E)end clean$(END_E)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(RED_E)end fclean$(END_E)"

re:			fclean all

.PHONY: clean fclean all re
