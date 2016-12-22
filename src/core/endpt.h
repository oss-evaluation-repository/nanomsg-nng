//
// Copyright 2016 Garrett D'Amore <garrett@damore.org>
//
// This software is supplied under the terms of the MIT License, a
// copy of which should be located in the distribution where this
// file was obtained (LICENSE.txt).  A copy of the license may also be
// found online at https://opensource.org/licenses/MIT.
//

#ifndef CORE_ENDPT_H
#define CORE_ENDPT_H

#include "core/transport.h"

// NB: This structure is supplied here for use by the CORE. Use of this library
// OUSIDE of the core is STRICTLY VERBOTEN.  NO DIRECT ACCESS BY PROTOCOLS OR
// TRANSPORTS.
struct nng_endpt {
	struct nni_endpt_ops	ep_ops;
	void *			ep_tran;
	nni_list_node_t		ep_sock_node;
	nni_socket *		ep_sock;
	const char *		ep_addr;
	nni_thread_t		ep_dialer;
	nni_thread_t		ep_listener;
	int			ep_close;
	nni_mutex		ep_mx;
	nni_cond		ep_cv;
};

int nni_endpt_create(nni_endpt **, nni_socket *, const char *);
void nni_endpt_destroy(nni_endpt *);
int nni_endpt_dial(nni_endpt *, nni_pipe **);
int nni_endpt_listen(nni_endpt *);
int nni_endpt_accept(nni_endpt *, nni_pipe **);
int nni_endpt_close(nni_endpt *);

#endif // CORE_ENDPT_H
