#include <RcppArmadillo.h>

using namespace std;

// hierarchy is a function for creating a hierarchy
// given the hierarchy's size (firm_size) and the span of control
// hierarchy returns a vector contain employment by hierarchical rank

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

arma::vec hierarchy(const double &firm_size, const double &span_of_control){

    if (span_of_control <= 1) {
        throw std::range_error("span of control (span) must be greater than 1");
    }

    // number of hierarchical levels in firm
    double n_levels = floor( log(firm_size*(span_of_control-1)+1)/log(span_of_control) );

    // hierarchical employment vector
    // (leave exta elements at end of vector for possible overshoot
    arma::vec h = arma::zeros<arma::vec>( n_levels + 2);

    // get size of bottom rank
    double base =  ceil( firm_size*( 1 - 1/span_of_control )/( 1 - std::pow(1/span_of_control, n_levels) ) );

    // correct to allow firm size of 1
    if( h[0] < 1 ){ h[0] = 1 ;}

    int i = 0;
    while( h[i] != 0 ){

        i++;
        h[i] =  floor( base / std::pow(span_of_control, i) );

    }

    int max_rank = i;


    // check for employment over/undershoot
    int check = arma::sum(h) - firm_size;

    // if h[0] - check <= 0 subtract overshoot from top levels
    // otherwise add/subtract to bottom level
    if( h[0] - check <= 0 ) {
        while (check > 0){
            h[max_rank - 1] = h[max_rank - 1] - 1;
            check =  check -1;
            if(h[max_rank - 1] == 0 ){ max_rank = max_rank - 1; }
        }
    }
    else {
        h[0] = h[0] - check;
    }

    return h.subvec(0, max_rank - 1);

}
