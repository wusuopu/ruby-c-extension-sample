#!/usr/bin/env ruby
#-*- coding:utf-8 -*-

module MyTest
  class Error < StandardError
  end

  def self.exception_example
    puts("raise custom exception")
    raise Error, "Custom Error"
    return nil;
  end

  def self.rescue_test args
    begin
      if args.class != Fixnum
        raise(TypeError, "args type error")
      end
      return args
    rescue Exception => err
      puts("in rescue %s %s" % [ args.class, err.class ]);
      return nil;
    end
  end

  def self.ensure_test args
    begin
      if args.class != Fixnum
        raise(TypeError, "args type error")
      end
      return args
    ensure
      puts("in ensure %s" % args.class);
      return nil;
    end
  end

  def self.throw_catch
    if !block_given?
      raise StandardError, "Expected a block"
    end

    catch(:catchpoint) {
      puts("in catch_cb")
      res = yield "val"
      if res.class != Fixnum
          puts("in throw_catch_test")
          throw(:catchpoint, nil)
      end
    }
  end
end
