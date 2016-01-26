// ---------------------------------------------------------------------
//
// Copyright (C) 2003 - 2015 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------



// Just output the constraint matrices of the FE_Q element. Test
// introduced when we started to compute them on the fly, rather than
// precomputing them for a number of elements and storing them in a
// table

#include "../tests.h"
#include <deal.II/base/logstream.h>
#include <deal.II/fe/fe_q.h>

#include <fstream>
#include <string>

#define PRECISION 2



template<int dim>
void
test(const unsigned int degree)
{
  deallog << "FE_Q<" << dim << "> (" << degree << ")"
          << std::endl;

  FE_Q<dim> fe_q(degree);
  FE_Q<dim> x(fe_q);
}


int
main()
{
  std::ofstream logfile ("output");
  deallog << std::setprecision(PRECISION);
  deallog << std::fixed;
  deallog.attach(logfile);
  deallog.threshold_double(1.e-10);

  // no constraints in 1d, but we had
  // the matrices precomputed up to
  // Q4 for 2d and Q2 for 3d
  for (unsigned int degree=1; degree<=4; ++degree)
    test<2>(degree);

  for (unsigned int degree=1; degree<=2; ++degree)
    test<3>(degree);

  return 0;
}



