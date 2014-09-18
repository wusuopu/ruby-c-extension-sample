#!/usr/bin/env ruby
#-*- coding:utf-8 -*-

require 'mkmf'

RbConfig::MAKEFILE_CONFIG['CC'] = ENV['CC'] if ENV['CC']

extension_name = 'my_test'

unless pkg_config('glib-2.0')
    raise "'glib-2.0' not found"
end

have_func('some_function', 'library/lib.h')
have_type('some_type', 'library/lib.h')

create_header
create_makefile(extension_name)
