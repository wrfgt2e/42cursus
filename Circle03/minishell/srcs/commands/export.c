/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjoo <hjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:52:52 by hjoo              #+#    #+#             */
/*   Updated: 2021/02/03 22:52:53 by hjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_no_args(t_minishell *minishell)
{
	t_list	*tmp;

	tmp = minishell->env_list;
	while (tmp)
	{
		ft_lstadd_back(&minishell->sort_env_list, ft_lstnew(tmp->content));
		tmp = tmp->next;
	}
	ft_sort_list(&minishell->sort_env_list, ft_strcmp);
	env_cmd_export(&minishell->sort_env_list);
	ft_lstclear(&minishell->sort_env_list, nothing);
}

int		modify_env_list(t_minishell *minishell, char **split, int ex, int jn)
{
	t_list	*tmp;
	char	*to_free;

	tmp = minishell->env_list;
	while (tmp)
	{
		if (ft_strequ(((t_env*)(tmp->content))->name, split[0]))
		{
			ex != 2 ? ((t_env*)(tmp->content))->tmp = 0 : 0;
			if (ex == 1)
				return (1);
			ex != 2 ? ((t_env*)(tmp->content))->tmp = 0 : 0;
			!jn ? to_free = ((t_env*)(tmp->content))->value : 0;
			if (split[1] && !jn)
				((t_env*)(tmp->content))->value = ft_strndup(split[1], 4096);
			else if (!split[1] && !jn)
				((t_env*)(tmp->content))->value = ft_strdup("");
			split[1] && jn ? ((t_env*)(tmp->content))->value = ft_strjoin_free(
				((t_env*)(tmp->content))->value, split[1]) : 0;
			!jn ? free(to_free) : 0;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	export_cmd2(t_minishell *minishell, t_token *args, char **split, int jn)
{
	int		ex;
	int		i;

	i = -1;
	ex = 0;
	ft_is_in_stri('=', args->word) == -1 ? ex = 1 : 0;
	if (!(modify_env_list(minishell, split, ex, jn)))
		ft_lstadd_back(&minishell->env_list,
			ft_lstnew(create_env(split, ex)));
	if (ft_strequ(split[0], "PATH"))
		parse_bin(minishell);
	minishell->env_array = env_to_array(minishell);
}

void	export_cmd3(t_minishell *minishell, t_cmd *cmd, char **split,
					t_token *args)
{
	char	*to_free;
	int		join;

	join = 0;
	if (ft_str_end(split[0], "+"))
	{
		to_free = split[0];
		split[0] = ft_strndup(split[0], ft_strlen(split[0]) - 1);
		free(to_free);
		join = 1;
	}
	if (ft_strlen(args->word) > 0 && env_valid_character(split[0]))
		export_cmd2(minishell, args, split, join);
	else
	{
		ft_dprintf(2, "%s: %s: `%s': %s\n", minishell->name, cmd->cmd,
			args->word, "not a valid identifier");
		minishell->exit = 1;
	}
}

void	export_cmd(t_minishell *minishell, t_cmd *cmd, int forked)
{
	t_token *args;
	char	**split;

	args = cmd->args;
	minishell->exit = 0;
	if (!args && forked)
	{
		export_no_args(minishell);
		return ;
	}
	while (args)
	{
		split = ft_split_n(args->word, '=', 1);
		export_cmd3(minishell, cmd, split, args);
		ft_free_split(&split);
		args = args->next;
	}
}
