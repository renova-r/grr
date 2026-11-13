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
