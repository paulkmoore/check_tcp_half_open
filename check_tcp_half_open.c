/*****************************************************************************
*
* Nagios check_tcp_half_open plugin
*
* License: GPL
* Copyright (c) 2018 Paul K Moore <paul@hypermedia.technology>
*
* Description:
*
* This file contains the check_tcp_half_open plugin
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

#include "check_tcp_half_open.h"

const char *progname = "check_tcp_half_open";
const char *copyright = "2018";
const char *email = "paul@hypermedia.technology";

static int verbose_flag;		/* Flag set by ‘--verbose’ */

int main (int argc, char **argv) {
  int c;

  while (1) {
      static struct option long_options[] = {
          /* These options set a flag. */
          {"verbose", no_argument,       &verbose_flag, 1},
          {"brief",   no_argument,       &verbose_flag, 0},
          /* These options don’t set a flag.
             We distinguish them by their indices. */
          {"host",    required_argument, 0, 'h'},
          {"port",    required_argument, 0, 'p'},
          {0, 0, 0, 0}
        };
        
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "h:p:",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c)
        {
        case 0:
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        /*case 'b':
          puts ("option -b\n");
          break;*/

        case 'h':
          printf ("option -h with value `%s'\n", optarg);
          break;

        case 'p':
          printf ("option -p with value `%s'\n", optarg);
          break;

        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }
}








