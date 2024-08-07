/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:52:52 by martiper          #+#    #+#             */
/*   Updated: 2024/08/07 11:29:47 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <sys/time.h>
#include <stddef.h>

#include <arpa/inet.h>

uint64_t get_timestamp(void) {
  struct timeval tv;
  if (gettimeofday(&tv, NULL) == -1)
    return 0;
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

bool is_ipv4(const char* ip) {
  struct in_addr addr;
  return inet_pton(AF_INET, ip, &addr) > 0;
}

bool is_ipv6(const char* ip) {
  struct in6_addr addr;
  return inet_pton(AF_INET6, ip, &addr) > 0;
}

bool is_valid_ip(const char* ip) {
  return is_ipv4(ip) || is_ipv6(ip);
}
