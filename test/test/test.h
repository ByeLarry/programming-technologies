// test.h

#ifndef MYDLL_H
#define MYDLL_H

#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

extern "C" {
    MYDLL_API int AddNumbers(int a, int b);
}

#endif
