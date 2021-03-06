# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#' @title  A random number generator using Rcpp
#' @description A random number generator using Rcpp
#' @param sigma the standard deviation of normal distribution
#' @param N the number of samples
#' @param x0 the initial value
#' @return a chain of random numbers
#' @examples
#' \dontrun{
#' CMetropolis(0.05,25,5000)
#' }
#' @export
CMetropolis <- function(sigma = 0.05, x0 = 25, N = 5000L) {
    .Call('_StatComp20005_CMetropolis', PACKAGE = 'StatComp20005', sigma, x0, N)
}

