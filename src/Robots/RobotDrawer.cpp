/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "RobotDrawer.h"
#include "iostream"

RobotDrawer::RobotDrawer(){
	qobj = gluNewQuadric();
	gluQuadricNormals( qobj, GLU_SMOOTH );
	pose = new Pose();
	teamColor = ColorName::Yellow;
	robotColor = ColorName::Red;

	robotWidth = 8.0;
	robotDepth = 8.0;
	robotHeight = 8.0;
}

void RobotDrawer::setPose( Pose *pose ){
	this->pose = pose;
}

void RobotDrawer::setTeamColor( ColorName teamColor ){
	this->teamColor = teamColor;
}

void RobotDrawer::setRobotColor( ColorName robotColor ){
	this->robotColor = robotColor;
}

void RobotDrawer::draw(){
	glPushMatrix();
	//! Desenha o corpo do robô
	glTranslatef( thickOfThings * 1.4, pose->x, pose->y );
	glRotatef( -pose->yaw, 1, 0, 0 );
	glScalef( robotWidth, robotDepth, robotHeight );
	material->applyMaterial( ColorName::Black3 );
	glutSolidCube( 1 );

	//! Desenha a etiqueta do time. Azul ou Amarelo
	glPushMatrix();
	glTranslatef( 0.5, -0.2, -0.2 );
	glScalef( 0.1f, colorLabelSize / robotWidth, colorLabelSize / robotWidth );
	material->applyMaterial( teamColor );
	glutSolidCube( 1 );
	glPopMatrix();

	//! Desenha a segunda etiqueta do robô
	glPushMatrix();
	glTranslatef( 0.5, 0.2, 0.2 );
	glScalef( 0.1f, colorLabelSize / robotWidth, colorLabelSize / robotWidth );
	material->applyMaterial( robotColor );
	glutSolidCube( 1 );
	glPopMatrix();

	//! Desenha as rodas de um robô
	glPushMatrix();
	glRotatef( 90.0, 1, 0, 0 );
	glTranslatef( -0.10, 0.0, -0.61 );
	material->applyMaterial( ColorName::White );
	gluCylinder( qobj, 0.2f, 0.2f, 1.2f, 16.0, 16.0 ); // Radius 1, Radius 2, Lenght, Precision1, Precision2
	glPopMatrix();

	glPopMatrix();
}
