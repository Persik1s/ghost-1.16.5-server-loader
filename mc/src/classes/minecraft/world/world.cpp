#include "world.h"
#include "../minecraft.h"

jobject World::theObject(){
    jclass classMine = jni_mc->FindClass("djz");
	jfieldID clientWorld = jni_mc->env->GetFieldID(classMine, "r", "Ldwt;");

	jobject minecraft = Minecraft::GetMinecraft();
	jobject world = jni_mc->env->GetObjectField(minecraft, clientWorld);

	jni_mc->env->DeleteLocalRef(minecraft);
    jni_mc->env->DeleteLocalRef(classMine);
	return world;
}

std::vector<Entity> World::playerEntities(){
    std::vector<Entity> entities;
	jclass worldClass = jni_mc->FindClass("dwt");


	jmethodID getPlayers = jni_mc->env->GetMethodID(worldClass, "x", "()Ljava/util/List;");

	jclass listClass = jni_mc->env->FindClass("java/util/List");
	jmethodID toArray = jni_mc->env->GetMethodID(listClass, "toArray", "()[Ljava/lang/Object;");

	jobject world = this->theObject();
	jobject array = jni_mc->env->CallObjectMethod(world, getPlayers);
	jobjectArray entityList = reinterpret_cast<jobjectArray>(jni_mc->env->CallObjectMethod(array, toArray));


	jsize size = jni_mc->env->GetArrayLength(entityList);

	entities.reserve(size);
	for (int i = 0; i < size; i++) {
		jobject obj =jni_mc->env->GetObjectArrayElement(entityList, i);
		entities.push_back(jni_mc->env->NewGlobalRef(obj)); 
		jni_mc->env->DeleteLocalRef(obj);
	}


	jni_mc->env->DeleteLocalRef(world);
	jni_mc->env->DeleteLocalRef(array);
	jni_mc->env->DeleteLocalRef(worldClass);
	jni_mc->env->DeleteLocalRef(listClass);
	jni_mc->env->DeleteLocalRef(entityList);
    
    return entities;
}

void World::SetWorldTime(int time){
	jclass world = jni_mc->FindClass("dwt");

	jmethodID methodeSet = jni_mc->env->GetMethodID(world, "b", "(J)V");

	jni_mc->env->DeleteLocalRef(world);

	jobject worldObject = this->theObject();
	jni_mc->env->CallVoidMethod(worldObject, methodeSet, time);
	jni_mc->env->DeleteLocalRef(worldObject);
}