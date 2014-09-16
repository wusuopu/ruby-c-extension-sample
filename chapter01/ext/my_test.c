#include "ruby.h"

static VALUE mTest;
static VALUE cTest;

static VALUE t_init(VALUE self)
{
    printf("\nCreate a MyTest instance.\n");

    return self;
}

void Init_my_test()
{
    mTest = rb_define_module("MyTest");
    cTest = rb_define_class_under(mTest, "MyTest", rb_cObject);
    rb_define_method(cTest, "initialize", t_init, 0);
}
