/*****************************************************************************
*
* Nagios check_tcp_half_open include file
*
* License: GPL
* Copyright (c) 2018 Paul K Moore <paul@hypermedia.technology>
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