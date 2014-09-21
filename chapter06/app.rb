#!/usr/bin/env ruby
#-*- coding:utf-8 -*-

require './example.so'

puts Example.fact(5)
puts Example.my_mod(7, 3)
puts Example.get_time()
