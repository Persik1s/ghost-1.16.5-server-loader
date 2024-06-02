#include "render.h"
#include "../minecraft.h"
#include "../../../utils/Math.h"

jobject Render::objectTimer(){
    jclass mcClass = jni_mc->FindClass("djz");
	jfieldID filedTimer = jni_mc->env->GetFieldID(mcClass, "P", "Ldkk;");

	jobject minecraft = Minecraft::GetMinecraft();
	jobject timerObject =  jni_mc->env->GetObjectField(minecraft, filedTimer);

	jni_mc->env->DeleteLocalRef(mcClass);
	jni_mc->env->DeleteLocalRef(minecraft);
	return timerObject;
}

float Render::RenderPartialTicks(){
    jclass timerClass = jni_mc->FindClass("dkk");
	jfieldID partFiled = jni_mc->env->GetFieldID(timerClass, "a", "F");

	jobject timerObejct = this->objectTimer();
	float part = jni_mc->env->GetFloatField(timerObejct, partFiled);
	jni_mc->env->DeleteLocalRef(timerClass);
	return part;
}

double* Render::ProjectionMatrix(){
	GLdouble projectionMatrix[16];
	glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
	return projectionMatrix;
}

double* Render::ModelViewMatrix(){
	GLdouble modelView[16];
	glGetDoublev(GL_MODELVIEW_MATRIX, modelView);
	return modelView;
}

Vector4 Multiply(Vector4 vec,Matrix matrix){
	return Vector4(
		vec.x * matrix.m00 + vec.y * matrix.m10 + vec.z * matrix.m20 + vec.w * matrix.m30,
		vec.x * matrix.m01 + vec.y * matrix.m11 + vec.z * matrix.m21 + vec.w * matrix.m31,
		vec.x * matrix.m02 + vec.y * matrix.m12 + vec.z * matrix.m22 + vec.w * matrix.m32,
		vec.x * matrix.m03 + vec.y * matrix.m13 + vec.z * matrix.m23 + vec.w * matrix.m33
	);
}
Vector2 Render::WorldToScrean(Vector3 position,Matrix matrix,Vector2 size_window){
	Vector4 mul = Multiply( {position.x,position.y,position.z,1.0},matrix);
	Vector3 ndc = {
		mul.x / mul.w,
		mul.y / mul.w,
		mul.z / mul.w 
	};
	
	if (ndc.z > 1 && ndc.z < 1.15) {
		return Vector2{
			((ndc.x + 1.0f) / 2.0f) * size_window.x,
			((1.0f - ndc.y) / 2.0f) * size_window.y,
		};
	}
	return {0,0};
}

// void Render::DrawBox(Matrix matrix,Vector3 position,Vector3 entity_pos){
// 	glPushAttrib(GL_ALL_ATTRIB_BITS);
//     glPushMatrix();

//     glEnable(GL_LINE_SMOOTH);

//     glEnable(GL_BLEND);
//     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

// 	glMatrixMode(GL_PROJECTION);
//     glLoadMatrixf(matrix.projection);

//     glMatrixMode(GL_MODELVIEW);
//     glLoadMatrixf(matrix.modelView);

// 	glColor4f(1, 1, 1, 1);
// 	//esp
// 	float distance = glm::distance(glm::vec3(position.x,position.y,position.z),glm::vec3(entity_pos.x,entity_pos.y,entity_pos.z));
// 	glm::vec3 pos = glm::vec3(entity_pos.x,entity_pos.y,entity_pos.z) - glm::vec3(position.x,position.y,position.z);

// 	glPushMatrix();

//     glLineWidth(2.0 / (distance / 50 + 1));
//     glTranslatef(pos.x, pos.y, pos.z);
//     glScalef(1, 2, 1);

// 	glRotatef(-Direction(entity_pos.x,entity_pos.y,position.x,position.y) + 90, 0, 1, 0);

//     glBegin(GL_LINES);

//         // Horizonte bottom
//     glVertex3f(0.5f, 0.0f, 0.0f);
//     glVertex3f(-0.5f, 0.0f, 0.0f);

//         // Horizonte top
//     glVertex3f(0.5f, 1.0f, 0.0f);
//     glVertex3f(-0.5f, 1.0f, 0.0f);

//         // Vertical
//     glVertex3f(0.5f, 0.0f, 0.0f);
//     glVertex3f(0.5f, 1.0f, 0.0f);

//     glVertex3f(-0.5f, 0.0f, 0.0f);
//     glVertex3f(-0.5f, 1.0f, 0.0f);

//     glEnd();

// 	glPopMatrix();


// 	glPopMatrix();
//     glPopAttrib();
// }