/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:10:04 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/03 18:09:54 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				x;
	struct s_list	*next;
}					t_list;

typedef struct s_mid
{
	t_list			*temp;
	t_list			*last;
	static int		n;
	static int		i;
	static int		md_pnt;
}					t_mid;

//----------------Moviments---------------//
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **b, t_list **a);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a ,t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);

//---------------util-----------------//

size_t		ft_strlen(const char *a);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_atoi(const char *str);

void		insert_end(t_list **root, int value);
t_list		*initialize_list_link(char **argv, t_list *t_list_a);
int			ft_intermedia(char *argv, int delimiter);
int			gv_i_b_a(t_list **a, t_list **b, int position);
int			gv_i(t_list **a, int element);
t_list* 	cloneList(t_list **head);

//--------------util2--------------------//

void		sortList(t_list **a);
int			small_i(t_list **a);
int			big_i(t_list **a);
int			ft_pultimo(t_list **a);
int			ft_meio(t_list **a);
int			cnt_rec(t_list *node);
void		send_desire(t_list **a, t_list **b, int meio, int pnultimo);
void		sort_3(t_list **a);
void		sort_4_elements(t_list **a, t_list **b);
void		sort_5_elements(t_list **a, t_list **b);
int			gv_i_mid(t_list **a);
int			give_value_mid(t_list **a);
void		send_pb(t_list **a, t_list **b, int top, int bottom, int md_pnt);
int			numero_movi(t_list **a, int end);
int			start(t_list **a);
int			end(t_list **a);

//-------------------testing--------------------//

int			midpoint(t_list **a, int i);
void		best_move(t_list **a, t_list **b, int start, int end);
int			sort_biggest_chunks_in_b(t_list **root);
int			i_last(t_list **root, int finish);
int			i_first(t_list **root, int start);
int			md_chunk(t_list **root, int start, int finish);
int			top_small(t_list *b);
int			bot_small(t_list *b);
int			top_big(t_list *b);
int			bot_big(t_list *b);
void		back_ra(t_list **a, int n_control);
void		back_pb(t_list **a, t_list **b, int n_control);
int			find_biggest_chunks_in_a(t_list **root, int n_moviments);
int			find_smallest_chunks_in_a(t_list **root);
void		sort_a(t_list **a, t_list **b, int n_moviments);
void		send_bot_b(t_list **a, t_list **b);
void		send_top_b(t_list **a, t_list **b);
void		send_rest(t_list **a, t_list **b);
void		sort_biggest(t_list **a, t_list **b);

//-----------------------------SORT--------------------------//

int			list_sorted(t_node **root);
void		insert_end(t_node **root, int value);
void		deallocate(t_node **root, int message);
char		write_word(char *dest, const char *from, char set);
char		**ft_split(char const *s, char c);
int			word_count(const char *sr, char delimiter);
void		add_split(char **dst, const char *string, char delimiter);
void		freeAll(char **result);
t_node		*initialize_list(char **argv, t_node *t_list_a);
void		print_array_2d(char **arr_bidimensional);
int			gv_i_b_a(t_list **a, t_list **b, int position);
int			gv_i(t_list **a, int element);
t_list*		cloneList(t_list **head)
void		sortList(t_list **a)
int			small_i(t_list **a)
int			big_i(t_list **a)
int			ft_pultimo(t_list **a)
int			ft_meio(t_list **a)
int			cnt_rec(t_list *node)
void		send_desire(t_list **a, t_list **b, int meio, int pnultimo)
t_node		*ft_split_create_str(t_node *t_list_a, char *argv, char delimiter);
//void		printList(t_node *root);
int			count_items(t_node *root);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isnum_compare(const char *str, t_node *t_list_a);
long int	ft_atoi_check_numbers(const char *str, t_node *t_list_a);


#endif
