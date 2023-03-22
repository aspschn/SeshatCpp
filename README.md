Seshat
=========
[![Build Status](https://travis-ci.org/hardboiled65/Seshat.svg?branch=master)](https://travis-ci.org/hardboiled65/Seshat)

![logo](https://raw.githubusercontent.com/hardboiled65/Seshat/master/docs/seshat-logo.png)

A Modern C++ Unicode Library.

***This repository is no longer maintained. We have moved to Rust.***

Demo
-----
[Seshat Web Demo](https://seshat-demo.herokuapp.com)

Introduction
---------
Seshat (pronounce as Sehs-hat) is a Unicode library that written in modern C++.
It abstracts Unicode character and many of it's standard algorithms.

Installation
---------
Seshat requires below tools to build from the source.
* make
* Python 3.x
* g++ 5.4.0+ or clang 3.8.0+

For building test, requires
* wget
* unzip

And for more detail configurations,
* wget

Currently, building Seshat is supports only on Linux.
macOS is not tested and for Windows has no plan.

Below is the list of tested distros.
* Ubuntu 16.04 (xenial)

For instalation, follow next steps in the repository's root directory.
```sh
$ ./configure.py
$ make
$ sudo cp lib/libseshat.so /usr/local/lib/libseshat.so
$ sudo cp -r include/seshat /usr/local/include/
```

For building test, using
```sh
$ make test
```
after build the library.

Usage
---------
Add later.

Contribute
---------
Add later.

License
---------
All logo images are copyright [Frybits Inc.](https://github.com/frybitsinc)
and should not be used out of this project without permission.

Seshat is developed under MIT License. For the detail, see the LICENSE file.
