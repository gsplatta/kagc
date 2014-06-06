/*
 * Copyright (C) 2014  Christopher Hagler
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

#ifndef LOADABLE_MODULE_H
#define	LOADABLE_MODULE_H


#include <dlfcn.h>


typedef struct {
	void *handle;	       //handle to the shared object returned from dlopen
	void (*init_module)(); //the shared object entry point
} loadable_module;

/*
 * Creates and returns a loadable_module structure and fills it with 
 * the appropriate data. The user is responsible for freeing the memory
 * occupied by the loadable_module.
 * Return value: a loadable_module structure on success, and NULL otherwise
 */
loadble_module* init_loadable_module(const char *module_path);

/*
 * Load a module into memory 
 */
int load_module(loadable_module* module);

/*
 * unload the module from memory
 * Return value: 0 on success and -1 otherwise
 */
int unload_module(loadable_module *module);

/*
 * terminate the module
 */
int terminate_module(loadable_module *module);

#endif /* loadable_module.h */
