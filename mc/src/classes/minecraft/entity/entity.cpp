#include "entity.h"
#include "../minecraft.h"


void Entity::SetGlowing(bool esp){
    jclass classEntity = jni_mc->FindClass("aqa");
	jmethodID methode = jni_mc->env->GetMethodID(classEntity, "i", "(Z)V");

	jni_mc->env->CallVoidMethod(this->__memory, methode, esp);
	jni_mc->env->DeleteLocalRef(classEntity);
}

Vector3 Entity::Position(){
	jclass classEntity = jni_mc->FindClass("aqa");
	jmethodID methode_x = jni_mc->env->GetMethodID(classEntity, "cD", "()D");
	jmethodID methode_y = jni_mc->env->GetMethodID(classEntity, "cE", "()D");
	jmethodID methode_z = jni_mc->env->GetMethodID(classEntity, "cH", "()D");

	Vector3 position = {
		jni_mc->env->CallDoubleMethod(this->__memory,methode_x),
		jni_mc->env->CallDoubleMethod(this->__memory,methode_y),
		jni_mc->env->CallDoubleMethod(this->__memory,methode_z),

	};
	jni_mc->env->DeleteLocalRef(classEntity);
	
	return position;
}

Vector3 Entity::LastTickPosition(){
	jclass classEntity = jni_mc->FindClass("aqa");

	jfieldID lastTickPosX = jni_mc->env->GetFieldID(classEntity, "D", "D");
	jfieldID lastTickPosY = jni_mc->env->GetFieldID(classEntity, "E", "D");
	jfieldID lastTickPosZ = jni_mc->env->GetFieldID(classEntity, "F", "D");

	Vector3 postLast = {
		jni_mc->env->GetDoubleField(this->__memory, lastTickPosX),
		jni_mc->env->GetDoubleField(this->__memory, lastTickPosY),
		jni_mc->env->GetDoubleField(this->__memory, lastTickPosZ)
	};

	jni_mc->env->DeleteLocalRef(classEntity);
	return postLast;
}
void Entity::SetBoundingBox(jobject allib){
	jclass classEntity = jni_mc->FindClass("aqa");
	jmethodID methode =  jni_mc->env->GetMethodID(classEntity, "a", "(Ldci;)V");

	jni_mc->env->CallVoidMethod(this->__memory, methode, allib);
	jni_mc->env->DeleteLocalRef(classEntity);
}

jobject Entity::AxisAlignedBB(double x, double y, double z, double x1, double y1, double z1){
	jclass aligenClass = jni_mc->FindClass("dci");

	jmethodID methode = jni_mc->env->GetMethodID(aligenClass, "<init>", "(DDDDDD)V");
	jobject aliganObject = jni_mc->env->NewObject(aligenClass, methode, x, y, z, x1, y1, z1);
	jni_mc->env->DeleteLocalRef(aligenClass);
	return aliganObject;
}

jobject Entity::GetBoundingBox() {
	jclass classEntity = jni_mc->FindClass("aqa");
	jmethodID methode =  jni_mc->env->GetMethodID(classEntity, "cc", "()Ldci;");

	jni_mc->env->DeleteLocalRef(classEntity);
	return jni_mc->env->CallObjectMethod(this->__memory, methode);
}

double Entity::MaxY(){
	jclass alig = jni_mc->FindClass("dci");
	jfieldID filed = jni_mc->env->GetFieldID(alig, "e", "D");


	jobject box = this->GetBoundingBox();
	double min = jni_mc->env->GetDoubleField(this->GetBoundingBox(), filed);

	jni_mc->env->DeleteLocalRef(box);
	jni_mc->env->DeleteLocalRef(alig);
	return min;
}
double Entity::MinY(){
	jclass alig = jni_mc->FindClass("dci");
	jfieldID filed = jni_mc->env->GetFieldID(alig, "b", "D");

	
	jobject box = this->GetBoundingBox();
	double min = jni_mc->env->GetDoubleField(this->GetBoundingBox(), filed);
	jni_mc->env->DeleteLocalRef(box);
	jni_mc->env->DeleteLocalRef(alig);
	return min;
}
int Entity::GetID(){
	jclass classEntity = jni_mc->FindClass("aqa");
	jmethodID methode =  jni_mc->env->GetMethodID(classEntity, "Y", "()I");
	jni_mc->env->DeleteLocalRef(classEntity);
	return  jni_mc->env->CallIntMethod(this->__memory, methode);
}

bool Entity::IsLocalPlayer(){
	jobject objectPlayer = Minecraft::local.objectPlayer();
	Entity player = objectPlayer;

	bool isLocalPlayer = (player.GetID() == this->GetID());
	jni_mc->env->DeleteLocalRef(objectPlayer);
	return isLocalPlayer;
}

double Entity::Distance(jobject entity){
	Entity m_entity = entity;

	Vector3 m_entity_pos = m_entity.Position();
	Vector3 l_entity_pos = this->Position();

	Vector3 cord = { 
		(float)(l_entity_pos.x - m_entity_pos.x),
		(float)(l_entity_pos.y - m_entity_pos.y),
		(float)(l_entity_pos.z - m_entity_pos.z)
	};
	return sqrt((cord.x* cord.x + cord.y * cord.y + cord.z * cord.z));
}

double Entity::GetEyeHeight(){
	jclass classEntity =  jni_mc->FindClass("aqa");
	jmethodID methodetEyeHeight = jni_mc->env->GetMethodID(classEntity, "ce", "()F");
	jni_mc->env->DeleteLocalRef(classEntity);
	return jni_mc->env->CallFloatMethod(this->GetMemory(), methodetEyeHeight);
}

const char* Entity::GetName(){
	jclass playerEntity = jni_mc->FindClass("bfw");

	jmethodID getNameMethode = jni_mc->env->GetMethodID(playerEntity, "bU", "()Ljava/lang/String;");
	jni_mc->env->DeleteLocalRef(playerEntity);
	jobject met = jni_mc->env->CallObjectMethod(this->GetMemory(), getNameMethode);

	const char* string = jni_mc->env->GetStringUTFChars((jstring)met, NULL);
	jni_mc->env->DeleteLocalRef(met);
	jni_mc->env->DeleteLocalRef(playerEntity);
	jni_mc->env->ReleaseStringUTFChars((jstring)met ,string);
	return string;
}

float Entity::GetHealth(){
	jclass LivingEntity = jni_mc->FindClass("aqm");
	jmethodID healthMethod = jni_mc->env->GetMethodID(LivingEntity, "dk", "()F");
	jni_mc->env->DeleteLocalRef(LivingEntity);
	return jni_mc->env->CallFloatMethod(this->GetMemory(), healthMethod);
}