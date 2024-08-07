/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:52:18 by martiper          #+#    #+#             */
/*   Updated: 2024/08/07 11:29:08 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <stdbool.h>

uint64_t get_timestamp(void);
bool is_ipv4(const char* ip);
bool is_ipv6(const char* ip);
bool is_valid_ip(const char* ip);
