/*
 * lispd_log.h
 *
 * This file is part of LISP Mobile Node Implementation.
 * Write log messages
 *
 * Copyright (C) 2011 Cisco Systems, Inc, 2011. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * Please send any bug reports or fixes you make to the email address(es):
 *    LISP-MN developers <devel@lispmob.org>
 *
 * Written or modified by:
 *    David Meyer       <dmm@cisco.com>
 *    Preethi Natarajan <prenatar@cisco.com>
 *    Alberto Rodriguez Natal <arnatal@ac.upc.edu>
 *
 */
#pragma once

#ifndef LISPD_LOG_H_
#define LISPD_LOG_H_


// If these set of defines is modified, check the function is_loggable()

#define LISP_LOG_CRIT        1       /* critical conditions -> Exit program */
#define LISP_LOG_ERR         2       /* error conditions -> Not exit but should be considered by user */
#define LISP_LOG_WARNING     3       /* warning conditions -> Low level errors. Program doesn't finish */
#define LISP_LOG_INFO        4       /* informational -> Initial configuration, SMRs, interface change status*/
#define LISP_LOG_DEBUG_1     5       /* low debug-level messages -> Control message */
#define LISP_LOG_DEBUG_2     6       /* medium debug-level messages -> Errors in received packets. Wrong AFI, ...  */
#define LISP_LOG_DEBUG_3     7       /* high debug-level messages -> Log for each received or generated packet */


#define LOG_FILE_NAME	"lispd.log"


//void lispd_log_msg(int lisp_log_level, const char *format, ...);



#define lispd_log_msg(...) LLOG(__VA_ARGS__)

void lispd_log_msg1(int lisp_log_level, const char *format, ...);

#define LLOG(level__, ...)              \
    do {                                \
        if (is_loggable(level__)) {     \
            lispd_log_msg1(level__, __VA_ARGS__); \
        }                               \
    } while (0)

void llog(int lisp_log_level, const char *format, ...);



void open_log_file(char *log_file);
void close_log_file();

/*
 * True if log_level is enough to print results
 */

int is_loggable (int log_level);


#endif /*LISPD_LOG_H_*/
