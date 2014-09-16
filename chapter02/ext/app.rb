#!/usr/bin/env ruby
#-*- coding:utf-8 -*-

require "./my_test.so"

t = MyTest::MyTest.new

t.fun1
t.fun2 1
t.fun3 1, 2


t.fun4
t.fun4 2
t.fun5 1, 2, 3
