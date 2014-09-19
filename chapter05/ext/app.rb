#!/usr/bin/env ruby
#-*- coding:utf-8 -*-

require "./my_test.so"

t = MyStruct.new 12

puts "unit: #{t.unit}"
puts "unit_inc: #{t.unit_inc}"
puts t.alloc 5
