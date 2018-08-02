/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:13:46 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/02 13:42:33 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
#define VM_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "op.h"

typedef struct			s_rule
{
	int					aff;
	int					visual;
	int					dump;
}						t_rule;

typedef struct			s_player
{
	unsigned char		*p_name;
	unsigned char		*p_comment;
	unsigned int		*p_code;
	unsigned int		p_id;
	int					p_size;
	int					p_live;
	int					stand;
	struct s_player		*next;
	unsigned int		last_live;
	int					i;
}						t_player;

typedef struct			s_pc
{
	int					carry;
	unsigned int		parent;
	unsigned int		reg[16];
	int					live;
	int					command;
	int					cicles;
	int					size;
	unsigned int		arg[3];
	struct s_pc			*next;
	int					change;
}						t_pc;

typedef struct			s_op
{
	char				*name;
	int					arg;
	int					weight[3];
	int					number;
	int					cicles;
	char				*des;
	int					codage;
	int					carry;
	int					label;
}						t_op;

void			get_command(unsigned char *map, t_pc *pc);
int				check_cycle(int count, int j, int cycle, t_player *p);
t_op			op_tab[17];
void			set_bit(int place, unsigned char *map, unsigned int number);
void			print_map(unsigned char *map, t_pc *pc);
void			solve(t_player *p, unsigned char *map, t_pc *pc_1);
char			*ft_dec_to_binary(int tmp);
int				bit_mask(int stand, int size);
int				find_weight(int stand, int cmd);
unsigned int	take_arg(unsigned char *map, int size, int stand);
int				get_map(unsigned char *map, int coord);
int				take_bit(t_pc *pc, int number, int arg);
int				red_arg(unsigned char *map, t_pc *pc, int size);
void			sti(unsigned char *map, t_pc **pc);
void			put_in_map(t_player *p, unsigned char *map);
void			zjmp(unsigned char *map, t_pc **pc);
void			live(unsigned char *map, t_player *p, t_pc *pc);
void			and(unsigned char *map, t_pc **pc);
void			st(unsigned char *map, t_pc **pc);
void			ld(unsigned char *map, t_pc **pc);
void			lld(unsigned char *map, t_pc **pc);
void			aff(unsigned char *map, t_pc **pc);
void			lfork_1(unsigned char *map, t_pc *pc, t_pc **main);
void			copy_pc(t_pc *pc1, t_pc *pc2, int stand, unsigned char *map);
void			fork_1(unsigned char *map, t_pc *pc, t_pc **main);
void			xor(unsigned char *map, t_pc **pc);
void			or(unsigned char *map, t_pc **pc);
void			add(unsigned char *map, t_pc **pc);
void			sub(unsigned char *map, t_pc **pc);
void			ldi(unsigned char *map, t_pc **pc);
void			lldi(unsigned char *map, t_pc **pc);
t_player		*read_p_from_f(char *name, int id);
void			delete_pc(t_player *p, t_pc **pc);
int				set_place(int place);
int				c_c_sti(int codege);
int				get_size(unsigned char *map, int cmd, int size);
int				c_c_ld_lld(int codage);
int				c_c_sti(int codage);
int				c_c_add_sub(int codage);
int				c_c_and_or_xor(int codage);
int				c_c_ldi_lldi(int codage);
int				c_c_st(int codage);
int				c_c_aff(int codage);
int				create_with_number(t_player **p, int size, int i, char **argv);
int				try_to_read(t_player **p, char *str, int nbr);
int				read_dump(t_rule *rule, char **argv, int argc, int i);
t_pc			*create_pc(t_player *p);
int				count_live(t_player *p, t_pc *pc, unsigned char *map);

#define BUF_SIZE 1
#endif
