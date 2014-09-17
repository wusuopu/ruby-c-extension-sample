#include "ruby.h"

static VALUE mTest;
static VALUE cTest;


static VALUE t_check(VALUE self, VALUE obj)
{
    printf("Type: %d\tClass: %s\n",
           TYPE(obj), rb_obj_classname(obj));
    return obj;
}

static VALUE t_number(VALUE self, VALUE n)
{
    VALUE res;
    if (TYPE(n) != T_FIXNUM)
    {
        rb_raise(rb_eTypeError, "args type error");
    }
    printf("args: %d\n", NUM2INT(n));
    res = INT2NUM(12345);
    return res;
}

static VALUE t_string(VALUE self, VALUE n)
{
    VALUE res;
    if (TYPE(n) != T_STRING)
    {
        rb_raise(rb_eTypeError, "args type error");
    }
    printf("args: %s\n", StringValueCStr(n));
    res = rb_str_new_cstr("abcdef");
    return res;
}

static VALUE t_array(VALUE self, VALUE n)
{
    VALUE res;
    if (TYPE(n) != T_ARRAY)
    {
        rb_raise(rb_eTypeError, "args type error");
    }
    rb_io_puts(1, &n, rb_stdout);
    res = rb_ary_new();
    rb_ary_push(res, rb_str_new_cstr("test"));
    rb_ary_store(res, 3, INT2NUM(10));
    return res;
}

int do_print(VALUE key, VALUE val, VALUE in) {
    fprintf(stderr, "Input data is %s\n", StringValueCStr(in));
    fprintf(stderr, "Key %s=>Value %s\n", StringValueCStr(key), StringValueCStr(val));

    return ST_CONTINUE;
}

static VALUE t_hash(VALUE self, VALUE n)
{
    VALUE res;
    if (TYPE(n) != T_HASH)
    {
        rb_raise(rb_eTypeError, "args type error");
    }

    rb_hash_foreach(n, do_print, rb_str_new2("passthrough"));
    res = rb_hash_new();
    rb_hash_aset(res, rb_str_new_cstr("k1"), INT2NUM(5));
    return res;
}

static VALUE t_block(VALUE self)
{
    VALUE res;
    if (!rb_block_given_p()) 
    {
        rb_raise(rb_eArgError, "Expected block");
    }
    res = rb_yield(rb_str_new2("hello"));
    rb_io_puts(1, &res, rb_stdout);
    return Qnil;
}

void Init_my_test()
{
    mTest = rb_define_module("MyTest");
    cTest = rb_define_class_under(mTest, "MyTest", rb_cObject);
    Check_Type(cTest, T_CLASS);

    rb_define_method(cTest, "check", t_check, 1);
    rb_define_method(cTest, "number_test", t_number, 1);
    rb_define_method(cTest, "string_test", t_string, 1);
    rb_define_method(cTest, "array_test", t_array, 1);
    rb_define_method(cTest, "hash_test", t_hash, 1);
    rb_define_method(cTest, "block_test", t_block, 0);
}
