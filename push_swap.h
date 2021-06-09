/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:10:48 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/07 21:02:38 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define BUFF_SIZE 32

typedef struct s_stack
{
	int				data;
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	int				count_a;
	int				count_b;
	int				min;
	int				max;
	int				med;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

typedef struct s_data
{
	int				a[10000];
	int				count_element;
}					t_data;

int					main(int argc, char **argv);
void				ft_stack_print(t_stack *lst);
int					ft_error(void);
int					error_check(int argc, char **argv);
void				ft_check_int_overflow(char *str);
void				ft_check_str(char *str);
int					check_dup(char **str, int count);
void				check_int_overflow(char *str);
int					check_num(char *str);
void				ft_stacking(t_data *neww, int *buff, int count);
void				ft_separate(int ac, char **av, t_data *neww);
int					ft_max(t_stack *s);
void				ft_sort_3(t_stacks *stacks);
void				ft_sort_5(t_stacks *stacks);
void				ft_quicksort(int *number, int first, int last);
void				ft_duplicate_check(t_data *neww, t_stacks *stacks);
void				ft_search_duplicate(const int *dup, int count);
void				swap(int *a, int *b);
int					ft_is_sorted(t_data *neww);
int					ft_only_spaces(const char *str);
t_stack				*ft_create_stack(int *buff, int count);
void				ft_init_stack(t_data *neww, t_stacks *stacks);
void				ft_free_stack(t_stacks *stacks);
void				ft_null(t_stacks *stacks, t_data *neww);
void				ft_global_sort(t_stacks *stacks);
void				ft_start_sort(t_stacks *stacks);
void				ft_step(t_stack *b, int count);
void				ft_min_step(t_stacks *stacks, t_steps *steps);
void				ft_exec(t_stacks *stacks, t_steps *steps);
int					ft_find_place(
						t_stacks *s, t_stack *b, t_steps *steps, int min);
void				ft_find_place_helper(
						t_stacks *s, t_stack *b, int *action, int *buff);
int					ft_smaller(t_stack *a, int buff, int src);
int					ft_min_count(t_stack *a, int min);
int					get_next_line(const int fd, char **line);
int					ft_stack_sorted(t_stacks *s);
void				ft_read_line(t_stacks *s);
void				ft_instructions(t_stacks *s, char *str);
void				ra(t_stack **a, int i);
void				rb(t_stack **b, int i);
void				rr(t_stacks *s, int i);
void				rra(t_stack **a, int i);
void				rrb(t_stack **b, int i);
void				rrr(t_stacks *s, int i);
void				sa(t_stack *a, int i);
void				sb(t_stack *b, int i);
void				ss(t_stacks *s, int i);
void				pa(t_stacks *s, int i);
void				pb(t_stacks *s, int i);

#endif
