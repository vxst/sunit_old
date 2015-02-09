# Copyright (C) 2015  Shan Ting <vxst@vxst.org>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

all: libsunit.a
libsunit.a: sunit.o
	ar cr libsunit.a sunit.o
sunit.o: sunit.c
	cc -fPIC -O3 -Wall -std=c89 -c  -o sunit.o sunit.c
install:libsunit.a
	cp libsunit.* /usr/local/lib/
	cp sunit.h /usr/local/include/
remove:
	rm -rf /usr/local/lib/libsunit.a
	rm -rf /usr/local/include/sunit.h
clean:
	rm -rf sunit.o libsunit.a
