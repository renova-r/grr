# grr 0.9.9002

Platform compatibility patch to Renova release 0.9.9001, which is based on CRAN grr 0.9 (archived on CRAN 2025-12-10).

- `src/grr.cpp`: defines `R_NO_REMAP`, includes the C++ standard headers before the R headers, and uses `Rf_allocVector` / `Rf_error`. Rinternals.h's `#define length(x) Rf_length(x)` collided with `std::codecvt::length` in libc++'s `<locale>` and broke compilation with libc++ toolchains (macOS, Windows ARM64, WebAssembly). No behaviour change.
- No R code, `NAMESPACE`, help page or other source file changed.
- `DESCRIPTION`: `Version` set to `0.9.9002`. `README.md` and `NEWS.md` updated.

# grr 0.9.9001

Renova release, based on CRAN grr 0.9 (archived on CRAN 2025-12-10).

- `src/init.c` (new): `R_init_grr` registers `sortcpp`, `ordercpp` and `matches` and disables dynamic symbol lookup.
- `src/grr.cpp`: string sorting now copies the elements to a `std::vector<SEXP>`, sorts it and writes it back with `SET_STRING_ELT`; ordering and matching read strings through `STRING_PTR_RO` (`const SEXP*`) instead of the writable `STRING_PTR`.
- `man/matches.Rd`: `{indexes=FALSE}` became `\code{indexes=FALSE}`.
- `DESCRIPTION`: `Depends: R (>= 3.0.0)` became `R (>= 3.5.0)` (needed for `STRING_PTR_RO`); `Author: Craig Varrichio <email>` became `Author: Craig Varrichio [aut, cre]` with an equivalent `Authors@R` entry (metadata only).
- `DESCRIPTION`: `Version` set to `0.9.9001`; "Compatibility updates by Renova." appended to `Description`.
- The stale `MD5` file was removed.
- `COPYING` (GNU GPL text) was added; the `License` field is unchanged.
- `README.md` was added and `.Rbuildignore` keeps `README.md` and `NEWS.md` out of the built package.
