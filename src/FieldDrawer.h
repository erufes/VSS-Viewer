/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef FIELD_DRAWER_H
#define FIELD_DRAWER_H

#include "Material.h"

class FieldDrawer {
public:

	Material material;

	FieldDrawer();
	void draw();
};

#endif // FIELD_DRAWER_H
