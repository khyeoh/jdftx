/*-------------------------------------------------------------------
Copyright 2012 Ravishankar Sundararaman

This file is part of Fluid1D.

Fluid1D is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fluid1D is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fluid1D.  If not, see <http://www.gnu.org/licenses/>.
-------------------------------------------------------------------*/

#ifndef FLUID1D_FLUID1D_FEX_H2O_FITTEDCORRELATIONS_H
#define FLUID1D_FLUID1D_FEX_H2O_FITTEDCORRELATIONS_H

#include <fluid/Fex.h>

class Fex_H2O_FittedCorrelations : public Fex
{
public:
	//! Create water with the excess functional from:
	//! J. Lischner and T. A. Arias, J. Phys. Chem. B 114, 1946 (2010).
	Fex_H2O_FittedCorrelations(FluidMixture& fluidMixture);

	const Molecule* getMolecule() const { return &molecule; }
	double get_aDiel() const;
	double compute(const ScalarFieldTilde* Ntilde, ScalarFieldTilde* grad_Ntilde) const;
	double computeUniform(const double* N, double* grad_N) const;
	void directCorrelations(const double* N, ScalarFieldTildeCollection& C) const;
private:
	SphericalKernel COO, COH, CHH, fex_gauss, siteChargeKernel;
	SiteProperties propO;
	SiteProperties propH;
	Molecule molecule;
};


#endif // FLUID1D_FLUID1D_FEX_H2O_FITTEDCORRELATIONS_H
