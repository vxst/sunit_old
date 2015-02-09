Simple Unit
=========================

A thread safe, extremely simple unit test tool.

How to install
------------------------

```
cd src
make install
```

How to remove
------------------------

```
cd src
make remove
```

How to link
------------------------

cc program.c -o program -lsunit

How to use
------------------------

 * void sassert(int success, sunit\_t test\_case)

Assert a condition

 * void sassert\_equal(double a, double b, sunit\_t test\_case)

Assert double equal(relative error: 1e-8)

 * void sassert\_not\_equal(double a, double b, sunit\_t test\_case)

Assert double not equal

 * void sassert\_equal\_f(float a, float b, sunit\_t test\_case)

Assert float equal(relative error: 1e-4)

 * void sassert\_not\_equal\_f(float a, float b, sunit\_t test\_case)

Assert float not equal

 * void sinit\_std(const char\* title, sunit_t\* test\_case\_ptr)

Init a testcase: to stderr and stdout

 * void sinit(const char\* title, sunit\_t\* test\_case\_ptr, FILE\* output, FILE\* error)

Init a testcase

 * void sfinal(sunit_t\* test_case_ptr)

Print result and delete a testcase


> Copyright (C) 2015  Shan Ting <vxst@vxst.org>
> 
> This program is free software: you can redistribute it and/or modify
> it under the terms of the GNU General Public License as published by
> the Free Software Foundation, either version 3 of the License, or
> (at your option) any later version.
> 
> This program is distributed in the hope that it will be useful,
> but WITHOUT ANY WARRANTY; without even the implied warranty of
> MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
> GNU General Public License for more details.
> 
> You should have received a copy of the GNU General Public License
> along with this program.  If not, see <http://www.gnu.org/licenses/>.

