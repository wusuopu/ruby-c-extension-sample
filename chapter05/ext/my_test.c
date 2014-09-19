#include "ruby.h"


VALUE cTest;

typedef struct {
    int i;
} cMyStruct;


static void t_free(void *p) {
    xfree(p);
}

static VALUE t_unit_inc(VALUE self)
{
    cMyStruct *ptr;
    Data_Get_Struct(self, cMyStruct, ptr);
    ptr->i++;
    return INT2NUM(ptr->i);
}


static VALUE t_unit(VALUE self)
{
    return rb_iv_get(self, "@unit");
}


static VALUE t_init(VALUE self, VALUE unit)
{
    rb_iv_set(self, "@unit", unit);
    return self;
}


VALUE t_new(VALUE class, VALUE unit)
{
    VALUE argv[1];
    cMyStruct *ptr = ALLOC(cMyStruct);
    VALUE tdata;

    ptr->i = NUM2INT(unit);
    tdata = Data_Wrap_Struct(class, 0, t_free, ptr);

    argv[0] = unit;
    rb_obj_call_init(tdata, 1, argv);

    return tdata;
}


static VALUE t_alloc(VALUE self, VALUE n)
{
    int *ids;
    VALUE result;
    int i, len;

    if (TYPE(n) != T_FIXNUM)
    {
        rb_raise(rb_eTypeError, "args type error");
    }

    len = NUM2INT(n);
    result = rb_ary_new();

    if (len <= 0)
    {
        return result;
    }

    ids = ALLOC_N(int, len);
    for (i = 0; i < len; i++)
    {
        ids[i] = i;
    }

    for (i = 0; i < len; i++)
    {
        rb_ary_push(result, INT2NUM(ids[i]));
    }

    xfree(ids);
    return result;
}


void Init_my_test()
{
    cTest = rb_define_class("MyStruct", rb_cObject);
    rb_define_singleton_method(cTest, "new", t_new, 1);
    rb_define_method(cTest, "initialize", t_init, 1);
    rb_define_method(cTest, "unit_inc", t_unit_inc, 0);
    rb_define_method(cTest, "unit", t_unit, 0);
    rb_define_method(cTest, "alloc", t_alloc, 1);
}
