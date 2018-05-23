/*****************************************************************************
*
* Nagios check_tcp_half_open plugin
*
* License: GPL
* Copyright (c) 2018 Paul K Moore <paulkmoore@gmail.com>
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
const char *email = "paulkmoore@gmail.com";

static int verbose_flag;		/* Flag set by ‘--verbose’ */

int main (int argc, char **argv) {
    int c;
    int sockfd; // socket descriptor
    struct sockaddr_in servaddr;
    
    openlog(progname, LOG_PID, LOG_USER);   // Prepare connection to syslog; do not log to STDERR per Nagios guidelines
    
    syslog(LOG_INFO, "Test only");  // Test logging
  
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
    
    
    /* Get a socket */
    if ( (sockfd = socket (AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0 ) {
        //socket creation failed, may be because of non-root privileges
        perror("Failed to create socket");
        exit(1);     
    }
    
    /* setup the server address */
    bzero(&servaddr, sizeof(servaddr));  /* initialise */
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);      /* TODO - get from program argument */
    if (inet_pton(AF_INET, "192.168.1.1", &servaddr.sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(1);  /* TODO - better error handling */
    }
    
    
    
    //Datagram to represent the packet
    //char datagram[4096] , source_ip[32] , *data , *pseudogram;
     
    //zero out the packet buffer
    //memset (datagram, 0, 4096);
     
    //IP header
    //struct iphdr *iph = (struct iphdr *) datagram;
     
    //TCP header
    //struct tcphdr *tcph = (struct tcphdr *) (datagram + sizeof (struct ip));
    //struct sockaddr_in sin;
    //struct pseudo_header psh;

    
    
    syslog(LOG_INFO, "Testing connection to %s:%d", "test", 8080);
    
    
    closelog();     // Cleanup connection to syslog
    
    return 0;
    
}








