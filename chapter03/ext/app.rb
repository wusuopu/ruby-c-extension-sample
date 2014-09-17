#!/usr/bin/env ruby
#-*- coding:utf-8 -*-

require "./my_test.so"

a = MyTest::MyTest.new

p a.check 1
p "-" * 10
p a.number_test 4
p a.string_test "qwer"
p "-" * 10
p a.array_test [1, 2, 3]
p "-" * 10
p a.hash_test({"a"=> "1", "b"=> "2"})
p "-" * 10
p a.block_test {|x| puts "yeild #{x}"; "done"}
