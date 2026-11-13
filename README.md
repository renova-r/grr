# grr

Faster alternative implementations of some base R functions: sort, order and match (sort2, order2, matches).

Compatibility updates by Renova.

Version 0.9.9002 is a platform compatibility patch: `src/grr.cpp` defines `R_NO_REMAP`, includes the C++ standard headers before the R headers and uses explicit `Rf_` API names, so the package compiles with libc++ toolchains (macOS, Windows ARM64, WebAssembly). Behaviour is unchanged.

Version 0.9.9001 registers the package's three native `.Call` routines, changes the C++ string sorting and matching to use R's read-only string accessors (`STRING_PTR_RO`, and `SET_STRING_ELT` for writing sorted strings) instead of writable `STRING_PTR`, raises the minimum R version to 3.5.0, fixes one Rd line, and adds an `Authors@R` entry equivalent to the existing author and maintainer.

## Install

```r
install.packages("grr", repos = c(
  Renova = "https://renova-r.r-universe.dev",
  CRAN = "https://cloud.r-project.org"
))
```

Or install this exact release from its tag:

```r
install.packages("remotes")
remotes::install_github("renova-r/grr@renova-0.9.9002")
```

[Release notes](NEWS.md) · [Renova package directory](https://github.com/renova-r/revival-catalog)

grr is by Craig Varrichio (maintainer); the original CRAN package is at <https://CRAN.R-project.org/package=grr>. License: GPL-3; see [COPYING](COPYING).
