//
//  camera.c
//  C-Ray
//
//  Created by Valtteri Koskivuori on 02/03/15.
//  Copyright (c) 2015 Valtteri Koskivuori. All rights reserved.
//

#include "includes.h"
#include "camera.h"

#include "filehandler.h"
#include "renderer.h"
#include "scene.h"
#include "transforms.h"

void computeFocalLength(struct renderer *renderer) {
	//Focal length is calculated based on the camera FOV value
	if (renderer->scene->camera->FOV > 0.0 && renderer->scene->camera->FOV < 189.0) {
		renderer->scene->camera->focalLength = 0.5 * renderer->image->size.width / toRadians(0.5 * renderer->scene->camera->FOV);
	}
}

void initCamera(struct camera *cam) {
	cam->pos = vectorWithPos(0, 0, 0);
	cam->up = vectorWithPos(0, 1, 0);
	cam->left = vectorWithPos(-1, 0, 0);
}
