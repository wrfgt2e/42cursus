/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_process2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:16:05 by gipark            #+#    #+#             */
/*   Updated: 2021/02/13 15:43:21 by hjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		add_more_args(t_cmd *cmd, char **split)
{
	int		i;
	char	*tmp;

	i = ft_count_split(split) - 1;
	tmp = cmd->cmd;
	cmd->cmd = ft_strdup(split[0]);
	free(tmp);
	while (i > 0)
	{
		add_token_front(&cmd->args, create_arg_token(split[i], T_WORD));
		i--;
	}
}

t_token		*add_more_args2(t_cmd *cmd, t_token **token, char **split)
{
	t_token *new;
	t_token *end_new;
	t_token *next;

	new = token_split_to_list(split);
	end_new = new;
	while (end_new->next)
		end_new = end_new->next;
	next = (*token)->next;
	end_new->next = next;
	if ((*token)->next)
		(*token)->next->prev = end_new;
	if ((*token)->prev)
		(*token)->prev->next = new;
	else
	{
		cmd->args = new;
		free((*token)->word);
		free(*token);
		return (end_new);
	}
	free((*token)->word);
	free(*token);
	ft_free_split(&split);
	return (end_new);
}

void		process_args2(t_cmd *cmd)
{
	int		env;
	char	**split;

	env = 0;
	if (cmd->cmd && cmd->cmd[0] == '$')
		env = 1;
	if (cmd->cmd)
		cmd->cmd = handle_quotes(cmd->cmd, 1);
	if (env)
	{
		split = ft_ssplit(cmd->cmd, " \n");
		if (ft_count_split(split) > 1)
			add_more_args(cmd, split);
		ft_free_split(&split);
	}
	if (env && ft_strlen(cmd->cmd) == 0)
		ft_strdel(&cmd->cmd);
}

void		process_args_env(t_cmd *cmd)
{
	t_list	*tmp;

	tmp = cmd->env_list;
	while (tmp)
	{
		tmp->content = handle_quotes(tmp->content, 1);
		tmp = tmp->next;
	}
}

void		process_args(t_cmd *cmd)
{
	t_token	*tmp;

	tmp = cmd->args;
	while (tmp)
	{
		tmp->word = handle_quotes(tmp->word, 1);
		if (ft_strlen(tmp->word) == 0)
			remove_redirect(tmp, &cmd->args);
		tmp = tmp->next;
	}
	process_args2(cmd);
}
