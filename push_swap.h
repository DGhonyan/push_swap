#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "colors.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_list {
	int				num;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	check_args(int argc, char **argv, char *s);

//Errors
void	err(char *msg, char **arr, char *s);
void	err_lst(char *msg, char **arr, char *s, t_list *lst);
//Errors

char	*sewing_machine(char **argv);

void	free_list(t_list *lst);
int		lstsize(t_list *lst);


void	_index(t_list *lst);

t_list	*allocate_list(char *s);

t_list	*lstnew(int num, int index, t_list *prev);  



#endif