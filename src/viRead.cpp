/* 
 * Copyright (C) 2012 Simon Richter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "object_cache.h"
#include "session.h"

#include <visa.h>

using namespace librevisa;

ViStatus _VI_FUNC viRead(ViSession vi, ViPBuf buf, ViUInt32 count, ViPUInt32 retCount)
{
        try
        {
                return objects.get_session(vi)->Read(buf, count, retCount);
        }
        catch(exception &e)
        {
                return e.code;
        }
}
