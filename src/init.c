#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>

extern SEXP sortcpp(SEXP x);
extern SEXP ordercpp(SEXP x);
extern SEXP matches(SEXP a, SEXP b);

static const R_CallMethodDef CallEntries[] = {
    {"sortcpp",  (DL_FUNC) &sortcpp,  1},
    {"ordercpp", (DL_FUNC) &ordercpp, 1},
    {"matches",  (DL_FUNC) &matches,  2},
    {NULL, NULL, 0}
};

void attribute_visible R_init_grr(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
