/*****************************************************************************
*
* Nagios check_tcp_half_open include file
*
* License: GPL
* Copyright (c) 2018 Paul K Moore paulkmoore@gmail.com>
*
* Description:
*
* This file contains common include files and defines used in the 
* the check_tcp_half_open plugin
*
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* $Id$
*
*****************************************************************************/

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>    /* memset */
#include <arpa/inet.h>  /* inet_pton */
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netdb.h>
 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

/* GNU Libraries */
#include <getopt.h>
#include <syslog.h>


/* Macros */
/* http://pubs.opengroup.org/onlinepubs/009696799/functions/bzero.html */
#ifndef bzero
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)
#endif


// helpers
typedef struct ip_header_t {
    unsigned char ihl:4,
    version:4;
    unsigned char tos;
    unsigned short tot_len;
    unsigned short id;
    unsigned short frag_off;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short check;
    unsigned int saddr;
    unsigned int daddr;
} * ip_header_t;

typedef struct tcp_header_t {
    unsigned short source;
    unsigned short dest;
    unsigned int seq;
    unsigned int ack_seq;
    unsigned short res1:4,
    doff:4,
    fin:1,
    syn:1,
    rst:1,
    psh:1,
    ack:1,
    urg:1,
    ece:1,
    cwr:1;
    unsigned short window;
    unsigned short check;
    unsigned short urg_ptr;
} * tcp_header_t;



enum {
	OK = 0,
	ERROR = -1
};

/* AIX seems to have this defined somewhere else */
#ifndef FALSE
enum {
	FALSE,
	TRUE
};
#endif


enum {
	STATE_OK,
	STATE_WARNING,
	STATE_CRITICAL,
	STATE_UNKNOWN,
	STATE_DEPENDENT
};

enum {
	DEFAULT_SOCKET_TIMEOUT = 10,	 /* timeout after 10 seconds */
	MAX_INPUT_BUFFER = 8192,	     /* max size of most buffers we use */
	MAX_HOST_ADDRESS_LENGTH = 256	 /* max size of a host address */
};