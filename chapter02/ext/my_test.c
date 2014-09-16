#include "ruby.h"

static VALUE mTest;
static VALUE cTest;

static VALUE t_fun1(VALUE self)
{
    printf("\nIt does not need arguments.\n");
    return self;
}

static VALUE t_fun2(VALUE self, VALUE arg1)
{
    printf("\nIt need 1 argument.\n");
    rb_io_puts(1, &arg1, rb_stdout);
    return self;
}

static VALUE t_fun3(VALUE self, VALUE arg1, VALUE arg2)
{
    printf("\nIt need 2 arguments.\n");
    rb_io_puts(1, &arg1, rb_stdout);
    rb_io_puts(1, &arg2, rb_stdout);
    return self;
}

static VALUE t_fun4(int argc, VALUE *argv, VALUE self)
{
    VALUE arg;
    printf("\nIt need -1 arguments.\n");
    rb_scan_args(argc, argv, "01", &arg);
    rb_io_puts(1, &arg, rb_stdout);
    return self;
}

static VALUE t_fun5(VALUE self, VALUE arg)
{
    printf("\nIt need -2 arguments.\n");
    rb_io_puts(1, &arg, rb_stdout);
    return self;
}

void Init_my_test()
{
    mTest = rb_define_module("MyTest");
    cTest = rb_define_class_under(mTest, "MyTest", rb_cObject);
    rb_define_method(cTest, "fun1", t_fun1, 0);
    rb_define_method(cTest, "fun2", t_fun2, 1);
    rb_define_method(cTest, "fun3", t_fun3, 2);
    rb_define_method(cTest, "fun4", t_fun4, -1);
    rb_define_method(cTest, "fun5", t_fun5, -2);
}
