SPEC = Gem::Specification.new do |s|
    s.name = "example"
    s.version = "1.0"
    s.date = '2014-09-21'
    s.summary = "C bindings"
    s.description = "C Bindings"
    s.authors = ["Long Changjin"]
    s.email = ["admin@longchangjin.cn"]
    s.files = ["Rakefile", "COPYING", "NEWS", "README.rdoc", "ext/my_test.c", "ext/app.rb", "ext/extconf.rb"]
    s.homepage = "http://www.xefan.com/"
    s.required_ruby_version = '>= 2.1.0'
    s.extensions = "ext/extconf.rb"
end
