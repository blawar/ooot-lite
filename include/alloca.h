#ifndef ALLOCA_H
#define ALLOCA_H

#if !defined(OS_DESKTOP)
#define alloca  _alloca
#else
#define alloca(x)  __builtin_alloca(x)
#endif

#endif
