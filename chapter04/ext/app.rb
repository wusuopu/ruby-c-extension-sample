#!/usr/bin/env ruby
#-*- coding:utf-8 -*-

require "./my_test.so"
#require "./my_test.rb"

# MyTest.exception_example    # 抛出 MyTest::Error 异常

p MyTest.rescue_test 1.1
p "-------------"

p MyTest.ensure_test 1
p "-------------"

MyTest.throw_catch do |a|
  puts "in yield #{a}"
  1.2
end
