# hierarchy

`hierarchy` is an R function to generate a hierarchy, given an inputted firm size. It is based on a model first proposed by Herbert Simon (see reference below). In this model, firms are hierarchically organized with a fixed 'span of control'. This means that each superior commands the same number of subordinates, with the number of subordinates equal to the span of control. See Simon's paper for more details:

* Simon, H. A. (1957). The compensation of executives. Sociometry, 20(1), 32-35.

### Inputs

* `firm_size` = the size of the firm to be made into a hierarchy
* `span_of_control` =  the number of subordinates controlled by each superior. `span_of_control` must be greater than 1.

### Output
`hierarchy` returns a vector containing the employment in each hierarchical rank, starting at the bottom rank.

### Example:

```R
library(RcppArmadillo)
library(Rcpp)

sourceCpp("hierarchy.cpp")

# a firm with 5000 members
firm_size = 10000

# each superior controls 4 people
span_of_control = 4

# make the hierarchy
hierarchy(firm_size, span_of_control)

     [,1]
[1,] 7503
[2,] 1875
[3,]  468
[4,]  117
[5,]   29
[6,]    7
[7,]    1
```

The span of control determines the 'shape' of the hierarchy. A small span of control will make a 'tall' hierarchy (meaning it has more hierarchical ranks):

```R
# tall hierarchy
firm_size = 10000
span_of_control = 2
hierarchy(firm_size, span_of_control)

      [,1]
 [1,] 5005
 [2,] 2500
 [3,] 1250
 [4,]  625
 [5,]  312
 [6,]  156
 [7,]   78
 [8,]   39
 [9,]   19
[10,]    9
[11,]    4
[12,]    2
[13,]    1

```

A large span of control will make a 'flat' hierarchy (meaning it has fewer hierarchical ranks):


```R
# flat hierarchy
firm_size = 10000
span_of_control = 20
hierarchy(firm_size, span_of_control)

    [,1]
[1,] 9501
[2,]  475
[3,]   23
[4,]    1
```

### Installation
To use `hierarchy`, install the following R packages:
 * [Rcpp](https://cran.r-project.org/web/packages/Rcpp/index.html) 
 * [RcppArmadillo](https://cran.r-project.org/web/packages/RcppArmadillo/index.html) 

Put the source code (`hierarchy.cpp`) in the directory of your R script. Then source it with the command `sourceCpp('hierarchy.cpp')`.
















```




