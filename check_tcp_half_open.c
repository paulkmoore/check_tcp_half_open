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

/* GNU Libraries */
#include <getopt.h>

const char *progname = "check_tcp_half_open";
const char *copyright = "2018";
const char *email = "paul@hypermedia.technology";







void print_help(void){
	print_revision(progname, NP_VERSION);

	printf ("Copyright (c) 2006 Sean Finney\n");
	printf (COPYRIGHT, copyright, email);

	printf ("%s\n", _("This plugin checks the selected ntp server"));

	printf ("\n\n");

	print_usage();
	printf (UT_HELP_VRSN);
	printf (UT_EXTRA_OPTS);
	printf (UT_HOST_PORT, 'p', "123");
	printf (UT_IPv46);
	printf (" %s\n", "-w, --warning=THRESHOLD");
	printf ("    %s\n", _("Offset to result in warning status (seconds)"));
	printf (" %s\n", "-c, --critical=THRESHOLD");
	printf ("    %s\n", _("Offset to result in critical status (seconds)"));
	printf (" %s\n", "-j, --jwarn=THRESHOLD");
	printf ("    %s\n", _("Warning threshold for jitter"));
	printf (" %s\n", "-k, --jcrit=THRESHOLD");
	printf ("    %s\n", _("Critical threshold for jitter"));
	printf (UT_CONN_TIMEOUT, DEFAULT_SOCKET_TIMEOUT);
	printf (UT_VERBOSE);

	printf("\n");
	printf("%s\n", _("Notes:"));
	printf(UT_THRESHOLDS_NOTES);

	printf("\n");
	printf("%s\n", _("Examples:"));
	printf(" %s\n", _("Normal offset check:"));
	printf("  %s\n", ("./check_ntp -H ntpserv -w 0.5 -c 1"));
	printf("\n");
	printf(" %s\n", _("Check jitter too, avoiding critical notifications if jitter isn't available"));
	printf(" %s\n", _("(See Notes above for more details on thresholds formats):"));
	printf("  %s\n", ("./check_ntp -H ntpserv -w 0.5 -c 1 -j -1:100 -k -1:200"));

	printf (UT_SUPPORT);

	printf ("%s\n", _("WARNING: check_ntp is deprecated. Please use check_ntp_peer or"));
	printf ("%s\n\n", _("check_ntp_time instead."));
}

void
print_usage(void)
{
	printf ("%s\n", _("WARNING: check_ntp is deprecated. Please use check_ntp_peer or"));
	printf ("%s\n\n", _("check_ntp_time instead."));
	printf ("%s\n", _("Usage:"));
	printf(" %s -H <host> [-w <warn>] [-c <crit>] [-j <warn>] [-k <crit>] [-4|-6] [-v verbose]\n", progname);
}



