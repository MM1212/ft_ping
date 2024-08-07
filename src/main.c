/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:17:11 by martiper          #+#    #+#             */
/*   Updated: 2024/04/09 14:01:53 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"
#include <io.h>

static bool init(t_ping* data) {
  ft_bzero(data, sizeof(t_ping));
  data->io = cli_begin("ft_ping", data);
  if (!data->io)
    return false;
  return true;
}

int main(int ac, char** av) {
  t_ping data;
  bool exit_request;

  if (!init(&data))
    return EXIT_FAILURE;

  if (!io_run(&data, ac, av, &exit_request))
    return EXIT_FAILURE;
  if (exit_request)
    return EXIT_SUCCESS;
  data.destination.ip = av[1];
  if (!start_ping(&data))
    return data.exit_code;
  return EXIT_SUCCESS;
}
