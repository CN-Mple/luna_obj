/* luna_obj.h */
#ifndef LUNA_OBJ_H
#define LUNA_OBJ_H

#include "luna_rq.h"
#include "luna_ev.h"
#include "luna_fsm.h"

struct core_obj {
	struct core_fsm super;
	struct rq mailbox;
};

#endif

#define LUNA_OBJ_IMPLEMENTATION
#ifdef LUNA_OBJ_IMPLEMENTATION

void luna_obj_init(struct core_obj *obj)
{
	LUNA_ASSERT(obj);
}

void luna_obj_ev_post(struct core_obj *obj, struct core_ev *ev)
{
	LUNA_ASSERT(obj);
	LUNA_ASSERT(ev);
	luna_ev_ref(ev);
	luna_rq_push(&obj->mailbox, (uint8_t *)&ev);
}

#endif
