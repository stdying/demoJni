#include <jni.h>
#include<iostream>
#include"com_stdying_jni_JniCallJava.h"
using namespace std;

/*
 * Class:     com_stdying_jni_JniCallJava
 * Method:    nativeSetName
 * Signature: (Ljava/lang/String;)V
 */
 /*在native中访问类非静态变量*/
JNIEXPORT void JNICALL Java_com_stdying_jni_JniCallJava_nativeSetName
   (JNIEnv *env, jobject obj, jstring str)
  {
	  /*1--获取类*/
	  jclass cls = env->GetObjectClass(obj);
	  /*2--获取字段或域的ID*/
	  jfieldID nameFId = env->GetFieldID(cls,"name","Ljava/lang/String;");
	  if(nameFId == NULL)
	  {
			cout<<"JNI--获取name句柄ID为NULL\n";
	  }

	  /*3--获取字段或域值*/
	  jstring jStr = (jstring)env->GetObjectField(obj,nameFId);
	  /*转换成char *类型*/
	  const char *c_str = env->GetStringUTFChars(jStr,NULL);
	  string str_name = c_str;
	  cout<<"JNI--The name From java :"<<str_name<<endl;

	  /*释放局部引用*/
	  env->ReleaseStringUTFChars(jStr,c_str);

	  /*4--设置该字段的值*/
	  env->SetObjectField(obj,nameFId,str);
  }
/*
 * Class:     com_stdying_jni_JniCallJava
 * Method:    doCall
 * Signature: ()V
 */
 /*在native中调用类的非静态方法*/
JNIEXPORT void JNICALL Java_com_stdying_jni_JniCallJava_doCall
 (JNIEnv *env, jobject obj)
  {
    /*1--获得java类*/
    jclass cls = env->GetObjectClass(obj);
    /*2--获得方法id*/
    jmethodID callBackId =env->GetMethodID(cls,"jniCall","(Ljava/lang/String;)V");
    
    
    if(callBackId == NULL)
    {
        cout<<"JNI--获取方法句柄失败"<<endl;
    }
    jstring jstr = env->NewStringUTF("In Native");
   
    /*3--回调java方法，并传入参数*/
    env->CallVoidMethod(obj,callBackId,jstr);
    
    /*删除本地引用*/
    env->DeleteLocalRef(cls);
    env->DeleteLocalRef(jstr);
 }

/*
 * Class:     com_stdying_jni_JniCallJava
 * Method:    doCallStatic
 * Signature: ()V
 */
 /*在native中调用类的静态方法*/
JNIEXPORT void JNICALL Java_com_stdying_jni_JniCallJava_doCallStatic
  (JNIEnv *env, jobject obj)
  {
    /*调用静态方法和非静态方法有相似地方*/
    /*1--获得java类*/
    jclass cls = env->FindClass("com/stdying/jni/JniCallJava");
    if(cls == NULL)
    {
        cout<<"cls 为空\n";
    }
    cout<<"开始调用\n";
    //jclass cls = env->GetObjectClass(obj);
    /*2--获取方法ID*/
    jmethodID id_method = env->GetStaticMethodID(cls,"jniCallStatic","(Ljava/lang/String;)V");
    if(id_method == NULL)
    {
        cout<<"id_method 为空\n";
    }
    jstring jstr = env->NewStringUTF("In Native static");
    /*3--回调java静态方法*/
    env->CallStaticVoidMethod(cls,id_method,jstr);
    
    /*删除本地引用*/
    env->DeleteLocalRef(cls);
    env->DeleteLocalRef(jstr);
    cout<<"调用完毕";
  }
