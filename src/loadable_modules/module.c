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

#include "module.h"

/*
 * Creates and returns a loadable_module structure and fills it with 
 * the appropriate data. The user is responsible for freeing the memory
 * occupied by the loadable_module.
 * Return value: a loadable_module structure on success, and NULL otherwise
 */
loadble_module* init_loadable_module(const char *module_path)
{	
	if (module_path) {  //prevent handles to the main program
		loadable_module *module = (loadable_module*)malloc(sizeof(loadable_module));
		module->handle = dlopen(module_path, RTLD_LAZY); //lazy evaluation
	}
	
	if (!module->handle || module == NULL) {
		free(module);
		module = NULL;
	} else {
		module->init_module = dlsym(module_handle, "init_module");
	}
	return module;
}

/*
 * Load a module into memory 
 */
int load_module(loadable_module* module)
{
	
}

/*
 * unload the module from memory
 * Return value: 0 on success and -1 otherwise
 */
int unload_module(loadable_module *module)
{
	int success = -1;
	if (module->handle) {
		success = dlclose(module->handle);			
	}
	return success;
}

/*
 * terminate the module
 */
int terminate_module(loadable_module *module)
{

}
