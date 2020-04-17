#ifndef UTILS_H_
#define UTILS_H_
extern void error(const char *msg);
extern void debug(const char *msg);
extern char *itoa2(int val, char *str, int base2);
extern void __checkfail(int x, const char *msg, const char *filename, int linenum);
#ifdef NDEBUG
#define _check(x, msg) \
	{                  \
		((void)(x));   \
		((void)(msg)); \
	}
#else
#define _check(x, msg) __checkfail(x, msg, __FILE__, __LINE__)
#endif
#define check(x) _check(x, "assert() failed")
#endif
