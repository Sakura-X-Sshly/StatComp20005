#include <Rcpp.h>

using namespace Rcpp;
//' @title  A random number generator using Rcpp
//' @description A random number generator using Rcpp
//' @param sigma the standard deviation of normal distribution
//' @param N the number of samples
//' @param x0 the initial value
//' @return a chain of random numbers
//' @examples
//' \dontrun{
//' CMetropolis(0.05,25,5000)
//' }
//' @export
//[[Rcpp::export]]
NumericMatrix CMetropolis(double sigma=0.05,double x0=25,int N=5000) {
  NumericMatrix mat(N, 2);
  mat(0,0)=x0;mat(0,1)=0;int k=0;
  for (int i=1; i<N;i++) {
    double z = runif(1,0,1)[0];
    double y = rnorm(1,mat(i-1, 0),sigma)[0];
    if (z < exp(-abs(y))/exp(-abs(mat(i-1, 0)))) mat(i, 0) = y ;
    else { mat(i, 0) = mat(i-1, 0);++k;}
    mat(i, 1) = k;
  }
  return(mat);
}