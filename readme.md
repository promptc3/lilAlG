# LiL Al G

## Basic Linear Algebra Library
The library you don't need and definitely don't deserve.
-----------------------------

## Build
Build shared dynamic library object
```
$ make
```

## Test
```
$ make test
```

## Test Summary

### Test Init
```
[InitZeroTest : TestLibraryInitializesZeroMatrices] PASSED

[InitOnesTest : TestLibraryInitializesOnesMatrices] PASSED

[InitIdentityTest : TestLibraryInitializesIdentityMatrices] PASSED
```

|  PASSED  |  SKIPPED  |  FAILED  |
|----------|-----------|----------|
|  3       |  0        |  0       |

### Test Operator
```
[Add : AddTwoMatrices] PASSED

[Subtract : SubtractTwoMatrices] PASSED

[Multiply : MultiplyElementWiseTwoMatrices] PASSED

[Matrix_Multiply : MultiplyTwoMatrices] PASSED

[Matrix_Divsion : DivideElementWiseTwoMatrices] PASSED

[InitZeroTest : TestLibraryInitializesZeroMatrices] PASSED

[InitOnesTest : TestLibraryInitializesOnesMatrices] PASSED

[InitIdentityTest : TestLibraryInitializesIdentityMatrices] PASSED
```

|  PASSED  |  SKIPPED  |  FAILED  |
|----------|-----------|----------|
|    8     |  0        |  0       |

## License
Basic Linear Algebra Library
Copyright © 2019 promptc3

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
