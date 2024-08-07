/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:14:10 by martiper          #+#    #+#             */
/*   Updated: 2024/04/09 12:19:22 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

#ifdef DEBUG

static void debug_settings(t_cli_option* opt, t_ping* data) {
  data->io->print();
  opt->_handle->settings.should_exit = true;
  opt->_handle->settings.run_cb_only_once = true;
}

static bool add_debug(t_cli_handle* cli) {
  t_cli_option_builder* opt = cli->new_option(
    "debug",
    "output debug information and exit",
    true
  );
  if (opt == NULL)
    return false;
  opt->set_cb((t_cli_option_cb)debug_settings);
  return opt->end() != NULL;
}

#endif

bool io_run(t_ping* data, int ac, char** av, bool* exit_request) {
  *exit_request = false;
  t_cli_handle* handle = data->io;
  if (
    !io_describe_verbose_options(handle) ||
#ifdef DEBUG
    !add_debug(handle) ||
#endif
    !handle->parse(ac, av)
    ) {
    handle->output_error();
    ft_fprintf(STDERR_FILENO, "Try '%s -h' for more information.\n", av[0]);
    return false;
  }
  *exit_request = handle->settings.should_exit;
  return true;
}
