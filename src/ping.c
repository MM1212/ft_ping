/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:50:57 by martiper          #+#    #+#             */
/*   Updated: 2024/08/07 11:37:40 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"
#include <utils.h>
#include <sys/time.h>

static bool setup(t_ping* data) {
  data->pid = getpid();
  if (data->settings.ip_version == IPV4)
    data->sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  else
    data->sock = socket(AF_INET6, SOCK_RAW, IPPROTO_ICMPV6);
  if (data->sock < 0) {
    perror("socket");
    data->exit_code = EXIT_FAILURE;
    return false;
  }
  // set sock timeout
  if (data->settings.timeout > 0) {
    struct timeval tv;
    tv.tv_sec = data->settings.timeout / 1000;
    tv.tv_usec = (data->settings.timeout % 1000) * 1000;
    if (setsockopt(data->sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
      perror("setsockopt");
      data->exit_code = EXIT_FAILURE;
      return false;
    }
  }
  if (data->settings.ip_version == IPV4)
    data->destination.addr.sin_family = AF_INET;
  else
    data->destination.addr.sin_family = AF_INET6;
  data->destination.addr.sin_port = htons(0);
  if (inet_aton(data->destination.ip, &data->destination.addr.sin_addr) == 0) {
    perror("inet_aton");
    data->exit_code = 2;
    return false;
  }
  return true;
}

static bool ping(t_ping* data) {
}

bool start_ping(t_ping* data) {

  uint64_t last_ping = 0;
  bool ok = true;
  data->sequence = 0;
  while (data->settings.count == 0 || data->sequence < data->settings.count) {
    last_ping = get_timestamp();
    if (!ping(data))
      ok = false;
  }
  return ok;
}
