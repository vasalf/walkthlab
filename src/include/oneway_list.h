#ifndef ONEWAY_LIST_H_
#define ONEWAY_LIST_H_

#include <stddef.h>
#include <stdlib.h>

#include <oneway_list_decl.h>
#include <gl_objects/gl_object.h>

typedef gl_object* gl_object_ptr;

ONEWAY_LIST_DECL(int);
ONEWAY_LIST_DECL(gl_object_ptr);

#endif //ONEWAY_LIST_H_
