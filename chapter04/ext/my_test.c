#include "ruby.h"

static VALUE mTest;
static VALUE eTest;

static VALUE exception_example(VALUE klass)
{
    printf("raise custom exception\n");
    rb_raise(eTest, "Custom Error");
    return Qnil;
}

static VALUE rescue_cb(VALUE args, VALUE err)
{
    printf("in rescue %s %s\n", rb_obj_classname(args), rb_obj_classname(err));
    return Qnil;
}

static VALUE cb(VALUE args)
{
    if (TYPE(args) != T_FIXNUM)
    {
        printf("type args: %d\n", TYPE(args));
        rb_raise(rb_eTypeError, "args type error");
    }
    return args;
}

static VALUE rescue_test(VALUE klass, VALUE args)
{
    return rb_rescue(cb, args, rescue_cb, args);
}

static VALUE ensure_cb(VALUE args)
{
    printf("in ensure %s\n", rb_obj_classname(args));
    return Qnil;
}

static VALUE ensure_test(VALUE klass, VALUE args)
{
    return rb_ensure(cb, args, ensure_cb, args);
}

// throw/catch
static VALUE catch_cb(VALUE val, VALUE args, VALUE self)
{
    VALUE res;
    printf("in catch_cb\n");
    res = rb_yield(args);

    if (TYPE(res) != T_FIXNUM)
    {
        printf("in throw_catch_test\n");
        rb_throw("catchpoint", Qnil);
    }
    return res;
}

static VALUE throw_catch_test(VALUE klass)
{
    VALUE res;
    if (!rb_block_given_p())
    {
        rb_raise(rb_eStandardError, "Expected a block");
    }

    res = rb_catch("catchpoint", catch_cb, rb_str_new2("val"));

    return res;
}

void Init_my_test()
{
    mTest = rb_define_module("MyTest");
    eTest = rb_define_class_under(mTest, "Error", rb_eStandardError);
    rb_define_module_function(mTest, "exception_example", exception_example, 0);
    rb_define_module_function(mTest, "rescue_test", rescue_test, 1);
    rb_define_module_function(mTest, "ensure_test", ensure_test, 1);
    rb_define_module_function(mTest, "throw_catch", throw_catch_test, 0);
}
