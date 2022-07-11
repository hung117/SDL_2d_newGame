### pragma once error

You get the warning because you are compiling a file that contains #pragma once. #pragma once is only intended to be used in headers, and there is no need to compile headers; hence the warning. Solution: Don't compile headers.
