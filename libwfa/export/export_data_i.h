#ifndef LIBWFA_EXPORT_DATA_I_H
#define LIBWFA_EXPORT_DATA_I_H

#include <libwfa/core/ab_matrix.h>
#include <libwfa/core/ab_vector.h>
#include <libwfa/core/ab_selector.h>
#include <libwfa/core/density_type.h>
#include <libwfa/core/orbital_type.h>

namespace libwfa {

/** \brief Interface for exporting density and orbital data.

    Interface to implement the export of density and orbital data.

    \ingroup libwfa
 **/
class export_data_i {
public:
    /** \brief Destructor
     **/
    virtual ~export_data_i() { }

    /** \brief Export the density matrix
        \param type Type of density matrix
        \param dm Density matrix
     **/
    virtual void perform(density_type type, const ab_matrix &dm) = 0;

    /** \brief Write the given orbital coefficients to the file.
        \param type Orbital type
        \param coeff Orbital coefficients
        \param ev Orbital eigenvalues
        \param s Selector of specific orbital coefficients

        The orbital coefficient vectors can be expected as columns of the
        coefficient matrix.
     **/
    virtual void perform(orbital_type type, const ab_matrix &coeff,
            const ab_vector &ev, const ab_selector &s) = 0;
};

} // namespace libwfa

#endif // LIBWFA_EXPORT_DATA_I_H