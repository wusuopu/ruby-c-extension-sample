
python:
	swig -python example.i
	gcc -c example.c example_wrap.c -I/usr/include/python2.7
	ld -shared example.o example_wrap.o -o _example.so

ruby:
	swig -ruby example.i
	gcc -c example.c example_wrap.c -I/usr/include/ruby-2.1.0/ -I/usr/include/ruby-2.1.0/i686-linux
	ld -shared example.o example_wrap.o -o example.so

clean:
	rm -rfv example.o example.py example.pyc example_wrap.c example_wrap.o __pycache__ _example.so example.so
