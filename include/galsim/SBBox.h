/* -*- c++ -*-
 * Copyright 2012-2014 The GalSim developers:
 * https://github.com/GalSim-developers
 *
 * This file is part of GalSim: The modular galaxy image simulation toolkit.
 *
 * GalSim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GalSim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GalSim.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef SBBOX_H
#define SBBOX_H
/** 
 * @file SBBox.h @brief SBProfile of a 2-d tophat profile.
 */

#include "SBProfile.h"

namespace galsim {

    /** 
     * @brief Surface Brightness Profile for the Boxcar function.
     *
     * The boxcar function is a rectangular box.  Convolution with a Boxcar function of dimensions
     * `width` x `height` and sampling at pixel centres is equivalent to pixelation (i.e. Surface
     * Brightness integration) across rectangular pixels of the same dimensions.  This class is
     * therefore useful for pixelating SBProfiles.
     */ 
    class SBBox : public SBProfile 
    {
    public:
        /** 
         * @brief Constructor.
         *
         * @param[in] width    width of Boxcar function along x.
         * @param[in] height   height of Boxcar function along y.
         * @param[in] flux     flux.
         * @param[in] gsparams GSParams object storing constants that control the accuracy of image
         *                     operations and rendering, if different from the default.
         */
        SBBox(double width, double height, double flux, const GSParamsPtr& gsparams);

        /// @brief Copy constructor.
        SBBox(const SBBox& rhs);

        /// @brief Destructor.
        ~SBBox();

        /// @brief Returns the x dimension width of the Boxcar.
        double getWidth() const;

        /// @brief Returns the y dimension width of the Boxcar.
        double getHeight() const;

    protected:

        class SBBoxImpl;

    private:
        // op= is undefined
        void operator=(const SBBox& rhs);
    };
}

#endif // SBBOX_H

