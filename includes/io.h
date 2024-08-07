/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:06:35 by martiper          #+#    #+#             */
/*   Updated: 2024/04/09 12:14:04 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cli.h>
#include <ping.h>

bool io_run(t_ping* data, int argc, char** argv, bool* exit_request);
bool io_describe_verbose_options(t_cli_handle* cli);

