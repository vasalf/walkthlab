#ifndef ONEWAY_LIST_DECL_H_
#define ONEWAY_LIST_DECL_H_

/* This provides one-way linked list of any type (usage is a bit like C++ 
 * template). To use it for specific type (for example, T), just add the 
 * following to oneway_list.h:
 * 
 * ONEWAY_LIST_DECL(T)
 *
 * and the following to oneway_list.c:
 *
 * ONEWAY_LIST_DEF(T)
 *
 * Then the struct name will be oneway_T_list.
*/

#define ONEWAY_LIST_ITER_STRUCT_DECL(TYPE) \
struct __oneway_##TYPE##_list_iter; \
struct __oneway_##TYPE##_list_iter \
{ \
    TYPE val; \
    struct __oneway_##TYPE##_list_iter* next; \
}; \
typedef struct __oneway_##TYPE##_list_iter oneway_##TYPE##_list_iter;

#define ONEWAY_LIST_STRUCT_DECL(TYPE) \
typedef struct \
{ \
    oneway_##TYPE##_list_iter* begin; \
    oneway_##TYPE##_list_iter* end; \
} oneway_##TYPE##_list;

#define ONEWAY_LIST_FUNC_DECL(TYPE) \
oneway_##TYPE##_list init_oneway_##TYPE##_list(); \
void oneway_##TYPE##_list_push(oneway_##TYPE##_list* l, TYPE val); \
void oneway_##TYPE##_list_erase(oneway_##TYPE##_list* l, oneway_##TYPE##_list_iter* it); \
oneway_##TYPE##_list_iter* oneway_##TYPE##_list_find(oneway_##TYPE##_list* l, TYPE val); \
void oneway_##TYPE##_list_free(oneway_##TYPE##_list* l);

#define ONEWAY_LIST_DECL(TYPE) \
ONEWAY_LIST_ITER_STRUCT_DECL(TYPE) \
ONEWAY_LIST_STRUCT_DECL(TYPE) \
ONEWAY_LIST_FUNC_DECL(TYPE)

#define INIT_ONEWAY_LIST_DEF(TYPE) \
oneway_##TYPE##_list init_oneway_##TYPE##_list() \
{\
    oneway_##TYPE##_list res;\
    res.begin = NULL; \
    res.end = NULL; \
    return res; \
}

#define ONEWAY_LIST_PUSH_DEF(TYPE) \
void oneway_##TYPE##_list_push(oneway_##TYPE##_list* l, TYPE val) \
{\
    oneway_##TYPE##_list_iter* iter = malloc(sizeof(oneway_##TYPE##_list_iter)); \
    iter->val = val; \
    iter->next = NULL; \
    if (l->begin == NULL) \
        l->begin = iter; \
    else if (l->end == NULL) \
        l->end = iter; \
    else \
    {\
        l->end->next = iter; \
        l->end = iter; \
    } \
}

#define ONEWAY_LIST_ERASE_DEF(TYPE) \
void oneway_##TYPE##_list_erase(oneway_##TYPE##_list* l, oneway_##TYPE##_list_iter* it) \
{ \
    if (l->begin == it) \
    { \
        oneway_##TYPE##_list_iter* jt = l->begin; \
        l->begin = l->begin->next; \
        free(jt); \
    } \
    else \
    { \
        oneway_##TYPE##_list_iter* jt; \
        for (jt = l->begin; jt->next != it; jt = jt->next); \
        jt->next = it->next; \
        free(it); \
    } \
}

#define ONEWAY_LIST_FIND_DEF(TYPE) \
oneway_##TYPE##_list_iter* oneway_##TYPE##_list_find(oneway_##TYPE##_list* l, TYPE val) \
{ \
    oneway_##TYPE##_list_iter* it; \
    for (it = l->begin; it != NULL && it->val != val; it = it->next); \
    return it; \
}

#define ONEWAY_LIST_FREE_DEF(TYPE) \
void oneway_##TYPE##_list_free(oneway_##TYPE##_list* l) \
{ \
    for (oneway_##TYPE##_list_iter* it = l->begin; it != NULL; ) \
    { \
        oneway_##TYPE##_list_iter* jt = it->next;\
        free(it); \
        it = jt; \
    } \
}

#define ONEWAY_LIST_DEF(TYPE) \
INIT_ONEWAY_LIST_DEF(TYPE) \
ONEWAY_LIST_PUSH_DEF(TYPE) \
ONEWAY_LIST_ERASE_DEF(TYPE) \
ONEWAY_LIST_FIND_DEF(TYPE) \
ONEWAY_LIST_FREE_DEF(TYPE)

#endif //ONEWAY_LIST_DECL_H_
