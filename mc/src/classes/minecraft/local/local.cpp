#include "local.h"

#include "../minecraft.h"

jobject Local::objectPlayer(){
    jobject minecraft = Minecraft::GetMinecraft();
    jfieldID thePlayer = jni_mc->env->GetFieldID(jni_mc->env->GetObjectClass(minecraft), "s", "Ldzm;");
	jobject localPlayer = jni_mc->env->GetObjectField(minecraft, thePlayer);
	jni_mc->env->DeleteLocalRef(minecraft);
	return localPlayer;
}

void Local::SetSprint(bool sprint){
    jclass playerEntity = jni_mc->FindClass("dzm");

	jmethodID sprintMethode = jni_mc->env->GetMethodID(playerEntity, "g", "(Z)V");
    jobject entity = this->objectPlayer();
	jni_mc->env->CallVoidMethod(entity, sprintMethode, sprint);
	jni_mc->env->DeleteLocalRef(playerEntity);
    jni_mc->env->DeleteLocalRef(entity);
}
Vector3 Local::GetStaticPosition(){
    Entity player = this->objectPlayer();

    Vector3 lastPos = player.LastTickPosition();
    Vector3 pos = player.Position();

    float part = Minecraft::render.RenderPartialTicks();
    
    Vector3 static_pos = {
        lastPos.x + (pos.x - lastPos.x) * part,
		lastPos.y + (pos.y - lastPos.y) * part,
		lastPos.z + (pos.z - lastPos.z) * part
    };

    jni_mc->env->DeleteLocalRef(player.GetMemory());
    return static_pos;
}

void Local::SetRotationYaw(float yaw){
    jclass classEntity = jni_mc->FindClass("aqa");
	jfieldID rotationYawFild = jni_mc->env->GetFieldID(classEntity, "p", "F");

	jobject localPlayer = this->objectPlayer();
	jni_mc->env->SetFloatField(localPlayer, rotationYawFild, yaw);
    jni_mc->env->DeleteLocalRef(localPlayer);
    jni_mc->env->DeleteLocalRef(classEntity);

}

void Local::SetRotationPitch(float pitch){
    jclass classEntity = jni_mc->FindClass("aqa");
	jfieldID rotationPitchFild = jni_mc->env->GetFieldID(classEntity, "q", "F");

	jobject localPlayer = this->objectPlayer();
	jni_mc->env->SetFloatField(localPlayer, rotationPitchFild, pitch);
    jni_mc->env->DeleteLocalRef(localPlayer);
    jni_mc->env->DeleteLocalRef(classEntity);
}

