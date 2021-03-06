/*******************************************************************************
*                                                                              *
*     Author:      A. Vrchoticky                                               *
*                  Technische Universitaet Wien                                *
*                  Institut fuer Technische Informatik E182/1                  *
*                  Treitlstrasse 3                                             *
*                  1040 Wien                                                   *
*                  Tel.: (0222) 58801 / 8168                                   *
*                  E-Mail: alex@vmars.tuwien.ac.at                             *
*     File:        seqev.c						       *
*     Version:     4.12							       *
*     Date:        9/7/94						       *
*                                                                              *
*******************************************************************************/

#ifndef lint
static char	seqev_c_sccsID[] = "@(#)seqev.c	4.12	9/7/94";
#endif /* lint */

#include <stdlib.h>
#include <stddef.h>

#include "seqev.h"

sequencer_t *create_sequencer (key_t key)
{
	sequencer_t *s;

	if ((s = malloc (sizeof (sequencer_t))) == NULL)
	{
		return NULL;
	}

	if (initSequencer (key, s) == -1)
	{
		return NULL;
	}

	return s;
}

long sticket (sequencer_t *sequencer)
{
	return Sticket (*sequencer);
}

int rm_sequencer (sequencer_t *sequencer)
{
	int status;

	status =  rmSequencer (*sequencer);

	free ((void *)sequencer);

	return status;
}


eventcounter_t *create_eventcounter (key_t key)
{
	eventcounter_t *e;

	if ((e = malloc (sizeof (eventcounter_t))) == NULL)
	{
		return NULL;
	}

	if (initEventcounter (key, e) == -1)
	{
		return NULL;
	}

	return e;
}

int eawait (eventcounter_t *eventcounter, long value)
{
	return Eawait (*eventcounter, value);
}

long eread (eventcounter_t *eventcounter)
{
	return Eread (*eventcounter);
}

int eadvance (eventcounter_t *eventcounter)
{
	return Eadvance (*eventcounter);
}

int rm_eventcounter (eventcounter_t *eventcounter)
{
	int status;

	status =  rmEventcounter (*eventcounter);

	free ((void *)eventcounter);

	return status;
}

