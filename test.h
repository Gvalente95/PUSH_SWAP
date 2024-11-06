/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:44:58 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/05 21:31:09 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#ifndef TEST_H
# define TEST_H
extern int 		debug;
extern int 		tests;
extern int 		instructions_given;
extern int		arr_len;

#define	TESTS_AMOUNT 20

extern char 	*func_name;
extern char 	*function_names[];

#endif