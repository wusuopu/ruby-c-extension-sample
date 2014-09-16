#!/usr/bin/env ruby
#-*- coding:utf-8 -*-

#require "./my_test.rb"
require "./my_test.so"
require "test/unit"

class TestTest < Test::Unit::TestCase
  def test_test
    t = MyTest::MyTest.new
    assert_equal(Object, MyTest::MyTest.superclass)
    assert_equal(MyTest::MyTest, t.class)
  end
end
