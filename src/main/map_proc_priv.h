/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software Foundation,
 *  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef _FR_MAP_PROC_PRIV_H
#define _FR_MAP_PROC_PRIV_H
/**
 * $Id$
 *
 * @file main/map_proc_priv.h
 * @brief Private map process structures and functions.
 *
 * @author Arran Cudbard-Bell <a.cudbardb@freeradius.org>
 */
#include <freeradius-devel/cf_util.h> /* Need CONF_* definitions */
#include <freeradius-devel/map_proc.h>
#include <freeradius-devel/modpriv.h>
#include <freeradius-devel/map_proc.h>
#include <freeradius-devel/rad_assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Map processor registration
 */
struct map_proc {
	void			*mod_inst;		//!< Module instance.
	char			name[FR_MAX_STRING_LEN];	//!< Name of the map function.
	int			length;			//!< Length of name.

	map_proc_func_t		evaluate;		//!< Module's map processor function.
	map_proc_instantiate_t	instantiate;		//!< Callback to create new instance struct.
	size_t			inst_size;		//!< Size of map_proc instance data to allocate.
};

/** Map processor instance
 */
struct map_proc_inst {
	map_proc_t const	*proc;			//!< Map processor.
	vp_tmpl_t const		*src;			//!< Evaluated to provide source value for map processor.
	vp_map_t const		*maps;			//!< Head of the map list.
	void			*data;			//!< Instance data created by #map_proc_instantiate
};

#ifdef __cplusplus
}
#endif
#endif
