#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

typedef struct s_list {
	int				num;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}

# include <unistd.h>
# include <stdlib.h>

# include "colors.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	check_args(int argc, char **argv);

#endif